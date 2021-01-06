#ifndef _MOTORPI_H
#define _MOTORPI_H

#include <softPwm.h>
#include <wiringPi.h>

/**
 * Class for 1 channel of L298 Motor Driver control using Raspberry Pi GPIO.
 */ 
class MotorPi {
    private:
        int pin_enable_;
        int pin_in_1_, pin_in_2_;

    public:
        /**
         * Initialize 1 bridge channel of L298 driver with given GPIO pin. 
         * 
         * @param pin_enable    {int}   Enable pin
         * @param pin_in_1      {int}   Input 1 pin
         * @param pin_in_2      {int}   Input 2 pin
         */
        void Init(int pin_enable, int pin_in_1, int pin_in_2);

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