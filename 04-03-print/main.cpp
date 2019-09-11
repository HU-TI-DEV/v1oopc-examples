// example:
// print a line by passing a line struct 
// that contains the four coordinates
// as in implicit parameter to its member function print()

#include "hwlib.hpp"
#include "line_print.hpp"

int main(int argc, char **argv){
    
   // the window in which we want to print the line
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );    
    
   line diagonal_line = { 10, 10, 40, 40 };
   diagonal_line.print( w );
   
   // keep the window around until we close it
   for(;;){ w.poll(); }   
}
