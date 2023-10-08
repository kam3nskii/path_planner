#pragma once

#include "search_engine.h"

#include <path_planner/grid.h>
#include <path_planner/i_path_planner.h>

#include <memory>

namespace path_planner {

class PathPlanner : public IPathPlanner
{
public:
    explicit PathPlanner(const Grid& grid);

    SearchResult Plan(SearchOptions options) override;

    const Grid& GetGrid() const override;

private:
    const Grid m_grid;
    std::unique_ptr<SearchEngine> m_searchEngine;
};

}  // namespace path_planner
