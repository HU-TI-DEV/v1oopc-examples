#include <hwlib.hpp>


class inputController {
    virtual bool isLeft() = 0;
    virtual bool isRight() = 0;
    virtual bool isClick() = 0;
};