#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <hwlib.hpp>

class drawable {
protected:

	hwlib::window & w;
	hwlib::xy location;
	hwlib::xy size;
   
public:

	drawable( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size );    
   
	virtual void draw() = 0;
	virtual void update(){}
	bool overlaps( const drawable & other );   
	virtual void interact( drawable & other ){}
   
	hwlib::ostream & print( hwlib::ostream & out ) const;      
};

#endif //DRAWABLE_HPP
