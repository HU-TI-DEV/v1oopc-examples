#include "hwlib.hpp"
//#include <array>

int main( void ){	
  
   namespace target = hwlib::target;
   auto led   = target::pin_out( target::pins::led );
   
   hwlib::blink( led );
}
