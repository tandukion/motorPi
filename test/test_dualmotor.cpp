#include <iostream>		// Include all needed libraries here
#include <unistd.h>
#include <signal.h>

#include <dualmotorPi.h>

int main()
{
    // GPIO pin number based on WiringPi
    // Right Motor
    int right_motor_en = 0;     // Pin 11
    int right_motor_pin_1 = 1;   // Pin 12
    int right_motor_pin_2 = 2;   // Pin 13
    // Left Motor
    int left_motor_en = 7;     // Pin 7
    int left_motor_pin_1 = 29;  // Pin 40
    int left_motor_pin_2 = 25;  // Pin 37
    
    DualMotorPi motor;
    motor.Init(right_motor_en, right_motor_pin_1, right_motor_pin_2, left_motor_en, left_motor_pin_1, left_motor_pin_2);

    std::cout << "[1] Move forward\n";
    std::cout << "[2] Move backward\n";
    std::cout << "[3] Turn right\n";
    std::cout << "[4] Turn left\n";
    std::cout << "[0] Stop\n";
    std::cout << "Enter mode: ";
    int mode;
    std::cin >> mode;
    switch (mode) {
        case 0:
            motor.Stop();
            break;
        case 1:
            motor.MoveForward(100);
            break;
        case 2:
            motor.MoveBackward(100);
            break;
        case 3:
            motor.TurnRight(1.57);
            break;
        case 4:
            motor.TurnLeft(1.57);
            break;
    }
    while (mode) {
        sleep(1);
        break;
    }
    motor.Stop();

	return 0;
}