#include "motorPi.h"

void MotorPi::Init(int pin_enable, int pin_in_1, int pin_in_2) {
    wiringPiSetup();

    pin_enable_ = pin_enable;
    pin_in_1_ = pin_in_1;
    pin_in_2_ = pin_in_2;

    // Direction setter pin
    pinMode(pin_in_1_, OUTPUT);
    pinMode(pin_in_2_, OUTPUT);

    digitalWrite(pin_in_1_, LOW);
    digitalWrite(pin_in_2_, LOW);

    // Enable pin. Use PWM to make speed changeable
    softPwmCreate(pin_enable_, 0, 100);
}

void MotorPi::Stop() {
    digitalWrite(pin_in_1_, LOW);
    digitalWrite(pin_in_2_, LOW);
    softPwmWrite(pin_enable_, 0);
}

void MotorPi::SetSpeed(double speed) {
    softPwmWrite(pin_enable_, int(speed));
}

void MotorPi::Move(bool forward, double speed) {
    if (forward){
        digitalWrite(pin_in_1_, HIGH);
        digitalWrite(pin_in_2_, LOW);
    }
    else{
        digitalWrite(pin_in_1_, LOW);
        digitalWrite(pin_in_2_, HIGH);
    }
    
    // softPwm only accept integer
    softPwmWrite(pin_enable_, int(speed));
}

void MotorPi::MoveForward(double speed) {
    MotorPi::Move(true, speed);
}

void MotorPi::MoveBackward(double speed) {
    MotorPi::Move(false, speed);
}
