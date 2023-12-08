#include <iostream>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include "phase.h"

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create instances of Die and Shooter
    Die die1;
    Die die2;
    Shooter shooter;

    // Create a pointer to Roll and set it to the return value of the shooter throw_die function
    Roll* roll = shooter.throw_die(die1, die2);

    // Create a ComeOutPhase instance
    ComeOutPhase come_out_phase;

    // Loop while the outcome is natural or craps
    while (true) {
        RollOutcome outcome = come_out_phase.get_outcome(roll);
        // Display the rolled value and text
        std::cout << "Rolled " << roll->rolled_value() << " - ";

        if (outcome == RollOutcome::natural) {
            std::cout << "Natural - End of come-out phase" << std::endl;
            break;
        } else if (outcome == RollOutcome::craps) {
            std::cout << "Craps - End of come-out phase" << std::endl;
            break;
        } else {
            std::cout << "Roll again" << std::endl;
        }

        // Set roll equal to the return value of the shooter throw_die function
        roll = shooter.throw_die(die1, die2);
    }

    // Display the start of the point phase
    std::cout << "Start of point phase" << std::endl;

    // Create an int point variable and set it to roll's rolled_value
    int point = roll->rolled_value();

    // Set roll equal to the return value of the shooter throw_die function
    roll = shooter.throw_die(die1, die2);

    // Create an instance of PointPhase
    PointPhase point_phase(point);

    // Loop while the outcome is point or notpoint
    while (true) {
        RollOutcome outcome = point_phase.get_outcome(roll);
        // Display the rolled value and text
        std::cout << "Rolled " << roll->rolled_value() << " - ";

        if (outcome == RollOutcome::point) {
            std::cout << "Point - End of point phase" << std::endl;
            break;
        } else if (outcome == RollOutcome::seven_out) {
            std::cout << "Seven out - End of point phase" << std::endl;
            break;
        } else {
            std::cout << "Roll again" << std::endl;
        }

        // Set roll equal to the return value of the shooter throw_die function
        roll = shooter.throw_die(die1, die2);
    }

    // Use cout to display the shooter variable
    std::cout << "Shooter: " << shooter << std::endl;

    return 0;
}