#ifndef DIE_H
#define DIE_H

class Die {
public:
    // Constructor
    Die();

    // Function to roll the die
    void roll();

    // Function to get the rolled value
    int rolled_value() const;

private:
    int roll_value; // Stores a randomly assigned value
    const int sides; // Die sides, initialized to 6
};

#endif