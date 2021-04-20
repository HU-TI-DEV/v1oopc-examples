#ifndef IPASS_JOYSTICK_HPP
#define IPASS_JOYSTICK_HPP

#include <hwlib.hpp>
#include "inputController.hpp"

class joystickController: public inputController {
private:
    hwlib::pin_in &click;
    hwlib::adc &X;
    hwlib::adc &Y;

    int Xcoor = 2075;  ///middle point
    int Ycoor = 2075;

    const int minimums = 1900;
    const int maximums = 2200;

    void checkJoystick();

public:
    joystickController (hwlib::pin_in & click, hwlib::adc & x, hwlib::adc & y);

    bool isLeft() override;
    bool isRight() override;
    bool isClick() override;
    bool isUp();
    bool isDown();
    uint16_t readX();
    uint16_t readY();
};

#endif //IPASS_JOYSTICK_HPP
