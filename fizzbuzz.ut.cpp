#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fizzbuzz.hpp"

TEST_CASE("Test with zero", "[classic]") {
    REQUIRE(fizzbuzz(0) == "0");
}

