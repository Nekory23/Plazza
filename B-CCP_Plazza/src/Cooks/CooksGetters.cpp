/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** CooksGetters
*/

#include "Cooks.hpp"

int Cooks::getType() const noexcept
{
    return _type;
}

int Cooks::getStep() const noexcept
{
    return _step;
}

int Cooks::getState() const noexcept
{
    return _state;
}
