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
        if (!IsOnGrid(obstacle))
        {
            throw std::runtime_error(
                fmt::format("Position({}, {}) is outside grid!",
                            obstacle.X(), obstacle.Y()));
        }

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
    if (!IsOnGrid(pos))
    {
        throw std::runtime_error(
                fmt::format("Position({}, {}) is outside grid!",
                            pos.X(), pos.Y()));
    }

    return (m_cells[pos.X()][pos.Y()] == Cell::Traversable);
}

bool Grid::IsObstacle(Position pos) const
{
    if (!IsOnGrid(pos))
    {
        throw std::runtime_error(
                fmt::format("Position({}, {}) is outside grid!",
                            pos.X(), pos.Y()));
    }

    return (m_cells[pos.X()][pos.Y()] == Cell::Obstacle);
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

}  // namespace path_planner
