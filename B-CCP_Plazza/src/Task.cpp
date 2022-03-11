/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** task
*/

#include <chrono>
#include <iostream>
#include <unistd.h>

#include "Kitchen.hpp"

void *task(void *kitchen)
{
    Kitchen *_kitchen = (Kitchen *) kitchen;
    int resfresh = 0;
    int stepCook = 0;

    while (_kitchen->_isWorking) {
        if (!_kitchen->_pizzasToCook.empty() && _kitchen->_pizzasToCook.at(0).second <= 0)
            _kitchen->_pizzasToCook.erase(_kitchen->_pizzasToCook.begin());
        if (!_kitchen->_pizzasToCook.empty() && _kitchen->_pizzasToCook.at(0).second > 0)
            _kitchen->assignWork();
        usleep(10000);
        resfresh += 10;
        stepCook += 10;
        if (_kitchen->getPlazza()->getRefresh() <= resfresh) {
            _kitchen->refreshStock();
            resfresh = 0;
        }
        if (stepCook >= 1000) {
            if (_kitchen->checkStep())
                _kitchen->_active = 0;
            else if (_kitchen->_active <= 5)
                _kitchen->_active++;
            else
                _kitchen->_isWorking = false;
                stepCook = 0;
        }
    }
    return NULL;
}