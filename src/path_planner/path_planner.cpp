#include "AStar.h"
#include "path_planner.h"

namespace path_planner {

PathPlanner::PathPlanner(const Grid& grid) : m_grid(grid)
{
}

SearchResult PathPlanner::Plan(SearchOptions options)
{
    SearchResult result;

    m_searchEngine = std::make_unique<AStar>();

    return m_searchEngine->StartSearch(m_grid, options);
}

const Grid& PathPlanner::GetGrid() const
{
    return m_grid;
}

}  // namespace path_planner
