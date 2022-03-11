/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** PlazzaGetters
*/

#include "Plazza.hpp"

std::vector<Kitchen *> Plazza::getKitchens() const noexcept
{
    return _kitchens;
}

int Plazza::getCooks() const noexcept
{
    return _cooks;
}

int Plazza::getRefresh() const noexcept
{
    return _refreshTime;
}

double Plazza::getMultiplier() const noexcept
{
    return _multiplier;
}

std::vector<order_t> Plazza::getOrder() const noexcept
{
    return _order;
}
