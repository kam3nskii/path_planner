#include "path_planner.h"

namespace path_planner {

PathPlanner::PathPlanner(const Grid& grid)
    : m_grid(grid)
{
}

SearchResult PathPlanner::Plan(SearchOptions options) const
{
    SearchResult result;

    result.path.push_back(options.start);
    result.path.push_back(options.goal);

    return result;
}

}  // namespace path_planner
