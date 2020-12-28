#include "motorPi.h"

void MotorPi::init(int pin_en, int pin_in1, int pin_in2) {
    wiringPiSetup();

    pin_EN = pin_en;
    pin_IN1 = pin_in1;
    pin_IN2 = pin_in2;

    // Direction setter pin
    pinMode(pin_IN1, OUTPUT);
    pinMode(pin_IN2, OUTPUT);

    digitalWrite(pin_IN1, LOW);
    digitalWrite(pin_IN2, LOW);

    // Enable pin. Use PWM to make speed changeable
    softPwmCreate(pin_EN, 0, 100);
}

void MotorPi::stop() {
    digitalWrite(pin_IN1, LOW);
    digitalWrite(pin_IN2, LOW);
    softPwmWrite(pin_EN, 0);
}

void MotorPi::set_speed(double speed) {
    softPwmWrite(pin_EN, int(speed));
}

void MotorPi::move(bool forward, double speed) {
    if (forward){
        digitalWrite(pin_IN1, HIGH);
        digitalWrite(pin_IN2, LOW);
    }
    else{
        digitalWrite(pin_IN1, LOW);
        digitalWrite(pin_IN2, HIGH);
    }
    
    // softPwm only accept integer
    softPwmWrite(pin_EN, int(speed));
}

void MotorPi::move_forward(double speed) {
    MotorPi::move(true, speed);
}

void MotorPi::move_backward(double speed) {
    MotorPi::move(false, speed);
}
