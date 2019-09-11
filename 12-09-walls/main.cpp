#include <hwlib.hpp>
#include <array>

// ===========================================================================

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

// ===========================================================================

class line : public drawable {
private:

   hwlib::xy end;
   
public:

   line( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & end ):
      drawable( w, location ),
      end( end )
   {}
   
   void draw(){
      hwlib::line x( location, end );
      x.draw( w );;
   }
};

// ===========================================================================

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
   }
};

// ===========================================================================

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

// ===========================================================================

int main(){
   hwlib::target::window w( hwlib::xy( 128, 64 ), hwlib::white, hwlib::black, 2 );
   line top( w, hwlib::xy(   0,  0 ), hwlib::xy( 127,  0 ) );
   line right( w, hwlib::xy( 127,  0 ), hwlib::xy( 127, 63 ) );
   line bottom( w, hwlib::xy( 127, 63 ), hwlib::xy(   0, 63 ) );
   line left( w, hwlib::xy(   0, 63 ), hwlib::xy(   0,  0 ) );
   ball b( w, hwlib::xy( 10, 10 ), 8, hwlib::xy( 2, 2 ) );
   
   std::array< drawable *, 5 > objects = { &b, &top, &left, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      w.flush();
      hwlib::wait_ms( 100 );
      for( auto & p : objects ){
          p->update();
      }
   }
}

