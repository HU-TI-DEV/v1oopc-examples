// example:
// make the window and the four coordinates private

#include "hwlib.hpp"
#include "line_print.hpp"

int main(int argc, char **argv){
    
   // the window in which we want to print the line
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );   
    
   line diagonal_line( w, 10, 10, 40, 40 );
   // diagonal_line.start_x = 7 ; // dit geeft nu een compilatie fout   
   diagonal_line.print();
   
   // keep the window around until we close it
   for(;;){ w.poll(); }   
}
