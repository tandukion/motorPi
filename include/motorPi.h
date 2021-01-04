#ifndef _MOTORPI_H
#define _MOTORPI_H

#include <softPwm.h>
#include <wiringPi.h>

/**
 * Class for 1 channel of L298 Motor Driver control using Raspberry Pi GPIO.
 */ 
class MotorPi {
    private:
        int pinEN;
        int pinIN1, pinIN2;

    public:
        /**
         * Initialize 1 bridge channel of L298 driver with given GPIO pin. 
         * 
         * @param pinEn     {int}   Enable pin
         * @param pinIn1    {int}   Input 1 pin
         * @param pinIn2    {int}   Input 2 pin
         */
        void Init(int pinEn, int pinIn1, int pinIn2);

        /**
         * Stop motor
         */
        void Stop();
        
        /**
         * Set the motor speed in percentage of full speed.
         * 
         * @param speed     {double}    Speed of Motor in percentage.
         */
        void SetSpeed(double speed);

        /**
         * Move the motor with given direction and speed.
         * Speed is controlled by PWM percentage.
         * 
         * @param forward   {bool}      Forward direction of Motor rotation. Default to true.
         * @param speed     {double}    Speed of Motor in percentage. Default to 100%.
         */
        void Move(bool forward=true, double speed=100);
        /**
         * Move the motor in forward direction
         * 
         * @param speed     {double}    Speed of Motor in percentage. Default to 100%.
         */
        void MoveForward(double speed=100);
        /**
         * Move the motor in backward direction
         * 
         * @param speed     {double}    Speed of Motor in percentage. Default to 100%.
         */
        void MoveBackward(double speed=100);
};

#endif