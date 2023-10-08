#pragma once

#include <path_planner/grid.h>
#include <path_planner/i_path_planner.h>

namespace path_planner {

class PathPlanner : public IPathPlanner
{
public:
    explicit PathPlanner(const Grid& grid);

    SearchResult Plan(SearchOptions options) override;

    const Grid& GetGrid() const override;

private:
    const Grid m_grid;
};

}  // namespace path_planner
