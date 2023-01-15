// Your First C++ Program

#include <iostream>
#include <task.h>

int main()
{
    std::vector<std::vector<int>> formulate_clauses(const std::vector<std::string> &cards_held, const std::set<std::string> &desired_cards, const std::vector<std::vector<std::string>> &packages);
    {
        std::vector<std::vector<int>> clauses;
        // map of card name to its corresponding clause
        std::map<std::string, std::vector<int>> card_clauses;
        // map of package number to its corresponding variable
        std::map<int, int> package_vars;
        // create a variable for each package
        for (int i = 0; i < packages.size(); i++)
        {
            package_vars[i] = i + 1;
        }
        // create a clause for each card in the desired collection
        for (const std::string &card : desired_cards)
        {
            if (std::find(cards_held.begin(), cards_held.end(), card) == cards_held.end())
            {
                std::vector<int> card_clause;
                for (int i = 0; i < packages.size(); i++)
                {
                    if (std::find(packages[i].begin(), packages[i].end(), card) != packages[i].end())
                    {
                        card_clause.push_back(package_vars[i]);
                    }
                }
                if (!card_clause.empty())
                {
                    card_clauses[card] = card_clause;
                }
            }
        }
        // create a clause that represents the conjunction of the clauses for each card
        std::vector<int> conjunction_clause;
        for (const auto &[card, card_clause] : card_clauses)
        {
            for (int var : card_clause)
            {
                conjunction_clause.push_back(var);
            }
        }
        clauses.push_back(conjunction_clause);
        // create clauses that represent the negation of the conjunction of two packages for each card
        for (const auto &[card, card_clause] : card_clauses)
        {
            for (int i = 0; i < card_clause.size(); i++)
            {
                for (int j = i + 1; j < card_clause.size(); j++)
                {
                    clauses.push_back({-card_clause[i], -card_clause[j]});
                }
            }
        }
        // create a clause that represents the disjunction of all the packages
        std::vector<int> disjunction_clause;
        for (const auto &[package, var] : package_vars)
        {
            disjunction_clause.push_back(var);
        }
        clauses.push_back(disjunction_clause);
        return clauses;
    }
}
