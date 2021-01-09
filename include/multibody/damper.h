//
// Created by nicol on 02/01/2021.
//

#ifndef MULTIBODYSIMULATOR_DAMPER_H
#define MULTIBODYSIMULATOR_DAMPER_H

#include "multibody/connector.h"

namespace multibody {
    class Damper : public Connector {
    protected:
        double dampingCoefficient_;

    public:
        Damper(const std::string &name, Body *src, Body *dest, double dampingCoefficient) : Connector(name, src, dest),
                                                                                            dampingCoefficient_(
                                                                                                    dampingCoefficient) {}

        virtual const Vector3D &computeNetForceOnTheBody() override;
    };
}

#endif //MULTIBODYSIMULATOR_DAMPER_H
