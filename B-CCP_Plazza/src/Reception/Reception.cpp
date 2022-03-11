/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Reception
*/

#include <iostream>

#include "Reception.hpp"
#include "Pizza.hpp"

bool Reception::checkType(std::string value) noexcept
{
   for (int i = 0; type[i].typeString.c_str() != NULL; ++i)
        if (!value.compare(type[i].typeString)) {
            _pizza.push_back(type[i].type);
            return true;
        }
    return false;
}

bool Reception::checkSize(std::string value) noexcept
{
    for (int i = 0; size[i].sizeString.c_str() != NULL; ++i)
        if (!value.compare(size[i].sizeString)) {
            _pizza.push_back(size[i].size);
            return true;
        }
    return false;
}

int Reception::checkOrder() noexcept
{
    pizzaOrder_t elem;

    for (auto i = 0; i < _order.size(); i += 3) {
        if (!checkType(_order[i]) || !checkSize(_order[i + 1]) || _order[i + 2][0] != 'x')
            return FAIL;
        _order[i + 2].erase(0, 1);
        if (_order[i + 2].empty() || _order[i + 2].c_str() == NULL)
            return FAIL;
        for (auto j = 0; j != _order[i + 2].size(); ++j)
            if (_order[i + 2][j] < '0' || _order[i + 2][j] > '9')
                return FAIL;
        if (std::stoi(_order[i + 2]) < 1)
            return FAIL;
        else
            _pizza.push_back(std::stoi(_order[i + 2]));
        elem.type = _pizza[i];
        elem.size = _pizza[i + 1];
        elem.quantity = _pizza[i + 2];
        switch (elem.size)
        {
        case 4:
            elem.size = 3;
            break;
        case 8:
            elem.size = 4;
            break;
        case 16:
            elem.size = 5;
            break;
        default:
            break;
        }
        switch (elem.type)
        {
        case 4:
            elem.type = 3;
            break;
        case 8:
            elem.type = 4;
            break;
        default:
            break;
        }
        _details.push(elem);
        _pizza.clear();
    }
    return SUCCESS;
}