#pragma once

#include <path_planner/position.h>

namespace path_planner {

struct SearchVertex
{
    explicit SearchVertex(Position pos, std::uint32_t gCost, SearchVertex* prev);

    Position Pos() const;

    SearchVertex* Prev() const;

    std::uint32_t GCost() const;

    friend bool operator==(const SearchVertex& lft, const SearchVertex& rht);
    friend bool operator!=(const SearchVertex& lft, const SearchVertex& rht);
    friend bool operator<(const SearchVertex& lft, const SearchVertex& rht);

private:
    Position m_pos;
    SearchVertex* m_prev{nullptr};

    std::uint32_t m_gCost;
};

}  // namespace path_planner
