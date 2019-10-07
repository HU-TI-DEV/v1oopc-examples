#include "ostream"
#include "xy.hpp"

#include "catch.hpp"

bool operator==( xy lhs, xy rhs ){
   return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

std::ostream & operator<<( std::ostream & lhs, xy rhs ){
   return lhs << "(" << rhs.x << "," << rhs.y << ")";
}

TEST_CASE( "constructors, two_parameters" ){
   xy v( 3, 4 );
   REQUIRE( v.x == 3 );   
   REQUIRE( v.y == 4 );   
}

TEST_CASE( "constructors, default" ){
   xy v;
   REQUIRE( v == xy( 0, 0 ) );   
}


