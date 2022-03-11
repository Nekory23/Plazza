/*
** EPITECH PROJECT, 2021
** B-CCP-400-PAR-4-1-theplazza-quentin.treheux
** File description:
** ReceptionSetters
*/

#include "Reception.hpp"

void Reception::setOrder() noexcept
{
    std::string src = _input;
    std::size_t pos = 0;

    _order.clear();
    while (src.find(' ', 0) != src.npos) {
        pos = src.find(' ', 0);
        if (src.find(';', 0) < src.find(' ', 0))
            pos = src.find(';', 0);
        _order.push_back(src.substr(0, pos));
        if (src[pos] == ';')
            src.erase(0, pos + 2);
        else    
            src.erase(0, pos + 1);
    }
    _order.push_back(src);
}
