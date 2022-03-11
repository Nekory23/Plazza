/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Shell
*/

#include <string>
#include <iostream>

#include "Plazza.hpp"
#include "Command.hpp"

static void DisplayHelp() noexcept
{
    std::cout << std::endl;
    std::cout << BLUE << BOLD << "Available commands :" << NOR << NON_BOLD << std::endl;
    std::cout << GREEN << BOLD << "    help:\t" << NOR << NON_BOLD << "Displays this message"<< std::endl;
    std::cout << GREEN << BOLD << "    quit:\t" << NOR << NON_BOLD << "Exit the program"<< std::endl;
    std::cout << GREEN << BOLD << "    status:\t" << NOR << NON_BOLD << "Displays the kitchen's status"<< std::endl;
    std::cout << std::endl;

    std::cout << BLUE << BOLD << "Make an order :" << NOR << NON_BOLD << std::endl;
    std::cout << "    [Pizza Name] [Size] x[Number]" << std::endl << std::endl;
    std::cout << GREEN << BOLD << "Our Pizzas :" << NOR << NON_BOLD << std::endl;
    std::cout << BLUE << BOLD << "    Margarita:" << NOR << NON_BOLD << std::endl;
    std::cout << "\tDoe, tomato and gruyere" << std::endl;
    std::cout << BLUE << BOLD << "    Regina:" << NOR << NON_BOLD << std::endl;
    std::cout << "\tDoe, tomato, gruyere, ham and mushrooms" << std::endl;
    std::cout << BLUE << BOLD << "    Americana:" << NOR << NON_BOLD << std::endl;
    std::cout << "\tDoe, tomato, gruyere and steak" << std::endl;
    std::cout << BLUE << BOLD << "    Fantasia:" << NOR << NON_BOLD << std::endl;
    std::cout << "\tDoe, tomato, eggplant, goat cheese and chief love" << std::endl;
    std::cout << std::endl;

    std::cout << GREEN << BOLD << "Sizes :" << NOR << NON_BOLD << std::endl;
    std::cout << "    S, M, L, XL and XXL" << std::endl;
    std::cout << std::endl;

    std::cout << GREEN << BOLD << "Number :" << NOR << NON_BOLD << std::endl;
    std::cout << "    Any number that is a positive integer (must not be null)" << std::endl;
    std::cout << std::endl;
}

void *shell(void *plazza)
{
    Plazza *_plazza = (Plazza *) plazza;

    while (_plazza->_isRunning) {
        std::cout << PROMPT;
        switch (_plazza->_rec->getInput()) {
        case Commands::Help :
            DisplayHelp();
            break;
        case Commands::Quit :
            _plazza->_isRunning = false;
            break;
        case Commands::Status :
            _plazza->DisplayStatus();
            break;
        case Commands::Command :
            if (_plazza->_rec->checkOrder()) {
                std::cerr << RED << BOLD << INVALID;
                std::cerr << NOR << NON_BOLD << HELP_ERROR << std::endl;
                break;
            }
            _plazza->setStack(_plazza->_rec->getStack());
            _plazza->setOrder();
            break;
        }
    }
    return NULL;
}
