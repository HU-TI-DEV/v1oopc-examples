#include "hwlib.hpp"

// hwlib::sttring<0> is de abstracte superklasse van alle string<N>'s
void f( const hwlib::string<0> & s ){

   hwlib::cout << "[";
    
   // iteren over de chars
   for( const auto c : s ){    
      hwlib::cout << c;       
   }

   hwlib::cout << "]";

   // maximale lengte opvragen
   hwlib::cout << " max=" << s.max_size() << "\n";
}

int main( void ){	
   
   // wait for the PC to start the console
   hwlib::wait_ms( 1000 );
   
   hwlib::cout << "String demo\n";
   
   // een string maken en initializeren
   hwlib::string< 32 > s = "Hello world";
   hwlib::cout << s << "\n";
   
   // je kan achteraan dingen toeveogen
   s += ",";
   s << " nice" << " to" << " see" << " you.";
   hwlib::cout << s << "\n";
   
   // wat niet past wordt genegeerd
   s = "Een boterham met chocopasta is lekker.";
   hwlib::cout << s << "\n";
   
   // je kan letters opvragen en wijzigen
   s[ 0 ] = s[ 1 ];
   hwlib::cout << s << "\n";
   
   // een string doorgeven als parameter
   f( s );
   hwlib::string< 10 > w = "Wouter";
   f( w );
   
}
