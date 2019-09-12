#include "hwlib.hpp"

int main( void ){	
   
   namespace target = hwlib::target;
   
   auto scl     = target::pin_oc( target::pins::scl );
   auto sda     = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c );  

   auto w1 = hwlib::part( 
      oled, 
      hwlib::xy( 0, 0 ),
      hwlib::xy( 128, 32));
   auto w2 = hwlib::part( 
      oled, 
      hwlib::xy( 0, 32 ),
      hwlib::xy( 128, 32));
      
   auto f1 = hwlib::font_default_16x16();
   auto d1 = hwlib::terminal_from( w1, f1 );  
   
   auto f2 = hwlib::font_default_8x8();
   auto d2 = hwlib::terminal_from( w2, f2 );
   
   d1 << "\f"
      << "LASER \nshooter" << hwlib::flush;   
   d2 << "\f"
      << "==============\n"
      << "user: Wouter\n"
      << "score: " << 42 << "\n"
      << "==============\n" << hwlib::flush;     
      
   int n = 0;   
   for(;;){       
      hwlib::wait_ms( 1'000 );
      d1 << "\f" << ++n << hwlib::flush;
      d2 << "\t0502" << ": " << n + 42 << hwlib::flush;
   }
}
