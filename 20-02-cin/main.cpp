#include "hwlib.hpp"

int main( void ){	
   
   // wait for the PC to start the console
   hwlib::wait_ms( 2000 );
   
   hwlib::cout << "cin demo\n";
   
   for(;;){
      char c;
      hwlib::cin >> c;    
      hwlib::cout 
         << "[0x" << hwlib::hex << (int) c << "] "
         << c << "\n";
   }
   
}
