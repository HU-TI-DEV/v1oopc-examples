#include "hwlib.hpp"

class drawable {
protected:

   hwlib::window & w;
   hwlib::xy location;
   
public:

   drawable( hwlib::window & w, const hwlib::xy & location ):
      w( w ),
      location( location )
   {}      
   
   virtual void draw() = 0;
   virtual void update(){}
};

class circle : public drawable {
protected:

   int radius;
 
public:

   circle( hwlib::window & w, const hwlib::xy & midpoint, int radius ):
      drawable( w, midpoint ),
      radius( radius )
   {}
   
   void draw(){
      hwlib::circle c( location, radius );
      c.draw( w );
      w.flush();
   }
};

class ball : public circle {
private:

   hwlib::xy speed;
   
public:

   ball( hwlib::window & w, const hwlib::xy & midpoint, int radius, const hwlib::xy & speed ):
      circle( w, midpoint, radius ),
      speed( speed )  
   {}
   
   void update(){
      location = location + speed; 
   }
};

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