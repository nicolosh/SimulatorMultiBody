//
// Created by nicol on 03/01/2021.
//

#ifndef MULTIBODYSIMULATOR_CONNECTOR_H
#define MULTIBODYSIMULATOR_CONNECTOR_H

#include <string>
#include "multibody/body.h"

namespace multibody {
    class Connector {
    protected:
        std::string name_;
        Body *src_ = nullptr, *dest_ = nullptr;
        Vector3D netForce_; // forza generata dal tipo di connettore (molla, smorzatore, coulombDamper...)
    public:
        Connector(const std::string &name, Body *src, Body *dest) : name_(name), src_(src), dest_(dest) {};

        virtual const Vector3D &computeNetForceOnTheBody() = 0;

        Body *getBodyDest() const { return dest_; }

        Body *getBodySrc() const { return src_; }

        const std::string &getName() const { return name_; }

        const Vector3D &getNetForce() const { return netForce_; }

        bool isConnected() const {
            return (src_ != nullptr && dest_ != nullptr);
        }
    };
}

#endif //MULTIBODYSIMULATOR_CONNECTOR_H
