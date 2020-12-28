#ifndef _MOTORPI_H
#define _MOTORPI_H

#include <softPwm.h>
#include <wiringPi.h>

/**
 * Class for 1 channel of L298 Motor Driver control using Raspberry Pi GPIO.
 */ 
class MotorPi {
    private:
        int pin_EN;
        int pin_IN1, pin_IN2;

    public:
        /**
         * Initialize 1 bridge channel of L298 driver with given GPIO pin. 
         * 
         * @param pin_en    {int}   Enable pin
         * @param pin_in1   {int}   Input 1 pin
         * @param pin_in2   {int}   Input 2 pin
         */
        void init(int pin_en, int pin_in1, int pin_in2);

        /**
         * Stop motor
         */
        void stop();
        
        /**
         * Set the motor speed in percentage of full speed.
         * 
         * @param speed     {double}    Speed of Motor in percentage.
         */
        void set_speed(double speed);

        /**
         * Move the motor with given direction and speed.
         * Speed is controlled by PWM percentage.
         * 
         * @param forward   {bool}      Forward direction of Motor rotation. Default to true.
         * @param speed     {double}    Speed of Motor in percentage. Default to 100%.
         */
        void move(bool forward=true, double speed=100);
        /**
         * Move the motor in forward direction
         * 
         * @param speed     {double}    Speed of Motor in percentage. Default to 100%.
         */
        void move_forward(double speed=100);
        /**
         * Move the motor in backward direction
         * 
         * @param speed     {double}    Speed of Motor in percentage. Default to 100%.
         */
        void move_backward(double speed=100);
};

#endif