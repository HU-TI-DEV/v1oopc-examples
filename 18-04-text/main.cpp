#include "hwlib.hpp"

int main( void ){	
   
      // wait for the PC console to start
   hwlib::wait_ms( 500 );   
   
   namespace target = hwlib::target;
   
   auto scl     = target::pin_oc( target::pins::scl );
   auto sda     = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 
   
   auto font    = hwlib::font_default_8x8();
   auto display = hwlib::terminal_from( oled, font );
   
   for(;;){
      display 
         << "\f" << "Hello world!" 
         << "\n" << "second line"
         << "\t0305" << "pos 3 line 5"
         << hwlib::flush;   
      hwlib::wait_ms( 1'000 );
      display 
         << "\f" << hwlib::flush;   
      hwlib::wait_ms( 1'000 );
   }         

}
