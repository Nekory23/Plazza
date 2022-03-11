/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** KitchenGetters
*/

#include "Kitchen.hpp"

Plazza *Kitchen::getPlazza() const noexcept
{
    return _plazza;
}

Stock *Kitchen::getStock()const noexcept
{
    return _stock;
}