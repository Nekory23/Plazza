/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Compute
*/

#include <iostream>

#include "Plazza.hpp"

static bool orderIsEmpty(order_t order)
{
    bool empty = false;

    for (auto i = 0; i != 4; ++i) {
        if (!order.pizzaLeft[i].second)
            empty = true;
        else
            return false;
    }
    return empty;
}

order_t prepareKitchen(Plazza *_plazza, order_t order)
{
    for (auto i = 0; i != _plazza->getKitchens().size(); ++i)
        order = _plazza->getKitchens()[i]->prepareOrder(order);
    if (orderIsEmpty(order))
        return order;
    while (!orderIsEmpty(order)) {
        Kitchen *kitchen = new Kitchen(_plazza);
        order = kitchen->prepareOrder(order);
        _plazza->addKitchen(kitchen);
        kitchen->startToWork();
    }
    return order;
}

void *compute(void *plazza)
{
    Plazza *_plazza = (Plazza *) plazza;
    std::vector<order_t> tmp;
    order_t current;

    while (_plazza->_isRunning) {
        while (_plazza->checkKitchens());
        tmp = _plazza->getOrder();
        if (!tmp.size())
            continue;
        _plazza->updateOrder();
        if (_plazza->orderIsReady())
            _plazza->removeOrder();
        else if (!_plazza->getKitchens().size()) {
            current = _plazza->getOrder()[0];
            if (!_plazza->orderIsReady())
                current = prepareKitchen(_plazza, current);
        }
    }
    _plazza->closeKitchens();
    return NULL;
}