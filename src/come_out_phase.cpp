#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    int rollValue = roll->rolled_value();

    if (rollValue == 7 || rollValue == 11) {
        return RollOutcome::natural;
    } else if (rollValue == 2 || rollValue == 3 || rollValue == 12) {
        return RollOutcome::craps;
    } else {
        return RollOutcome::point;
    }
}