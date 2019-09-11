// example:
// print a line by (explicitly) passing a line struct 
// that contains the four coordinates

#include "hwlib.hpp"
#include "line_print.hpp"

int main(int argc, char **argv){
    
   // the window in which we want to print the line
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );
   
   // print a line by specifying the coordinates in a struct
   line diagonal_line = { 10, 10, 40, 20 };
   line_print( w, diagonal_line );
   
   // keep the window around until we close it
   for(;;){ w.poll(); }
}
   
