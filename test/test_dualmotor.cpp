// Include all needed libraries here
#include <iostream>
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

    std::cout << "---- MODE ----\n";
    std::cout << "[0]  Stop\n";
    std::cout << "[1]  Move forward\n";
    std::cout << "[2]  Move backward\n";
    std::cout << "[3]  Turn right (90 deg using timer only)\n";
    std::cout << "[4]  Turn left (90 deg using timer only)\n";
    std::cout << "[5]  Rotate right\n";
    std::cout << "[6]  Rotate left\n";
    std::cout << "[99] Exit program\n";

    bool running = true;

    while (running) {
        std::cout << "Enter mode: ";
        int mode;
        std::cin >> mode;
        switch (mode) {
            case 0:
                motor.Stop();
                break;
            case 1:
                motor.MoveForward(100);
                // Stop motor after some time for moving forward/backward
                sleep(1);
                motor.Stop();
                break;
            case 2:
                motor.MoveBackward(100);
                // Stop motor after some time for moving forward/backward
                sleep(1);
                motor.Stop();
                break;
            case 3:
                motor.TurnRight(1.57, true);
                break;
            case 4:
                motor.TurnLeft(1.57, true);
                break;
            case 5:
                motor.TurnRight(1); // not using time limit, any number >0 is OK
                break;
            case 6:
                motor.TurnLeft(1); // not using time limit, any number >0 is OK
                break;
            case 99:
                running = false;
                break;
        }
    }
    motor.Stop();

	return 0;
}