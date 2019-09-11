#include "hwlib.hpp"

class line {
private:    

   hwlib::window & w;
   int start_x;
   int start_y; 
   int end_x;
   int end_y;

public:

   line( 
       hwlib::window & w,
       int p_start_x, int p_start_y, 
       int p_end_x, int p_end_y 
   ): 
      w( w )
   {
      start_x = p_start_x;
      start_y = p_start_y;
      end_x   = p_end_x;
      end_y   = p_end_y;
   }
   
   void print();

   // move the line
   void shift( int x, int y ){
      start_x += x;
      start_y += y;
      end_x += x;
      end_y += y;
   }
};


void line::print(){
   hwlib::line line( 
   hwlib::xy( start_x, start_y), 
   hwlib::xy( end_x, end_y ) );
   line.draw( w );
   w.flush();
}

int main(int argc, char **argv){
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );    
    
   line diagonal_line( w, 10, 10, 40, 20 );
   diagonal_line.print();
   
   diagonal_line.shift( 50, 5 );
   diagonal_line.print();
   
   for(;;){ w.poll(); }
}
