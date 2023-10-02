#include "path_planner.h"

#include <path_planner/path_planner_factory.h>

namespace path_planner {

std::unique_ptr<IPathPlanner> CreatePathPlanner(const Grid& grid)
{
    return std::make_unique<PathPlanner>(grid);
}

}  // namespace path_planner
