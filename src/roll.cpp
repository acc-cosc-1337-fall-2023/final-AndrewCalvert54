#include "roll.h"
#include <iostream>

Roll::Roll(Die* d1, Die* d2) : die1(d1), die2(d2), value(0), rolled(false) {}

Roll::Roll(int rolledValue) : die1(nullptr), die2(nullptr), value(rolledValue), rolled(true) {}

void Roll::roll_die() {
    die1->roll();
    die2->roll();
    value = die1->rolled_value() + die2->rolled_value();
    rolled = true;
}

int Roll::rolled_value() const {
    if (die1 && die2) {
        return die1->rolled_value() + die2->rolled_value();
    } else {
        return value;
    }
}

std::ostream& operator<<(std::ostream& os, const Roll& roll) {
    os << "Roll value: " << roll.value;
    return os;
}