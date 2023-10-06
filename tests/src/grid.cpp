#include "path_planner/position.h"

#include <path_planner/grid.h>

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <sstream>
#include <stdexcept>

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

TEST(GridTest, PosOnGrid)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};

    const auto grid = Grid(height, width);
    for (std::uint16_t i = 0; i < height; ++i)
    {
        for (std::uint16_t j = 0; j < width; ++j)
        {
            Position currPos(i, j);
            EXPECT_TRUE(grid.IsOnGrid(currPos));
            EXPECT_FALSE(grid.IsObstacle(currPos));
            EXPECT_TRUE(grid.IsTraversable(currPos));
            EXPECT_NO_THROW(Grid(height, width, {currPos}));
        }
    }
}

TEST(GridTest, PosOutsideGrid)
{
    constexpr uint16_t height{2};
    constexpr uint16_t width{3};
    constexpr uint16_t delta{5};

    const auto grid = Grid(height, width);
    for (std::uint16_t i = 0; i < height; ++i)
    {
        for (std::uint16_t j = width; j < width + delta; ++j)
        {
            Position currPos(i, j);
            EXPECT_FALSE(grid.IsOnGrid(currPos));
            EXPECT_THROW(grid.IsObstacle(currPos), std::runtime_error);
            EXPECT_THROW(grid.IsTraversable(currPos), std::runtime_error);
            EXPECT_THROW(grid.GetTraversableNeighbors(currPos), std::runtime_error);
            EXPECT_THROW(Grid(height, width, {currPos}), std::runtime_error);
        }
    }
    for (std::uint16_t i = height; i < height + delta; ++i)
    {
        for (std::uint16_t j = 0; j < width; ++j)
        {
            Position currPos(i, j);
            EXPECT_FALSE(grid.IsOnGrid(currPos));
            EXPECT_THROW(grid.IsObstacle(currPos), std::runtime_error);
            EXPECT_THROW(grid.IsTraversable(currPos), std::runtime_error);
            EXPECT_THROW(grid.GetTraversableNeighbors(currPos), std::runtime_error);
            EXPECT_THROW(Grid(height, width, {currPos}), std::runtime_error);
        }
    }
    for (std::uint16_t i = height; i < height + delta; ++i)
    {
        for (std::uint16_t j = width; j < width + delta; ++j)
        {
            Position currPos(i, j);
            EXPECT_FALSE(grid.IsOnGrid(currPos));
            EXPECT_THROW(grid.IsObstacle(currPos), std::runtime_error);
            EXPECT_THROW(grid.IsTraversable(currPos), std::runtime_error);
            EXPECT_THROW(grid.GetTraversableNeighbors(currPos), std::runtime_error);
            EXPECT_THROW(Grid(height, width, {currPos}), std::runtime_error);
        }
    }
}

TEST(GridTest, CheckObstacles)
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

    for (std::uint16_t i = 0; i < grid.GetHeight(); ++i)
    {
        for (std::uint16_t j = 0; j < grid.GetWidth(); ++j)
        {
            Position currPos(i, j);
            const auto it = std::find(obstacles.begin(), obstacles.end(), currPos);

            if (it != obstacles.end())
            {
                EXPECT_TRUE(grid.IsObstacle(currPos));
                EXPECT_FALSE(grid.IsTraversable(currPos));
            }
            else
            {
                EXPECT_FALSE(grid.IsObstacle(currPos));
                EXPECT_TRUE(grid.IsTraversable(currPos));
            }
        }
    }
}

TEST(GridTest, GetTraversableNeighbors)
{
    constexpr uint16_t MaxNeighborsCount{4};

    constexpr uint16_t height{5};
    constexpr uint16_t width{7};

    Obstacles obstacles = {
        Position(1, 1), Position(1, 5), Position(3, 1), Position(3, 5)
    };
    const auto grid = Grid(height, width, obstacles);
    for (std::uint16_t i = 0; i < grid.GetHeight(); ++i)
    {
        for (std::uint16_t j = 0; j < grid.GetWidth(); ++j)
        {
            Position currPos(i, j);

            for (auto pos : grid.GetTraversableNeighbors(currPos))
            {
                EXPECT_TRUE(grid.IsTraversable(pos));
                EXPECT_FALSE(grid.IsObstacle(pos));
            }
        }
    }

    const auto grid2 = Grid(height, width);
    for (std::uint16_t i = 1; i < grid2.GetHeight() - 1; ++i)
    {
        for (std::uint16_t j = 1; j < grid2.GetWidth() - 1; ++j)
        {
            Position currPos(i, j);
            const auto neighbors = grid2.GetTraversableNeighbors(currPos);

            EXPECT_EQ(neighbors.size(), MaxNeighborsCount);

            for (auto pos : neighbors)
            {
                EXPECT_TRUE(grid2.IsTraversable(pos));
                EXPECT_FALSE(grid2.IsObstacle(pos));
            }
        }
    }
}
