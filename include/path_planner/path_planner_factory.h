#pragma once

#include <memory>

namespace path_planner {

class IPathPlanner;

std::unique_ptr<IPathPlanner> CreatePathPlanner();

}  // namespace path_planner
