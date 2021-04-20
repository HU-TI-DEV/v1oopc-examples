#include "../inc/joystick.hpp"

namespace target = hwlib::target;

joystickController::joystickController (hwlib::pin_in & click, hwlib::adc & x, hwlib::adc & y):
        click(click),
        X(x),
        Y(y)
{}

bool joystickController::isLeft() {
    checkJoystick();
    return Xcoor <= minimums && Ycoor >= minimums && Ycoor <= maximums;
}
bool joystickController::isRight() {
    checkJoystick();
    return Xcoor >= maximums && Ycoor >= minimums && Ycoor <= maximums;
}
bool joystickController::isClick() {
    return !click.read();

}
bool joystickController::isUp() {
    checkJoystick();
    return Ycoor <= minimums && Xcoor >= minimums && Xcoor <= maximums;
}
bool joystickController::isDown() {
    checkJoystick();
    return Ycoor >= maximums && Xcoor >= minimums && Xcoor <= maximums;
}

uint16_t joystickController::readX(){
    checkJoystick();
    return Xcoor;
}

uint16_t joystickController::readY(){
    checkJoystick();
    return Ycoor;
}

void joystickController::checkJoystick(){
    Xcoor = X.read();
    Ycoor = Y.read();
}
