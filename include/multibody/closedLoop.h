//
// Created by nicol on 02/01/2021.
//

#ifndef MULTIBODYSIMULATOR_CLOSEDLOOP_H
#define MULTIBODYSIMULATOR_CLOSEDLOOP_H

#include "multibody/connector.h"
#include <vector>

namespace multibody {
    class ClosedLoop {
    private:
        //double dt_, T_;
        std::vector<Body *> bodiesConnected_;
        std::vector<Connector *> connectors_;
    public:
        ClosedLoop(const std::vector<Body *> &bodiesConnected, const std::vector<Connector *> &connectors)
                : bodiesConnected_(bodiesConnected), connectors_(connectors) {};

        void simulationStep(double dt, bool enableGravity = true);

        void completeSimulation(double dt, int T, bool enableGravity = true, bool enableInfoBodies = true);

        void getStateBodies() const;

        const std::vector<Connector *> &getConnectors() const { return connectors_; }

        const std::vector<Body *> &getBodies() const { return bodiesConnected_; }

        void addConnector(Connector &connector);

        //void setDt(double dt) { dt_ = dt; }

        //void setT(double T) { T_ = T; }

        void addBody(Body &body) { bodiesConnected_.push_back(&body); }

    };
}

#endif //MULTIBODYSIMULATOR_CLOSEDLOOP_H
