#include <path_planner.h>

#include <path_planner/path_planner_factory.h>

namespace path_planner {

std::unique_ptr<IPathPlanner> CreatePathPlanner()
{
    return std::make_unique<PathPlanner>();
}

}  // namespace path_planner
