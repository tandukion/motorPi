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
mkdir build
cd build
cmake ..
make
```

### Installing the library
```
sudo make install
```

## Run test program
### Test dual motor
Run the following command under `build` directory created on build.
```
./test_dualmotor
```
