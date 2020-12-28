# motorPi

Motor driver for Raspberry Pi using L298 dual bridge motor driver.

## Dependencies
- wiringPi

The driver mainly uses GPIO to control the motor. For using c++ to control the GPIO, wiringPi is needed.
```
sudo apt-get install wiringpi
```

## Compiling the program
### Build libraries and test program at once
```
make all
```

### Build separately
#### Build the static library
```
cd src
make
cd ..
```
#### Build test program
```
make
```
or
```
g++ -o motor_test motor_test.cpp -lwiringPi -Isrc -Lsrc -lmotorPi
```

## Run test program
```
./motor_test
```
