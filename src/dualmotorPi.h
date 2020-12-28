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
        MotorPi right_motor;
        MotorPi left_motor;

    public:
        /**
         * Initialize dual bridge channel of L298 driver with given GPIO pin. 
         * 
         * @param right_pin_en  {int}   Enable pin for right motor
         * @param right_pin_in1 {int}   Input 1 pin for right motor
         * @param right_pin_in2 {int}   Input 2 pin for right motor
         * @param left_pin_en   {int}   Enable pin for left motor
         * @param left_pin_in1  {int}   Input 1 pin for left motor
         * @param left_pin_in2  {int}   Input 2 pin for left motor
         */
        void init(int right_pin_en, int right_pin_in1, int right_pin_in2,
                  int left_pin_en, int left_pin_in1, int left_pin_in2);

        /**
         * Stop motors
         */
        void stop();

        /**
         * Set the motor speed in percentage of full speed.
         * 
         * @param speed     {double}    Speed of Motor in percentage.
         */
        void set_speed(double speed);

        /**
         * Move the motors in forward direction
         * 
         * @param speed {double}    Speed of Motor in percentage. Default to 100%.
         */
        void move_forward(double speed=100);
        /**
         * Move the motors in backward direction
         * 
         * @param speed {double}    Speed of Motor in percentage. Default to 100%.
         */
        void move_backward(double speed=100);


        /**
         * Rotate the system with given angle.
         * Angle axis is counter-clockwise of Z-axis (Positive angle = left rotation)
         * Rotation is controlled by moving right motor forward and left motor backward (vice versa).
         * 
         * @param angle {double}    Angle of rotation in radian.
         */
        void rotate(double angle=0);
        /**
         * Rotate the system to the right (clockwise of Z-axis).
         * 
         * @param angle {double}    Angle of rotation in radian.
         */
        void turn_left(double angle=0);
        /**
         * Rotate the system to the left (counter-clockwise of Z-axis).
         * 
         * @param angle {double}    Angle of rotation in radian.
         */
        void turn_right(double angle=0);
};

#endif