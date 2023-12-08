#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h"
#include <iostream>

class Shooter {
public:
    // Public member functions
    Roll* throw_die(Die& d1, Die& d2);
    friend std::ostream& operator<<(std::ostream& os, const Shooter& shooter);

    // Destructor
    ~Shooter();

private:
    // Private member variables
    std::vector<Roll*> rolls;
};

#endif