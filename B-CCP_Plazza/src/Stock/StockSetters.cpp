/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** StockSetters
*/

#include "Stock.hpp"

void Stock::addIngredient() noexcept
{
    for (auto i = 0; i != 9; ++i)
        _products[i].second += 1;
}

void Stock::removeIngredient(int elem) noexcept
{
    if (elem >= 0 && elem <= 8)
        _products[elem].second -= 1;
}
