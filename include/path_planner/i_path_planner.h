#pragma once

#include "search_options.h"
#include "search_result.h"

namespace path_planner {

class IPathPlanner
{
public:
    virtual ~IPathPlanner() = default;

    virtual SearchResult Plan(SearchOptions options) const = 0;
};

}  // namespace path_planner
