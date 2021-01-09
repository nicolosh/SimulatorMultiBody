//
// Created by nicol on 02/01/2021.
//

#ifndef MULTIBODYSIMULATOR_DAMPERCOULOMB_H
#define MULTIBODYSIMULATOR_DAMPERCOULOMB_H


#include "multibody/connector.h"

namespace multibody {
    class DamperCoulomb : public Connector {
    protected:
        double cineticFrictionCoefficient_;
    public:
        DamperCoulomb(const std::string &name, Body *src, Body *dest, double cineticFrictionCoefficient) : Connector(
                name, src, dest), cineticFrictionCoefficient_(cineticFrictionCoefficient) {}

        virtual const Vector3D &computeNetForceOnTheBody() override;
    };
}

#endif //MULTIBODYSIMULATOR_DAMPERCOULOMB_H
