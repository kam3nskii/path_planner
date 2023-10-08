#pragma once

#include <cstdint>
#include <vector>

namespace path_planner {

class Position
{
public:
    explicit Position(std::uint16_t x, std::uint16_t y);

    std::uint16_t X() const;
    std::uint16_t Y() const;

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

private:
    std::uint16_t m_x;
    std::uint16_t m_y;
};

using Path = std::vector<Position>;

}  // namespace path_planner
