#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::vector<int>> generate_sat_clauses(const std::vector<std::string> &cards_held,
                                                   const std::vector<std::string> &desired_cards,
                                                   const std::vector<std::vector<std::string>> &packages)
{
    std::unordered_map<std::string, int> card_to_var;
    int var_count = 1;
    for (const auto &card : desired_cards)
    {
        if (card_to_var.find(card) == card_to_var.end())
        {
            card_to_var[card] = var_count++;
        }
    }

    std::vector<std::vector<int>> sat_clauses;

    for (const auto &card : cards_held)
    {
        if (card_to_var.find(card) != card_to_var.end())
        {
            sat_clauses.push_back({-card_to_var[card]});
        }
    }

    for (const auto &package : packages)
    {
        std::vector<int> package_clause;
        for (const auto &card : package)
        {
            if (card_to_var.find(card) != card_to_var.end())
            {
                package_clause.push_back(card_to_var[card]);
            }
        }
        if (!package_clause.empty())
        {
            sat_clauses.push_back(package_clause);
        }
    }

    for (const auto &card : desired_cards)
    {
        if (card_to_var.find(card) != card_to_var.end())
        {
            std::vector<int> card_clause;
            for (const auto &package : packages)
            {
                bool has_card = false;
                for (const auto &package_card : package)
                {
                    if (package_card == card)
                    {
                        has_card = true;
                        break;
                    }
                }
                if (has_card)
                {
                    card_clause.push_back(card_to_var[card]);
                }
            }
            sat_clauses.push_back(card_clause);
        }
    }
    return sat_clauses;
}
