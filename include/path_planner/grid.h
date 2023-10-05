#pragma once

#include "position.h"

#include <cstdint>
#include <iostream>
#include <vector>

namespace path_planner {

enum class Cell : char
{
    Traversable = ' ',
    Obstacle    = '#'
};

using Obstacles = std::vector<Position>;

class Grid
{
public:
    explicit Grid(std::uint16_t height, std::uint16_t width, Obstacles obstacles = {});

    std::uint16_t GetHeight() const;
    std::uint16_t GetWidth() const;

    bool IsOnGrid(Position pos) const;
    bool IsTraversable(Position pos) const;
    bool IsObstacle(Position pos) const;

    friend std::ostream& operator<<(std::ostream& out, const Grid& grid);

private:
    std::uint16_t m_height;
    std::uint16_t m_width;

    std::vector<std::vector<Cell>> m_cells;
};

}  // namespace path_planner
