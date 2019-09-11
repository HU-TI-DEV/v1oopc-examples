#include "mirror.hpp"

window_mirror::window_mirror( hwlib::window & w ): 
   window( hwlib::xy( w.size.x / 2, w.size.y ), hwlib::white, hwlib::black ),
   w( w )
{}

void window_mirror::write_implementation( 
   hwlib::xy pos, 
   hwlib::color col
){
   w.write( pos, col );
   w.write( hwlib::xy( ( w.size.x - 1 ) - pos.x, pos.y ), col );
}

void window_mirror::clear_implementation( hwlib::color col ){
   w.clear( col ); 
}

void window_mirror::flush(){
   w.flush();   
}



