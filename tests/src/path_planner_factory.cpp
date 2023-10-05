#include <gtest/gtest.h>

#include <path_planner/i_path_planner.h>
#include <path_planner/path_planner_factory.h>

using path_planner::CreatePathPlanner;
using path_planner::Grid;

TEST(PathPlannerFactoryTest, CreatePathPlanner)
{
    const auto grid = Grid(42, 42);
    auto pathPlanner = CreatePathPlanner(grid);
    EXPECT_NE(pathPlanner, nullptr);
}
