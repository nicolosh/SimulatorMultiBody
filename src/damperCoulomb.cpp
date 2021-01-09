//
// Created by nicol on 02/01/2021.
//

#include "../include/multibody/damperCoulomb.h"

const multibody::Vector3D &multibody::DamperCoulomb::computeNetForceOnTheBody() {
    assert(isConnected());
    netForce_ = (dest_->getSpeed() - src_->getSpeed()) * cineticFrictionCoefficient_;
    return netForce_;

}
