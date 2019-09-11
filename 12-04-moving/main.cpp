#include "hwlib.hpp"

class circle {
protected:

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

class ball : public circle {
private:
   hwlib::xy speed;
public:
   ball( hwlib::window & w, const hwlib::xy & midpoint, int radius, const hwlib::xy & speed );
   void update();
};

void ball::update(){
   midpoint = midpoint + speed; // no compiler error
}

ball::ball( hwlib::window & w, const hwlib::xy & midpoint, int radius, const hwlib::xy & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

int main(int argc, char **argv){
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );
   ball b( w, hwlib::xy( 10, 10 ), 8, hwlib::xy( 2, 2 ));   
   for(;;){
      w.clear();
      b.draw();
      hwlib::wait_ms( 100 );
      b.update();
   }
   
   for(;;){ w.poll(); } 
}


