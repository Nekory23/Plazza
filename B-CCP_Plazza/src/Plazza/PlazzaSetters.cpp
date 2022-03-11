/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** PlazzaSetters
*/

#include "Pizza.hpp"
#include "Plazza.hpp"

void Plazza::setReception(Reception *rec) noexcept
{
    _rec = rec;
}

void Plazza::setCommu(commu_t *commu) noexcept
{
    _commu = commu;
}

void Plazza::setStack(std::stack<pizzaOrder_t> stack) noexcept
{
    _stack = stack;
}

void Plazza::setOrder() noexcept
{
    order_t tmp;

    tmp.pizzaToCook = {
        {IPizza::Regina, 0},
        {IPizza::Margarita, 0},
        {IPizza::Americana, 0},
        {IPizza::Fantasia, 0}
    };
    tmp.pizzaLeft = {
        {IPizza::Regina, 0},
        {IPizza::Margarita, 0},
        {IPizza::Americana, 0},
        {IPizza::Fantasia, 0}
    };
    tmp.pizzaCooked = {
        {IPizza::Regina, 0},
        {IPizza::Margarita, 0},
        {IPizza::Americana, 0},
        {IPizza::Fantasia, 0}
    };
    tmp.details = _stack;
    while(!_stack.empty()) {
        tmp.pizzaLeft[_stack.top().type - 1].second += _stack.top().quantity;
        tmp.pizzaToCook[_stack.top().type - 1].second += _stack.top().quantity;
        _stack.pop();
    }
    _order.push_back(tmp);
}
