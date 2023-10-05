#include <path_planner/position.h>

namespace path_planner {

Position::Position(std::uint16_t x, std::uint16_t y)
    : m_x(x)
    , m_y(y)
{
}

std::uint16_t Position::X() const
{
    return m_x;
}

std::uint16_t Position::Y() const
{
    return m_y;
}

bool Position::operator==(const Position& other) const
{
    return ((X() == other.X()) && (Y() == other.Y()));
}

bool Position::operator!=(const Position& other) const
{
    return !(*this == other);
}

}  // namespace path_planner
