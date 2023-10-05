#include "path_planner/position.h"

#include <path_planner/grid.h>

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <sstream>

using path_planner::Grid;
using path_planner::Obstacles;
using path_planner::Position;

TEST(GridTest, GetHeight)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};

    const auto grid = Grid(height, width);
    EXPECT_EQ(grid.GetHeight(), height);
}

TEST(GridTest, GetWidth)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};

    const auto grid = Grid(height, width);
    EXPECT_EQ(grid.GetWidth(), width);
}

TEST(GridTest, AddObstacles)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};

    Obstacles obstacles = {Position(0, 0), Position(1, 0)};
    const auto grid = Grid(height, width, obstacles);

    std::stringstream stream;
    stream << grid;
    std::string str = stream.str();
    EXPECT_EQ(std::count(str.begin(), str.end(), '#'),
                         obstacles.size());
}
