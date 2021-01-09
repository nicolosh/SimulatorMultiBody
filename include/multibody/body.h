//
// Created by nicol on 02/01/2021.
//

#ifndef MULTIBODYSIMULATOR_BODY_H
#define MULTIBODYSIMULATOR_BODY_H

#include <string>
#include <cassert>
#include "multibody/vector3D.h"
#include "multibody/loggable.h"

namespace multibody {

    class Body : public Loggable {
    protected:
        double mass_;
        Vector3D p0_, v0_;
        std::string name_;
        Vector3D acceleration_, speed_, position_;
        Vector3D valueCurrentForce_;
        bool firstIter_;

        void init(const std::string &name, double mass, const Vector3D &p0, const Vector3D &v0,
                  const Vector3D &value = Vector3D(0.0, 0.0, 0.0));

    public:

        Body(const std::string &name, double mass, const Vector3D &p0, const Vector3D &v0,
             const Vector3D &value = Vector3D(0.0, 0.0, 0.0));

        Body(const std::string &name, double mass, int lenLog, const Vector3D &p0, const Vector3D &v0,
             const Vector3D &value = Vector3D(0.0, 0.0, 0.0));

        Body(Body& otherBody);

        const std::string &getName() const { return name_; }

        const Vector3D &getValue() const { return valueCurrentForce_; }

        Vector3D getSpeed() const { return speed_; }

        const Vector3D &getAcceleration() const { return acceleration_; }

        Vector3D getPosition() const { return position_; }

        const Vector3D &getP0() const { return p0_; }

        const Vector3D &getV0() const { return v0_; }

        void transferTo(Body *Dest, const Vector3D &netForce);

        void computeCinematic(double dt, bool enableG = true);

        std::string printInfoBody() const;

    };
}

#endif //MULTIBODYSIMULATOR_BODY_H
