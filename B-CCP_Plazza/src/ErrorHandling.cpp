/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** ErrorHandling
*/

#include <vector>

#include "Error.hpp"

std::vector<double> ErrorHandling(int ac, char **av, std::vector<double> &values)
{
    if (ac != 4)
        throw Error(std::cerr, "This program must take 3 arguments (see with -h)");
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] == '.')
            continue;
        if (av[1][i] < '0' || av[1][i] > '9')
            throw Error(std::cerr, "the multiplier must be a positive number (see with -h)");
    }
    for (int i = 0; av[2][i] != '\0'; i++)
        if (av[2][i] < '0' || av[2][i] > '9')
            throw Error(std::cerr, "the number of cooks be a positive number (see with -h)");
    for (int i = 0; av[3][i] != '\0'; i++)
        if (av[3][i] < '0' || av[3][i] > '9')
            throw Error(std::cerr, "the time be a positive number (see with -h)");
    for (int i = 1; i != ac; i++)
        values.push_back(std::atof(av[i]));
    return values;
}