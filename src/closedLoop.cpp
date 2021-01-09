//
// Created by nicol on 02/01/2021.
//

#include "../include/multibody/closedLoop.h"

void multibody::ClosedLoop::simulationStep(double dt, bool enableGravity) {
    for (int k = 0; k < connectors_.size(); ++k) {
        //calcolo forza di ogni connettore in un dato istante temporale
        connectors_[k]->computeNetForceOnTheBody();
    }

    //calcolo della valueCurrentForce (Risultante di forze) per ogni body
    for (int k = 0; k < connectors_.size(); ++k) {
        Body *bodySRC = connectors_[k]->getBodySrc();
        bodySRC->transferTo(connectors_[k]->getBodyDest(), connectors_[k]->getNetForce());
    }

    //aggiorno gli attributi interni di ogni corpo una volta note le F_ris su ogni corpo
    for (int i = 0; i < bodiesConnected_.size(); ++i) {
        bodiesConnected_[i]->computeCinematic(dt, enableGravity);
    }
}

void multibody::ClosedLoop::completeSimulation(double dt, int T, bool enableGravity, bool enableInfoBodies) {
    std::cout << "Multibody Simulator Simulation started: displaying info for each body during the simulation with the Eulerian Integration if you will: " << std::endl;

    for (int i = 0; i < T; ++i) {
        simulationStep(dt, enableGravity);
        if (enableInfoBodies) {
            std::cout << "Time t = " << (i+1) * dt << ": " << std::endl;
            getStateBodies();
        }
    }
    if(!enableInfoBodies)
        std::cout << "No info requested -> call getStateBodies() if you want" << std::endl;

    std::cout << "Multibody Simulator Simulation finished " << std::endl;
}


//ritorna un vettore di VectorVector3D con ogni singola info dei corpi del mio sistema (name, p,v,a,F)
void multibody::ClosedLoop::getStateBodies() const {
    std::cout << "{" << std::endl;
    for (int i = 0; i < bodiesConnected_.size() - 1; ++i) {
        std::cout << bodiesConnected_[i]->printInfoBody() << ", " << std::endl;
    }
    std::cout << bodiesConnected_[bodiesConnected_.size() - 1]->printInfoBody() << std:: endl << "}" << std::endl;
}



void multibody::ClosedLoop::addConnector(Connector &connector) {
    if (connector.isConnected())
        connectors_.push_back(&connector);
}