#include "hwlib.hpp"

int main( void ){	
      
   // wait for the PC to start the console
   hwlib::wait_ms( 2000 );
   
   hwlib::cout 
      << "cout demo\n"
      << 'd' << "ecimal " << 42 << "\n" 
      << "hexadecimal " << hwlib::hex << 42 << "\n";
   
}
