#include <path_planner/grid.h>

#include <fmt/format.h>

#include <stdexcept>

namespace path_planner {

Grid::Grid(std::uint16_t height, std::uint16_t width, Obstacles obstacles)
    : m_height(height)
    , m_width(width)
{
    m_cells = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell::Traversable));

    for (auto obstacle : obstacles)
    {
        CheckPosition(obstacle);
        m_cells[obstacle.X()][obstacle.Y()] = Cell::Obstacle;
    }
}

std::uint16_t Grid::GetHeight() const
{
    return m_height;
}

std::uint16_t Grid::GetWidth() const
{
    return m_width;
}

bool Grid::IsOnGrid(Position pos) const
{
    if ((pos.X() < GetHeight()) && (pos.Y() < GetWidth()))
    {
        return true;
    }

    return false;
}

bool Grid::IsTraversable(Position pos) const
{
    CheckPosition(pos);

    return (m_cells[pos.X()][pos.Y()] == Cell::Traversable);
}

bool Grid::IsObstacle(Position pos) const
{
    CheckPosition(pos);

    return (m_cells[pos.X()][pos.Y()] == Cell::Obstacle);
}

std::vector<Position> Grid::GetTraversableNeighbors(Position pos) const
{
    CheckPosition(pos);

    std::vector<Position> neighbors;
    neighbors.reserve(4);

    for (std::int16_t i = (pos.X() >= 1) ? -1 : 0; i <= 1; ++i)
    {
        for (std::int32_t j = (pos.Y() >= 1) ? -1 : 0; j <= 1; ++j)
        {
            Position curr(pos.X() + i, pos.Y() + j);

            if ((std::abs(i) + std::abs(j) == 2) || (curr == pos))
            {
                continue;
            }

            if (IsOnGrid(curr) && IsTraversable(curr))
            {
                neighbors.push_back(curr);
            }
        }
    }

    return neighbors;
}

std::ostream& operator<<(std::ostream& out, const Grid& grid)
{
    std::string formatString;
    formatString.reserve((grid.GetHeight() + 2) * (grid.GetWidth() + 3));

    formatString += "┌{0:─^{1}}┐\n";
    for (std::uint16_t i = 0; i < grid.GetHeight(); ++i)
    {
        formatString += "│";
        for (std::uint16_t j = 0; j < grid.GetWidth(); ++j)
        {
            formatString += static_cast<char>(grid.m_cells[i][j]);
        }
        formatString += "│\n";
    }
    formatString += "└{0:─^{1}}┘";

    out << fmt::format(formatString, "", grid.GetWidth());
    return out;
}

void Grid::CheckPosition(Position pos) const
{
    if (!IsOnGrid(pos))
    {
        throw std::runtime_error(
                fmt::format("Position({}, {}) is outside the grid!",
                            pos.X(), pos.Y()));
    }
}

}  // namespace path_planner
