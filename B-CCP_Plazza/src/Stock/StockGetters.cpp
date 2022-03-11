/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** StockGetters
*/

#include "Stock.hpp"

bool Stock::getStockForPizza(int type) noexcept
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
    if (!can)
        return (false);
    for (auto i = 0; recipe.Elems[i] != EMPTY; i++)
        removeIngredient(recipe.Elems[i]);
    return (true);
}
