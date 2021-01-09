//
// Created by nicol on 02/01/2021.
//

#include "../include/multibody/spring.h"

const multibody::Vector3D &multibody::Spring::computeNetForceOnTheBody() {
    assert(isConnected());
    Vector3D direction = (dest_->getPosition() - src_->getPosition());
    netForce_ = direction.normalization3D() * (direction.intensity3D() - l0_) * stiffness_;
    return netForce_;
}
