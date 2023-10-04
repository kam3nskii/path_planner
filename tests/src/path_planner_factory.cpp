#include <gtest/gtest.h>

#include <path_planner/i_path_planner.h>
#include <path_planner/path_planner_factory.h>

TEST(PathPlannerFactoryTest, CreatePathPlanner)
{
    const auto grid  = path_planner::Grid(42, 42);
    auto pathPlanner = path_planner::CreatePathPlanner(grid);
    EXPECT_NE(pathPlanner, nullptr);
}
