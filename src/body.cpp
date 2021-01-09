//
// Created by nicol on 02/01/2021.
//

#include "../include/multibody/body.h"

multibody::Body::Body(const std::string &name, double mass, const multibody::Vector3D &p0,
                      const multibody::Vector3D &v0,
                      const multibody::Vector3D &value) : Loggable(0) {
    init(name, mass, p0, v0, value);
}

multibody::Body::Body(const std::string &name, double mass, int lenLog, const Vector3D &p0, const Vector3D &v0,
                      const Vector3D &value) : Loggable(lenLog) {
    init(name, mass, p0, v0, value);
}


void multibody::Body::transferTo(multibody::Body *Dest, const multibody::Vector3D &netForce) {
    Dest->valueCurrentForce_ -= netForce;
    valueCurrentForce_ += netForce;
}

void multibody::Body::computeCinematic(double dt, bool enableG) {
    if (firstIter_) {
        speed_ = v0_;
        position_ = p0_;
        firstIter_ = false;
    }

    acceleration_ = valueCurrentForce_ / mass_;

    if(enableG)
        acceleration_ += Vector3D(0.0, 0.0, -9.81);

    //logger della forza netta corrente sul corpo i-esimo
    logValue(acceleration_ * mass_);

    speed_ = acceleration_ * dt + speed_;

    position_ = acceleration_ * dt * dt * 0.5 + speed_ * dt + position_;

    //reset ValueCurrentForce così che allo stepo dopo non sommo le forze risultanti con quelle dei passi precedenti
    valueCurrentForce_ = Vector3D(0.0, 0.0, 0.0);
}

std::string multibody::Body::printInfoBody() const {
    std::stringstream stream;
    stream << "{" << name_ << ", " << position_.toStringVector3D() << ", " <<
           speed_.toStringVector3D() << ", " << acceleration_.toStringVector3D()
           << ", " << valueCurrentForce_.toStringVector3D() << "}";
    return stream.str();//.c_str();
}

void multibody::Body::init(const std::string &name, double mass, const multibody::Vector3D &p0,
                           const multibody::Vector3D &v0, const multibody::Vector3D &value) {
    assert(mass > 0);
    mass_ = mass;
    name_ = name;
    p0_ = p0;
    v0_ = v0;
    valueCurrentForce_ = value;
    firstIter_ = true;
}

multibody::Body::Body(multibody::Body &otherBody) : Loggable(otherBody){
    name_ = otherBody.name_;
    mass_ = otherBody.mass_;

    p0_ = otherBody.p0_;
    v0_ = otherBody.v0_;
    position_ = otherBody.position_;
    speed_ = otherBody.speed_;
    acceleration_ = otherBody.acceleration_;
    valueCurrentForce_ = otherBody.valueCurrentForce_;

}




