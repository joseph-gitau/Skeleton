#ifndef TASK_H_
#define TASK_H_

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <array>
#include <utility>
#include <string>

class Task
{
public:
    virtual ~Task() = default;
    virtual void solve() = 0;
    virtual void read_problem_data() = 0;
    virtual void formulate_oracle_question() = 0;
    virtual void decipher_oracle_answer() = 0;
    virtual void write_answer() = 0;

    /*
     * Stores the files paths as class attributes.
     *
     * @param in_filename:         the file containing the problem input
     * @param oracle_in_filename:  the file containing the oracle input
     * @param oracle_out_filename: the file containing the oracle output
     * @param out_filename:        the file containing the problem output
     */

    /*
     * Asks the oracle for an answer to the formulated question.
     */
    void ask_oracle()
    {
        std::string solver_path = "sat_oracle.py";
        std::string command = "python3 " + solver_path + " sat.cnf sat.sol";
        std::array<char, 512> buffer{};
        std::string output;

        auto pipe = popen(command.c_str(), "r");

        while (!feof(pipe))
        {
            if (fgets(buffer.data(), 512, pipe) != nullptr)
            {
                output += buffer.data();
            }
        }

        auto rc = pclose(pipe);

        if (rc != EXIT_SUCCESS)
        {
            std::cerr << "Error encountered while running oracle" << std::endl;
            std::cerr << output << std::endl;
            exit(-1);
        }
    }
    void read_input()
    {
        int N, M, P;
        std::cin >> N >> M >> P;
        std::vector<std::string> cards_held;
        for (int i = 0; i < N; i++)
        {
            std::string card;
            std::cin >> card;
            cards_held.push_back(card);
        }
        std::set<std::string> desired_cards;
        for (int i = 0; i < M; i++)
        {
            std::string card;
            std::cin >> card;
            desired_cards.insert(card);
        }
        std::vector<std::vector<std::string>> packages;
        for (int i = 0; i < P; i++)
        {
            int package_size;
            std::cin >> package_size;
            std::vector<std::string> package_cards;
            for (int j = 0; j < package_size; j++)
            {
                std::string card;
                std::cin >> card;
                package_cards.push_back(card);
            }
            packages.push_back(package_cards);
        }
        // save the input data in some variable for further processing: packages, cards_held, desired_cards
        vector<vector<string>> packages;
        vector<string> cards_held;
        set<string> desired_cards;
    }
};

#endif // TASK_H_