#ifndef SHOOTER_H
#define SHOOTER_H

#pragma once
#include "roll.h"
#include <vector>

class Shooter {
public:
    ~Shooter(); // Destructor to clean up allocated Roll objects

    Roll* throw_die(Die& d1, Die& d2);

    friend std::ostream& operator<<(std::ostream& os, const Shooter& shooter);

private:
    std::vector<Roll*> rolls;
};

#endif