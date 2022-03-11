/*
** EPITECH PROJECT, 2021
** B-CCP_ThePlazza
** File description:
** Stock
*/

#include <iostream>

#include "Stock.hpp"
#include "Command.hpp"

Stock::Stock() noexcept
{
    for (auto i = 0; i != 9; ++i) {
        std::pair<int, int> pair = {i, 5};
        _products[i] = pair;
    }
}

bool Stock::availableForPizza(int type) noexcept
{
    bool can = true;
    pizzaRecipe_t recipe = { Nil };

    for (auto i = 0; PizzaRecipeList[i].Type != Nil; i++)
        if (PizzaRecipeList[i].Type == type) {
            recipe = PizzaRecipeList[i];
            break;
        }
    if (recipe.Type == Nil)
        return (false);
    for (auto i = 0; recipe.Elems[i] != EMPTY; i++)
        if (checkStock(recipe.Elems[i]) <= 0)
            can = false;
    return can;
}

int Stock::checkStock(int elem) noexcept
{
    if (elem >= 0 && elem <= 8)
        return _products[elem].second;
    else
        return -1;
}

void Stock::display() noexcept
{
    std::cout << BLUE << BOLD << "\tAvailable stock :" << NOR << NON_BOLD << std::endl;
    for (int i = DOE; i <= CHIEF_LOVE; ++i) {
        if (_products[i].second == 0)
            std::cout << RED << "\t\t" << ElemsNames[i].first << ": " << _products[i].second << NOR << std::endl;
        else
            std::cout << "\t\t" << ElemsNames[i].first << ": " << _products[i].second << std::endl;
    }
    std::cout << std::endl;
}