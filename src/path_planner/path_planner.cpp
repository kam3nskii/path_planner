#include "path_planner.h"

namespace path_planner {

PathPlanner::PathPlanner(const Grid& grid)
    : m_grid(grid)
{
}

SearchResult PathPlanner::Plan(SearchOptions options)
{
    SearchResult result;

    result.path.push_back(options.start);
    result.path.push_back(options.goal);

    return result;
}

const Grid& PathPlanner::GetGrid() const
{
    return m_grid;
}

}  // namespace path_planner
