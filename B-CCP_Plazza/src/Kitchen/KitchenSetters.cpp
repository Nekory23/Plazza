/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** KitchenSetters
*/

#include "Kitchen.hpp"

void Kitchen::stopToWork() noexcept
{
    _isWorking = false;
}

void Kitchen::prepareCooks() noexcept
{
    for (auto i = 0; i != getPlazza()->getCooks(); ++i)
        _cooks.push_back(new Cooks(this));
}