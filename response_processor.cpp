#include <vector>
#include <unordered_map>

std::pair<int, std::vector<int>> process_response(const std::vector<int> &oracle_response,
                                                  const std::unordered_map<std::string, int> &card_to_var)
{
    std::pair<int, std::vector<int>> result;
    result.first = 0;
    for (const auto &response : oracle_response)
    {
        if (response > 0)
        {
            result.first++;
            result.second.push_back(response);
        }
    }
    return result;
}
