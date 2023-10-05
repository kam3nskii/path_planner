#pragma once

#include <cstdint>

namespace path_planner {

class Position
{
public:
    explicit Position(std::uint16_t x, std::uint16_t y);

    std::uint16_t X() const;

    std::uint16_t Y() const;

private:
    std::uint16_t m_x;
    std::uint16_t m_y;
};

}  // namespace path_planner
