#ifndef _DUALMOTORPI_H
#define _DUALMOTORPI_H

#include "motorPi.h"
#include <unistd.h>
#include <math.h>

/**
 * Class for dual-channel of L298 Motor Driver control using Raspberry Pi GPIO.
 * Used for mobile robot with right and left motors.
 */ 
class DualMotorPi {
    private:
        /**
         * Motors defined as right and left motors.
         */
        MotorPi rightMotor;
        MotorPi leftMotor;

    public:
        /**
         * Initialize dual bridge channel of L298 driver with given GPIO pin. 
         * 
         * @param rightPinEn    {int}   Enable pin for right motor
         * @param rightPin1     {int}   Input 1 pin for right motor
         * @param rightPin2     {int}   Input 2 pin for right motor
         * @param leftPinEn     {int}   Enable pin for left motor
         * @param leftPin1      {int}   Input 1 pin for left motor
         * @param leftPin2      {int}   Input 2 pin for left motor
         */
        void Init(int rightPinEn, int rightPin1, int rightPin2,
                  int leftPinEn, int leftPin1, int leftPin2);

        /**
         * Stop motors
         */
        void Stop();

        /**
         * Set the motor speed in percentage of full speed.
         * 
         * @param speed     {double}    Speed of Motor in percentage.
         */
        void SetSpeed(double speed);

        /**
         * Move the motors in forward direction
         * 
         * @param speed {double}    Speed of Motor in percentage. Default to 100%.
         */
        void MoveForward(double speed=100);
        /**
         * Move the motors in backward direction
         * 
         * @param speed {double}    Speed of Motor in percentage. Default to 100%.
         */
        void MoveBackward(double speed=100);


        /**
         * Rotate the system with given angle.
         * Angle axis is counter-clockwise of Z-axis (Positive angle = left rotation)
         * Rotation is controlled by moving right motor forward and left motor backward (vice versa).
         * 
         * @param angle {double}    Angle of rotation in radian.
         */
        void Rotate(double angle=0);
        /**
         * Rotate the system to the right (clockwise of Z-axis).
         * 
         * @param angle {double}    Angle of rotation in radian.
         */
        void TurnLeft(double angle=0);
        /**
         * Rotate the system to the left (counter-clockwise of Z-axis).
         * 
         * @param angle {double}    Angle of rotation in radian.
         */
        void TurnRight(double angle=0);
};

#endif