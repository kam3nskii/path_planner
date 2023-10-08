#pragma once

#include "search_engine.h"
#include "search_vertex.h"

namespace path_planner {

class AStar : public SearchEngine
{
public:
    AStar();

    SearchResult StartSearch(const Grid& grid, SearchOptions options) override;
};

}  // namespace path_planner
