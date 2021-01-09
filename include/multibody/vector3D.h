//
// Created by nicol on 02/01/2021.
//

#ifndef MULTIBODYSIMULATOR_VECTOR3D_H
#define MULTIBODYSIMULATOR_VECTOR3D_H

#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

namespace multibody {
    class Vector3D {
    protected:
        double x_, y_, z_;
    public:
        explicit Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) {
            x_ = x;
            y_ = y;
            z_ = z;
        };

        double getX() const { return x_; }

        double getY() const { return y_; }

        double getZ() const { return z_; }

        void setX(double x) { x_ = x; }

        void setY(double y) { y_ = y; }

        void setZ(double z) { z_ = z; }

        const std::string toStringVector3D() const {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2);
            stream << " {" << x_ << ", " << y_ << ", " << z_ << "}";

            return stream.str();
            //.c_str();
        }

        double intensity3D() const {
            return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
        }

        Vector3D normalization3D() const {
            return Vector3D(x_, y_, z_) / intensity3D();
        }

        Vector3D &operator=(const Vector3D &p) {
            x_ = p.x_;
            y_ = p.y_;
            z_ = p.z_;

            return *this;
        }

        Vector3D operator+(const Vector3D &p) const {
            return Vector3D(x_ + p.x_, y_ + p.y_, z_ + p.z_);
        }

        Vector3D &operator+=(const Vector3D &p) {
            x_ += p.x_;
            y_ += p.y_;
            z_ += p.z_;

            return *this;
        }

        Vector3D operator-(const Vector3D &p) const {
            return Vector3D(x_ - p.x_, y_ - p.y_, z_ - p.z_);
        }

        Vector3D &operator-=(const Vector3D &p) {
            x_ -= p.x_;
            y_ -= p.y_;
            z_ -= p.z_;

            return *this;
        }

        Vector3D operator*(double N) const {
            return Vector3D(x_ * N, y_ * N, z_ * N);
        }

        Vector3D &operator*=(double N) {
            x_ *= N;
            y_ *= N;
            z_ *= N;

            return *this;
        }


        Vector3D operator/(double N) const {
            return Vector3D(x_ / N, y_ / N, z_ / N);
        }

        Vector3D &operator/=(double N) {
            x_ /= N;
            y_ /= N;
            z_ /= N;

            return *this;
        }

    };
}

#endif //MULTIBODYSIMULATOR_VECTOR3D_H
