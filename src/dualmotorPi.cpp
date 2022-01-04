#include "dualmotorPi.h"

void DualMotorPi::Init(int right_pin_enable, int right_pin_1, int right_pin_2,
                       int left_pin_enable, int left_pin_1, int left_pin_2) {
    // Init MotorPi class for right and left motor
    right_motor_.Init(right_pin_enable, right_pin_1, right_pin_2);
    left_motor_.Init(left_pin_enable, left_pin_1, left_pin_2);
}

void DualMotorPi::Stop() {
    right_motor_.Stop();
    left_motor_.Stop();
}

void DualMotorPi::SetSpeed(double speed) {
    right_motor_.SetSpeed(speed);
    left_motor_.SetSpeed(speed);
}

void DualMotorPi::MoveForward(double speed) {
    right_motor_.MoveForward(speed);
    left_motor_.MoveForward(speed);
}

void DualMotorPi::MoveBackward(double speed) {
    right_motor_.MoveBackward(speed);
    left_motor_.MoveBackward(speed);
}

void DualMotorPi::Rotate(double angle, bool time_limit) {
    if (angle>0){
        right_motor_.MoveForward();
        left_motor_.MoveBackward();
    }
    else {
        left_motor_.MoveForward();
        right_motor_.MoveBackward();
    }

    if (time_limit) {
        // Currently using only sleep to control angle
        // Assumed 90deg/sec
        double i;
        double set_time = 2 * abs(angle)/M_PI;
        for (i=0; i < set_time; i+=0.01) {
            usleep(10000);
        }
        
        DualMotorPi::Stop();
    }
}

void DualMotorPi::TurnLeft(double angle, bool time_limit) {
    DualMotorPi::Rotate(angle, time_limit);
}

void DualMotorPi::TurnRight(double angle, bool time_limit) {
    DualMotorPi::Rotate(-1 * angle, time_limit);
}
