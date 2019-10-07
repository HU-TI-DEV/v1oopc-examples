#include "ostream"
#include "xy.hpp"

#include "catch.hpp"

bool operator==( xy lhs, xy rhs ){
   return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

std::ostream & operator<<( std::ostream & lhs, xy pos ){
   lhs << "(" << pos.x << "," << pos.y << ")";
   return lhs;
}

TEST_CASE( "constructors, default" ){
   xy v;
   REQUIRE( v == xy( 1, 7 ) );   
}


