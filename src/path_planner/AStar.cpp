#include "AStar.h"

namespace path_planner {

AStar::AStar()
{
}

SearchResult AStar::StartSearch(const Grid& grid, SearchOptions options)
{
    SearchResult result;

    grid.IsOnGrid(options.start);
    grid.IsOnGrid(options.goal);

    result.path.push_back(options.start);
    result.path.push_back(options.goal);

    return result;
}

}  // namespace path_planner
