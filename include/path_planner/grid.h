#pragma once

#include "position.h"

#include <cstdint>
#include <iostream>
#include <vector>

namespace path_planner {

enum class Cell : char
{
    Traversable = ' ',
    Obstacle = '#',
    PathStep = '*',
};

using Obstacles = std::vector<Position>;

class BaseGrid
{
public:
    explicit BaseGrid(
        std::uint16_t height, std::uint16_t width, Obstacles obstacles = {});

    std::uint16_t GetHeight() const;
    std::uint16_t GetWidth() const;

    bool IsOnGrid(Position pos) const;

    friend BaseGrid CreateGridWithPath(const BaseGrid& grid, const Path& path);
    friend std::ostream& operator<<(std::ostream& out, const BaseGrid& grid);

protected:
    void CheckPosition(Position pos) const;

protected:
    std::uint16_t m_height;
    std::uint16_t m_width;

    std::vector<std::vector<Cell>> m_cells;
};

class Grid : public BaseGrid
{
public:
    explicit Grid(
        std::uint16_t height, std::uint16_t width, Obstacles obstacles = {});

    bool IsTraversable(Position pos) const;
    bool IsObstacle(Position pos) const;

    std::vector<Position> GetTraversableNeighbors(Position pos) const;
};

}  // namespace path_planner
