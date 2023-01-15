#include <iostream>
#include <vector>

void write_output(const std::pair<int, std::vector<int>> &result)
{
    std::cout << result.first << std::endl;
    for (const auto &package : result.second)
    {
        std::cout << package << " ";
    }
    std::cout << std::endl;
}
