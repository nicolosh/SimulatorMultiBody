//
// Created by nicol on 02/01/2021.
//

#ifndef MULTIBODYSIMULATOR_SPRING_H
#define MULTIBODYSIMULATOR_SPRING_H

#include "multibody/connector.h"

namespace multibody {
    class Spring : public Connector {
    protected:
        double stiffness_, l0_;
    public:
        Spring(const std::string &name, Body* src, Body* dest, double l0, double stiffness) : Connector(name, src,
                                                                                                      dest),
                                                                                            l0_(l0),
                                                                                            stiffness_(stiffness) {}

        virtual  const Vector3D &computeNetForceOnTheBody() override;

    };
}

#endif //MULTIBODYSIMULATOR_SPRING_H
