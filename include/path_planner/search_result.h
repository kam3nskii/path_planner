#pragma once

#include "position.h"

#include <vector>

namespace path_planner {

using Path = std::vector<Position>;

struct SearchResult
{
    Path path{};
    bool pathFound{false};
};

}  // namespace path_planner
