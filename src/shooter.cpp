#include "shooter.h"
#include <iostream>

// Public member functions
Roll* Shooter::throw_die(Die& d1, Die& d2) {
    // Create a Roll object on the heap
    Roll* roll = new Roll(&d1, &d2);

    // Roll the dice
    roll->roll_die();

    // Store the Roll object in the vector
    rolls.push_back(roll);

    return roll;
}

std::ostream& operator<<(std::ostream& os, const Shooter& shooter) {
    for (const Roll* roll : shooter.rolls) {
        os << *roll << std::endl;
    }
    return os;
}

// Destructor
Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}