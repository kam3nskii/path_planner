#include "search_vertex.h"

namespace path_planner {

SearchVertex::SearchVertex(Position pos, std::uint32_t gCost, SearchVertex* prev)
    : m_pos(pos)
    , m_prev(prev)
    , m_gCost(gCost)
{
}

Position SearchVertex::Pos() const
{
    return m_pos;
}

SearchVertex* SearchVertex::Prev() const
{
    return m_prev;
}

std::uint32_t SearchVertex::GCost() const
{
    return m_gCost;
}

bool operator==(const SearchVertex& lft, const SearchVertex& rht)
{
    return lft.m_pos == rht.m_pos;
}

bool operator!=(const SearchVertex& lft, const SearchVertex& rht)
{
    return !(lft == rht);
}

bool operator<(const SearchVertex& lft, const SearchVertex& rht)
{
    if (lft.m_gCost < rht.m_gCost)
    {
        return true;
    }

    return lft.m_pos < rht.m_pos;
}

}  // namespace path_planner
