#ifndef ROLL_H
#define ROLL_H

#pragma once
#include "die.h"
#include <iostream>

class Roll {
public:
    Roll(Die* d1, Die* d2);

    Roll(int rolledValue);


    void roll_die();
    int rolled_value() const;

private:
    Die* die1;
    Die* die2;
    int value;
    bool rolled;

    friend std::ostream& operator<<(std::ostream& os, const Roll& roll);
};

#endif