#pragma once

#include <path_planner/grid.h>
#include <path_planner/search_options.h>
#include <path_planner/search_result.h>

namespace path_planner {

class SearchEngine
{
public:
    virtual ~SearchEngine() = default;

    virtual SearchResult StartSearch(const Grid& grid, SearchOptions options) = 0;
};

}  // namespace path_planner
