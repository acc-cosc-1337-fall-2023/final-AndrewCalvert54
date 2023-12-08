#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    // Constructor
    Roll(Die& d1, Die& d2);

    // Public member functions
    void roll_die();
    int roll_value() const;

private:
    // Private member variables
    Die& die1; // Initialize in Roll constructor
    Die& die2; // Initialize in Roll constructor
    bool rolled{false}; // Initialize to false
    int value; // Set to die1 + die2 rolled values
};

#endif