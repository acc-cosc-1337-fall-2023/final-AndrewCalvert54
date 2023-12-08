#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Die Class", "[Die]") {
    SECTION("RollValueInRange") {
        Die die;
        for (int i = 0; i < 10; ++i) {
            die.roll();
            int value = die.rolled_value();
            REQUIRE(value >= 1); // Assert value is greater than or equal to 1
            REQUIRE(value <= 6); // Assert value is less than or equal to 6
        }
    }
}