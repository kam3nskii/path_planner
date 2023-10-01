#pragma once

#include <string>

namespace path_planner {

class IPathPlanner
{
public:
    virtual ~IPathPlanner() = default;
};

}  // namespace path_planner
