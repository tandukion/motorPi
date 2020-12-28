#include "dualmotorPi.h"

void DualMotorPi::init(int right_pin_en, int right_pin_in1, int right_pin_in2,
                       int left_pin_en, int left_pin_in1, int left_pin_in2) {
    // Init MotorPi class for right and left motor
    right_motor.init(right_pin_en, right_pin_in1, right_pin_in2);
    left_motor.init(left_pin_en, left_pin_in1, left_pin_in2);
}

void DualMotorPi::stop() {
    right_motor.stop();
    left_motor.stop();
}

void DualMotorPi::set_speed(double speed) {
    right_motor.set_speed(speed);
    left_motor.set_speed(speed);
}

void DualMotorPi::move_forward(double speed) {
    right_motor.move_forward(speed);
    left_motor.move_forward(speed);
}

void DualMotorPi::move_backward(double speed) {
    right_motor.move_backward(speed);
    left_motor.move_backward(speed);
}

void DualMotorPi::rotate(double angle) {
    if (angle>0){
        right_motor.move_forward();
        left_motor.move_backward();
    }
    else {
        left_motor.move_forward();
        right_motor.move_backward();
    }

    // Currently using onlt sleep to control angle
    // Assumed 90deg/sec
    double i;
    double set_time = 2 * abs(angle)/M_PI;
    for (i=0; i < set_time; i+=0.01) {
        usleep(10000);
    }

    DualMotorPi::stop();
}

void DualMotorPi::turn_left(double angle) {
    DualMotorPi::rotate(angle);
}

void DualMotorPi::turn_right(double angle) {
    DualMotorPi::rotate(-1 * angle);
}
