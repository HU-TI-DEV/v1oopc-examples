#include "hwlib.hpp"

class circle {
private:
   hwlib::window & w;
   hwlib::xy midpoint;
   int radius;
 
public:

   circle( hwlib::window & w, const hwlib::xy & midpoint, int radius ):
      w( w ),
      midpoint( midpoint ),
      radius( radius )
   {}
   
   void draw(){
      hwlib::circle c( midpoint, radius );
      c.draw( w );
      w.flush();
   }
};

class ball {
private:
   hwlib::window & w;
   hwlib::xy midpoint;
   int radius;
   hwlib::xy speed;
public:
   ball( hwlib::window & w, hwlib::xy midpoint, int radius, hwlib::xy speed );
   void draw();
   void update();
};

void ball::update(){
   midpoint = midpoint + speed;
}

ball::ball( hwlib::window & w, hwlib::xy midpoint, int radius, hwlib::xy speed ):
   w( w ),
   midpoint( midpoint ),
   radius( radius ),
   speed( speed )
{}

void ball::draw(){
   circle c( w, midpoint, radius );
   c.draw();
}


int main(int argc, char **argv){
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );
   
   ball b( w, hwlib::xy( 30, 30 ), 20, hwlib::xy( 10, 20 ) );
   b.draw();
   b.update();
   b.draw();
   
   for(;;){ w.poll(); } 
}
