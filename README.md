# motorPi

Motor driver for Raspberry Pi using L298 dual bridge motor driver.

## Dependencies
- wiringPi

The driver mainly uses GPIO to control the motor. For using c++ to control the GPIO, wiringPi is needed.
```
sudo apt-get install wiringpi
```

## Compiling the program
### Build the static library
```
cd src
g++ -c *.cpp
ar -crs libmotorPi.a *.o
rm -rf *.o
cd ..
```
### Build test program
```
g++ -o motor_test motor_test.cpp -lwiringPi -Isrc -Lsrc -lmotorPi
```

## Run test program
```
./motor_test
```