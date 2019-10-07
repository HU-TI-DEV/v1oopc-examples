#include "ostream"
#include "xy.hpp"

#include "catch.hpp"

bool operator==( xy lhs, xy rhs ){
   return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

TEST_CASE( "constructors, default" ){
   xy v;
   REQUIRE( v == xy( 1, 7 ) );   
}



