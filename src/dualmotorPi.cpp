#include "dualmotorPi.h"

void DualMotorPi::Init(int rightPinEn, int rightPin1, int rightPin2,
                       int leftPinEn, int leftPin1, int leftPin2) {
    // Init MotorPi class for right and left motor
    rightMotor.Init(rightPinEn, rightPin1, rightPin2);
    leftMotor.Init(leftPinEn, leftPin1, leftPin2);
}

void DualMotorPi::Stop() {
    rightMotor.Stop();
    leftMotor.Stop();
}

void DualMotorPi::SetSpeed(double speed) {
    rightMotor.SetSpeed(speed);
    leftMotor.SetSpeed(speed);
}

void DualMotorPi::MoveForward(double speed) {
    rightMotor.MoveForward(speed);
    leftMotor.MoveForward(speed);
}

void DualMotorPi::MoveBackward(double speed) {
    rightMotor.MoveBackward(speed);
    leftMotor.MoveBackward(speed);
}

void DualMotorPi::Rotate(double angle) {
    if (angle>0){
        rightMotor.MoveForward();
        leftMotor.MoveBackward();
    }
    else {
        leftMotor.MoveForward();
        rightMotor.MoveBackward();
    }

    // Currently using onlt sleep to control angle
    // Assumed 90deg/sec
    double i;
    double set_time = 2 * abs(angle)/M_PI;
    for (i=0; i < set_time; i+=0.01) {
        usleep(10000);
    }

    DualMotorPi::Stop();
}

void DualMotorPi::TurnLeft(double angle) {
    DualMotorPi::Rotate(angle);
}

void DualMotorPi::TurnRight(double angle) {
    DualMotorPi::Rotate(-1 * angle);
}
