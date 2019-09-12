#include "hwlib.hpp"

int main( void ){	
   
   // wait for the PC to start the console
   hwlib::wait_ms( 500 );
   
   hwlib::cout << "ADC a0 demo\n";
   
   auto pin = hwlib::target::pin_adc( hwlib::target::ad_pins::a0 );
   
   for(;;){
      hwlib::cout << pin.read() << "\n";
      hwlib::wait_ms( 200 );
   }
   
}
