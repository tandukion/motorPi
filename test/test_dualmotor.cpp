#include <iostream>		// Include all needed libraries here
#include <unistd.h>
#include <signal.h>

#include <dualmotorPi.h>

int main()
{
    // GPIO pin number based on WiringPi
    // Right Motor
    int Motor_A_EN = 0;     // Pin 11
    int Motor_A_Pin1 = 1;   // Pin 12
    int Motor_A_Pin2 = 2;   // Pin 13
    // Left Motor
    int Motor_B_EN = 7;     // Pin 7
    int Motor_B_Pin1 = 29;  // Pin 40
    int Motor_B_Pin2 = 25;  // Pin 37
    
    DualMotorPi motor;
    motor.init(Motor_A_EN, Motor_A_Pin1, Motor_A_Pin2, Motor_B_EN, Motor_B_Pin1, Motor_B_Pin2);

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
            motor.stop();
            break;
        case 1:
            motor.move_forward(100);
            break;
        case 2:
            motor.move_backward(100);
            break;
        case 3:
            motor.turn_right(1.57);
            break;
        case 4:
            motor.turn_left(1.57);
            break;
    }
    while (mode) {
        sleep(1);
        break;
    }
    motor.stop();

	return 0;
}