#include "roll.h"

// Constructor
Roll::Roll(Die& d1, Die& d2) : die1(d1), die2(d2), value(0) {}

// Public member functions
void Roll::roll_die() {
    die1.roll();
    die2.roll();
    value = die1.rolled_value() + die2.rolled_value();
    rolled = true;
}

int Roll::roll_value() const {
    return value;
}