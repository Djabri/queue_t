#include <catch.hpp>
#include <sstream>
#include <cassert>
#include "queue.hpp"

TEST_CASE("creating queue")
{
	queue_t<int> q;
	REQUIRE( vector.size() == 0 );
	REQUIRE( vector.capacity() == 0 );
}
