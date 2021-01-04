#include "motorPi.h"

void MotorPi::Init(int pinEn, int pinIn1, int pinIn2) {
    wiringPiSetup();

    pinEN = pinEn;
    pinIN1 = pinIn1;
    pinIN2 = pinIn2;

    // Direction setter pin
    pinMode(pinIN1, OUTPUT);
    pinMode(pinIN2, OUTPUT);

    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, LOW);

    // Enable pin. Use PWM to make speed changeable
    softPwmCreate(pinEN, 0, 100);
}

void MotorPi::Stop() {
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, LOW);
    softPwmWrite(pinEN, 0);
}

void MotorPi::SetSpeed(double speed) {
    softPwmWrite(pinEN, int(speed));
}

void MotorPi::Move(bool forward, double speed) {
    if (forward){
        digitalWrite(pinIN1, HIGH);
        digitalWrite(pinIN2, LOW);
    }
    else{
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, HIGH);
    }
    
    // softPwm only accept integer
    softPwmWrite(pinEN, int(speed));
}

void MotorPi::MoveForward(double speed) {
    MotorPi::Move(true, speed);
}

void MotorPi::MoveBackward(double speed) {
    MotorPi::Move(false, speed);
}
