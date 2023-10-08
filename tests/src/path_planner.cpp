#include <path_planner/i_path_planner.h>
#include <path_planner/path_planner_factory.h>

#include <fmt/format.h>
#include <gtest/gtest.h>

using path_planner::CreatePathPlanner;
using path_planner::Grid;
using path_planner::Position;
using path_planner::SearchOptions;

TEST(PathPlannerTest, PlanSimplePath)
{
    const auto grid = Grid(2, 3);
    auto pathPlanner = CreatePathPlanner(grid);
    EXPECT_NE(pathPlanner, nullptr);

    const auto result =
        pathPlanner->Plan(SearchOptions(Position(0, 0), Position(0, 1)));
}
