#include <path_planner/i_path_planner.h>
#include <path_planner/path_planner_factory.h>

#include <fmt/format.h>

#include <iostream>

int main()
{
    using namespace path_planner;

    std::cout << "PathPlanner example started" << std::endl;

    const Grid grid(5, 20,
        {Position(1, 2), Position(2, 3), Position(3, 1), Position(3, 2), Position(3, 3)});
    std::cout << "Starting grid:\n" << grid << std::endl;

    auto pathPlanner = CreatePathPlanner(grid);
    if (!pathPlanner)
    {
        std::cerr << "CreatePathPlanner() failed" << std::endl;
        return 1;
    }

    auto result = pathPlanner->Plan(SearchOptions(Position(0, 0), Position(4, 3)));
    std::cout << fmt::format("Path {}!", result.pathFound ? "found" : "not found") << std::endl;
    if (result.pathFound)
    {
        std::cout << "Grid with path:\n"
                  << CreateGridWithPath(pathPlanner->GetGrid(), result.path)
                  << std::endl;
    }
}
