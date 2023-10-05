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

TEST(PositionTest, EqualPositions)
{
    const auto pos1 = Position(1, 2);
    const auto pos2 = Position(1, 2);

    EXPECT_EQ(pos1, pos1);
    EXPECT_EQ(pos1, pos2);
}

TEST(PositionTest, NotEqualPositions)
{
    const auto pos1 = Position(1, 1);
    const auto pos2 = Position(1, 2);
    const auto pos3 = Position(2, 1);
    const auto pos4 = Position(2, 2);

    EXPECT_NE(pos1, pos2);
    EXPECT_NE(pos1, pos3);
    EXPECT_NE(pos1, pos4);
    EXPECT_NE(pos2, pos3);
    EXPECT_NE(pos2, pos4);
    EXPECT_NE(pos3, pos4);
}
