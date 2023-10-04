#include <gtest/gtest.h>

#include <path_planner/grid.h>

#include <cstdint>

TEST(GridTest, GetHeight)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};

    const auto grid = path_planner::Grid(height, width);
    EXPECT_EQ(grid.GetHeight(), height);
}

TEST(GridTest, GetWidth)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};

    const auto grid = path_planner::Grid(height, width);
    EXPECT_EQ(grid.GetWidth(), width);
}
