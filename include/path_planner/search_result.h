#pragma once

#include "position.h"

namespace path_planner {

struct SearchResult
{
    Path path{};
    bool pathFound{false};
};

}  // namespace path_planner
