#pragma once

#include "position.h"

namespace path_planner {

struct SearchOptions
{
    explicit SearchOptions(const Position& start, const Position& goal)
        : start(start), goal(goal)
    {
    }

    Position start;
    Position goal;
};

}  // namespace path_planner
