#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> read_cards(int n)
{
    std::vector<std::string> cards;
    for (int i = 0; i < n; i++)
    {
        std::string card;
        std::getline(std::cin, card);
        cards.push_back(card);
    }
    return cards;
}

std::vector<std::vector<std::string>> read_packages(int n)
{
    std::vector<std::vector<std::string>> packages;
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;
        std::cin.ignore();
        std::vector<std::string> package = read_cards(m);
        packages.push_back(package);
    }
    return packages;
}

void read_input(std::vector<std::string> &cards_held, std::vector<std::string> &desired_cards, std::vector<std::vector<std::string>> &packages)
{
    int n, m, p;
    std::cin >> n >> m >> p;
    std::cin.ignore();
    cards_held = read_cards(n);
    desired_cards = read_cards(m);
    packages = read_packages(p);
}
