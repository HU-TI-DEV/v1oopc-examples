#include "../inc/motorController.hpp"

void PCAMotorController::motorOff(){
    controller.setPin( pwmPin, 0 );
}

void PCAMotorController::setDirection( enum direction dir ){
    motorOff();
    dirPin.write( (bool) dir );
    dirPin.flush();
    currentDir = (bool) dir;
}

uint8_t PCAMotorController::getSpeed() {
    return controller.getPWM( pwmPin );
}

void PCAMotorController::setSpeed( uint16_t speed ){
    controller.setPin( pwmPin, speed );
}