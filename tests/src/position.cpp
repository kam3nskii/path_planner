#include <path_planner/position.h>

#include <gtest/gtest.h>

#include <cstdint>

using path_planner::Position;

TEST(PositionTest, GetCoordinates)
{
    constexpr uint16_t x{2};
    constexpr uint16_t y{3};

    const auto pos = Position(x, y);
    EXPECT_EQ(pos.X(), x);
    EXPECT_EQ(pos.Y(), y);
}
