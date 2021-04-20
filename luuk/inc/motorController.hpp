#ifndef RCCAR_MOTORCONTROLLER_HPP
#define RCCAR_MOTORCONTROLLER_HPP

#include <hwlib.hpp>
#include "PCA9685.hpp"

enum class direction : bool {
    forward        = false,
    backward       = true
};

class PCAMotorController {
private:

    PCA9685_i2c & controller;
    hwlib::target::pin_out & dirPin;
    const uint8_t & pwmPin;
    bool currentDir = false;

public:

    /// construct by providing the i2c channel
    PCAMotorController(PCA9685_i2c & pca, hwlib::target::pin_out & dirPin, const uint8_t & pwmPin ):
            controller( pca ),
            dirPin( dirPin ),
            pwmPin( pwmPin )
    {}

    void motorOff();
    void setDirection( enum direction dir );
    uint8_t getSpeed();
    void setSpeed( uint16_t speed );
};

#endif //RCCAR_MOTORCONTROLLER_HPP
