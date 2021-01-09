//
// Created by nicol on 02/01/2021.
//

#include "../include/multibody/damper.h"

const multibody::Vector3D &multibody::Damper::computeNetForceOnTheBody(){
    assert(isConnected());
    netForce_ = (dest_->getSpeed() - src_->getSpeed()) * dampingCoefficient_;
    return netForce_;
}
