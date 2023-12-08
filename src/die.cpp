#include "die.h"
#include <cstdlib> // For rand and srand functions
#include <ctime>   // For time function

// Constructor
Die::Die() : sides(6) {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    // Initialize roll_value with a default value
    roll_value = 1;
}

// Function to roll the die
void Die::roll() {
    // Generate a random value between 1 and 6
    roll_value = rand() % sides + 1;
}

// Function to get the rolled value
int Die::rolled_value() const {
    return roll_value;
}