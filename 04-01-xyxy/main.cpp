#include "hwlib.hpp"
#include "line_print.hpp"

int main(){
   // the window in which we want to print the line
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );
   
   // print a line by specifying the start x,y and the end x,y
   line_print( w, 10, 10, 20, 20 );
   
   // keep the window around until we close it
   for(;;){ w.poll(); } 
}
