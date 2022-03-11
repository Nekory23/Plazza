/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Cooks
*/

#include <iostream>
#include "Cooks.hpp"

Cooks::Cooks(Kitchen *kitchen) noexcept
{
    _kitchen = kitchen;
    _state = 0;
    _type = -1;
    _step = -1;
}

void Cooks::assign(int type) noexcept
{
    _type = type;
    _state = Cooking;
    _step = 0;
}

void Cooks::nextStep() noexcept
{
    _step++;
}

void Cooks::cookReady(int mult) noexcept
{
    _kitchen->pizzaReady(_type);
    _step = 0;
    _type = -1;
    _state = 0;
}

void Cooks::display() const noexcept
{
    if (_state == Sleeping)
        std::cout << GREEN << "Waiting" << NOR;
    else {
        int remain = _kitchen->getMultiPizza(_type) - _step;
        std::cout << RED << "Cooking a " << PizzaNames[_type - 1].first;
        std::cout << " Remain " << remain << " Elapsed " << _step << "s" << NOR;
    }
}