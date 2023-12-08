#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int rollValue = roll->rolled_value();

    if (rollValue == point) {
        return RollOutcome::point;
    } else if (rollValue == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}