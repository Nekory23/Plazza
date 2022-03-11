/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** ReceptionGetters
*/

#include <iostream>
#include "Reception.hpp"

std::stack<pizzaOrder_t> Reception::getStack() const noexcept
{
    return _details;
}

Commands Reception::getInput() noexcept
{
    _input.clear();
    std::getline(std::cin, _input);
    if (std::cin.eof() == true)
        return Commands::Quit;
    if (!_input.compare("status"))
        return Commands::Status;
    if (!_input.compare("quit"))
        return Commands::Quit;
    if (!_input.compare("help"))
        return Commands::Help;
    setOrder();
    return Commands::Command;
}