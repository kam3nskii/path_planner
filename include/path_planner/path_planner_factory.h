#pragma once

#include "grid.h"

#include <memory>

namespace path_planner {

class IPathPlanner;

std::unique_ptr<IPathPlanner> CreatePathPlanner(const Grid& grid);

}  // namespace path_planner
