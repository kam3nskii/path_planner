#include <path_planner/i_path_planner.h>
#include <path_planner/path_planner_factory.h>

#include <fmt/format.h>

#include <iostream>

int main()
{
    using namespace path_planner;

    std::cout << "PathPlanner example started" << std::endl;

    const path_planner::Grid grid(5, 20,
        {Position(1, 2), Position(2, 3), Position(3, 1), Position(3, 2), Position(3, 3)});
    std::cout << "Grid:\n" << grid << std::endl;

    auto pathPlanner = path_planner::CreatePathPlanner(grid);
    if (!pathPlanner)
    {
        std::cerr << "CreatePathPlanner() failed" << std::endl;
        return 1;
    }

    const auto result = pathPlanner->Plan(SearchOptions(Position(0, 0), Position(0, 1)));
    std::cout << fmt::format("Path {}!", result.pathFound ? "found" : "not found") << std::endl;
}
