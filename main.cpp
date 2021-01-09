#include <iostream>
#include "multibody/closedLoop.h"
#include "multibody/spring.h"
#include "multibody/damper.h"


using namespace std;
using namespace multibody;

int main() {

    std::vector<Body *> bodies;
    std::vector<Connector *> connectorList;

    double dt = 0.1;
    int T = 200;

    //creo corpi
    Body A("A", 1.0, T, Vector3D(0.0, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0));
    Body B("B", 2.0, T, Vector3D(1.1, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0));
    Body C("C", 3.0, T, Vector3D(1.9, 0.0, 0.0), Vector3D(0.0, 0.0, 0.0));

    bodies.push_back(&A);
    bodies.push_back(&B);
    bodies.push_back(&C);

    //creo i connettori
    connectorList.push_back(new Spring("K1", &A, &B, 1.0, 10));
    connectorList.push_back(new Damper("D1", &A, &B, 2));
    connectorList.push_back(new Spring("K2", &B, &C, 1.0, 100));
    connectorList.push_back(new Damper("D2", &B, &C, 10));
    connectorList.push_back(new Spring("K3", &C, &A, 2.1, 200));
    connectorList.push_back(new Damper("D3", &C, &A, 15));

    ClosedLoop closedLoop(bodies, connectorList);

    closedLoop.completeSimulation(dt, T, true, true);


    Body testBodyOne = A;

    testBodyOne.writeOnFile("logData_A.txt");
    B.writeOnFile("logData_B.txt");


    return 0;
}
