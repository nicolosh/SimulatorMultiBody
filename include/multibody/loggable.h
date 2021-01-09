//
// Created by nicol on 08/01/2021.
//

#ifndef MULTIBODYSIMULATOR_LOGGABLE_H
#define MULTIBODYSIMULATOR_LOGGABLE_H

#include <fstream>
#include "vector3D.h"

namespace multibody {
    class Loggable {
    protected:
        Vector3D *data_;
        int lenLog_;
        bool active_;
        int step_;

        static void arrayCopy(const Vector3D src[], Vector3D dest[], int len) {
            for (int i = 0; i < len; ++i) {
                dest[i] = src[i];
            }
        }

        explicit Loggable(int lenLog, int step = 0) : lenLog_(lenLog) {
            if (lenLog == 0) {
                active_ = false;
                data_ = nullptr;
            } else {
                data_ = new Vector3D[lenLog];
                active_ = true;
            }
        }

        void logValue(const Vector3D& value) {
            if (step_ < lenLog_ && active_ && data_ != nullptr)
                data_[step_++] = value;

        }

    public:

        double getLenLog() const { return lenLog_; }

        void getData(Vector3D buffer[], int len) {
            if (data_ == nullptr)
                return;

            if (len > lenLog_) {
                len = lenLog_;
                arrayCopy(data_, buffer, len);
            }
        }

        Loggable(Loggable &other) {
            step_ = other.step_;
            lenLog_ = other.lenLog_;

            if (other.data_ != nullptr) {
                data_ = new Vector3D[lenLog_];
                for (int i = 0; i < lenLog_; ++i) {
                    data_[i] = other.data_[i];
                }
            } else
                data_ = nullptr;
        }

        bool getActive() const { return active_; }

        void writeOnFile(const char *fileName) {
            std::ofstream logFile;

            logFile.open(fileName);

            for (int i = 0; i < lenLog_; ++i) {
                logFile << "{" << data_[i].getX() << ", " << data_[i].getY() << ", " << data_[i].getZ() << "}" << std::endl;
            }

            logFile.close();
        }

        ~Loggable() {
            delete[] data_;
        }

    };
}

#endif //MULTIBODYSIMULATOR_LOGGABLE_H
