#ifndef _MIRROR_HPP
#define _MIRROR_HPP

#include "hwlib.hpp"

class window_mirror : public hwlib::window {
private:

   hwlib::window & w;
   
   void write_implementation( 
      hwlib::xy pos, 
      hwlib::color col
   ) override;
   
public:

   window_mirror( hwlib::window & w ); 
   void clear_implementation( hwlib::color col ) override;
   void flush() override;
   
};

#endif


