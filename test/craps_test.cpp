#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

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

TEST_CASE("Verify Roll Class", "[Roll]") {
    SECTION("RollValueInRange") {
        Die die1;
        Die die2;
        Roll roll(die1, die2);

        for (int i = 0; i < 10; ++i) {
            roll.roll_die();
            int value = roll.roll_value();
            REQUIRE(value >= 2); // Assert value is greater than or equal to 2
            REQUIRE(value <= 12); // Assert value is less than or equal to 12
        }
    }
}

TEST_CASE("Verify Shooter Class", "[Shooter]") {
    SECTION("ThrowDieAndGetRoll") {
        Die die1;
        Die die2;
        Shooter shooter;

        for (int i = 0; i < 10; ++i) {
            Roll* roll = shooter.throw_die(die1, die2);
            int value = roll->roll_value();
            REQUIRE((value >= 2 && value <= 12)); // Assert value is within the expected range
        }

        std::cout << shooter; // Print the rolls using the overloaded << operator
    }
}