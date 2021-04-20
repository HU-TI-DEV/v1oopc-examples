#include <hwlib.hpp>
#include "inc/PCA9685.hpp"
#include "inc/motorController.hpp"
#include "inc/joystick.hpp"
#include "inc/MovingAverage.hpp"

int main() {

    // wait for the PC console to start
    hwlib::wait_ms(500);

    namespace target = hwlib::target;

    auto click = target::pin_in(target::pins::d2);
    click.pullup_enable();
    auto X = due::pin_adc(due::ad_pins::a0);
    auto Y = due::pin_adc(due::ad_pins::a1);
    joystickController joy(click, X, Y);

    auto scl = target::pin_oc(target::pins::scl);
    auto sda = target::pin_oc(target::pins::sda);
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    auto PCA = PCA9685_i2c(i2c_bus);

    //  Initialize the PCA9685 with the values for this project
    PCA.begin();
    PCA.setOscillatorFrequency(27000000);
    PCA.setPWMFreq(50);
    hwlib::wait_ms(10);
    //Servo min and max values;
//    uint16_t USMIN = 600;
//    uint16_t USMAX = 2400;
    const uint16_t DIRPIN    = 2;
    const uint16_t PWMPIN    = 1;

    // Motordriver controller
    const uint16_t FORWARDS    = 4095;   //100% dutycycle for forwards
    const uint16_t BACKWARDS    = 0;    //0% dutycycle for backwards

    uint16_t direction = 0;              //contains either BACKWARDS or FORWARDS value

    bool timerRunning      = false;       // timer running
    uint32_t timeBetweenStep     = 1000;         // = versnellingsstap tijd (Time between each step update)
    uint16_t Stepsize = 40;         // = volgende PWM waarde (Value of the increment per step)
    uint16_t acceleration = 0;           // = huidige snelheid (Current PWM value written to board)
    int16_t targetSpeed = 0;       // = gewenste snelheid (Target PWM value as read from joystick)
    int16_t previousSpeed = 0;         // staat stil (Previous value of acceleration)
    int8_t  speedUp_slowDown = 1;   // 1 = versnellen -1 = vertragen 0 = idle
    uint_fast64_t timer;                // variable that holds the timer

    MovingAverage <uint16_t> joyYAverage(50);

    // Servodriver controller
    int16_t targetRotation = 0;       // = (Target PWM value as read from joystick)
    MovingAverage <uint16_t> joyXAverage(50);


    volatile bool _true = true;
    while (_true) {

        // read joystick value and remap to -2048 - +2048
        targetSpeed = joyYAverage.CalculateMovingAverage(joy.readY());// - 2048) * 2;
        targetRotation = joyXAverage.CalculateMovingAverage(joy.readX());
        //hwlib::cout << "joystick: " << targetSpeed;

        targetSpeed = (targetSpeed - 2048) * 2;
        targetRotation = (targetRotation - 2048) * 2;
        //hwlib::cout << "  na normalisatie: " << targetSpeed;

        if (targetSpeed >= -50 && targetSpeed <= 150){
            targetSpeed = 0;
        }
        if (targetRotation >= -50 && targetRotation <= 150){
            targetRotation = 0;
        }
        //hwlib::cout << "  na deadzone: " << targetSpeed;

        // Pick direction
        if (targetSpeed < 0){
            direction = FORWARDS;
        } else if (targetSpeed > 0) {
            direction = BACKWARDS;
        }

        // make speed absolute
        if (targetSpeed < 0){
            targetSpeed *= -1;
        }

        if (targetSpeed > previousSpeed) {
            speedUp_slowDown = 1;
        } else if (targetSpeed < previousSpeed) {
            speedUp_slowDown = -1;
        }else {
            speedUp_slowDown = 0;
        }

        //hwlib::cout << "Joystick abs value: " << targetSpeed << hwlib::endl;

        // decide to move
        if (speedUp_slowDown != 0) {
            if (!timerRunning) {
                timer = hwlib::now_us();
                timerRunning = true;
                //acceleration = 0;
            }
        }


        // decide direction to move in
        if (timerRunning) {
            if (hwlib::now_us() - timer > timeBetweenStep){

                // change acceleration
                acceleration += (Stepsize * speedUp_slowDown);
                if (acceleration >= targetSpeed) {
                    timer       = 0;
                    timerRunning  = false;
                    acceleration = targetSpeed;
                } else {
                    // restart timer
                    timer = hwlib::now_us();
                }
            }
        }

        //hwlib::cout << " Acceleration is: " << acceleration << hwlib::endl;

        if (speedUp_slowDown != 0) {
            PCA.setPin(DIRPIN, direction);
            PCA.setPin(PWMPIN, acceleration);
            previousSpeed = acceleration;
        }
    }
}