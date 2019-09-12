#include "hwlib.hpp"
#include "mirror.hpp"

int main( void ){	
      
   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  
   
   auto mirrored = window_mirror( display );
     
   hwlib::graphics_random_circles( mirrored );
}
