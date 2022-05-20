#include "drawable.hpp"

hwlib::ostream & operator<<( hwlib::ostream & lhs, const drawable & rhs ){
    return rhs.print( lhs );
}

bool within( int x, int a, int b ){
    return ( x >= a ) && ( x <= b );
}

drawable::drawable( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size ):
    w( w ),
    location( location ),
    size( size )
	{}  
   
hwlib::ostream & drawable::print( hwlib::ostream & out ) const {
    return out << location << " " << ( location + size );
} 
   
bool drawable::overlaps( const drawable & other ){
   
	bool x_overlap = within( 
		location.x, 
		other.location.x, 
		other.location.x + other.size.x
	) || within( 
		other.location.x, 
		location.x, 
		location.x + size.x
	);
     
	bool y_overlap = within( 
		location.y, 
		other.location.y, 
		other.location.y + other.size.y
	) || within( 
		other.location.y, 
		location.y, 
		location.y + size.y
	);
   
	return x_overlap && y_overlap;
}

