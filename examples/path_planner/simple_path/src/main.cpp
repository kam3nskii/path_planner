#include <path_planner/i_path_planner.h>
#include <path_planner/path_planner_factory.h>

#include <iostream>

int main()
{
    auto pathPlanner = path_planner::CreatePathPlanner();
    if (!pathPlanner)
    {
        std::cerr << "CreatePathPlanner() failed" << std::endl;
        return 1;
    }

    std::cout << "PathPlanner example started" << std::endl;
}
