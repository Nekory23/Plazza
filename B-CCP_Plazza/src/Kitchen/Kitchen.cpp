/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Kitchen
*/

#include <iostream>

#include "Kitchen.hpp"

void *task(void *kitchen);

Kitchen::Kitchen(Plazza *plazza) noexcept
{
    _plazza = plazza;
    _isWorking = false;
    _stock = new Stock();
    _active = 0;
}

Kitchen::~Kitchen() noexcept
{
    for (auto i = 0; i != _cooks.size(); ++i) {
        if (_cooks[i])
            free(_cooks[i]);
    }
    _cooks.clear();
    if (_stock)
        free(_stock);
    pthread_cancel(this->_thread);
}

order_t Kitchen::prepareOrder(order_t order)
{
    std::pair<int, int> pair;
    int nbMaxHandle = getPlazza()->getCooks() * 2;

    for (auto i = 0; i != 4 && nbMaxHandle; ++i) {
        if (!order.pizzaLeft[i].second)
            continue;
        if (nbMaxHandle && nbMaxHandle >= order.pizzaLeft[i].second) {
            pair = order.pizzaLeft[i];
            nbMaxHandle -= order.pizzaLeft[i].second;
            order.pizzaLeft[i].second = 0;
            _pizzasToCook.insert(_pizzasToCook.begin(), pair);
        } else if (nbMaxHandle) {
            pair = order.pizzaLeft[i];
            pair.second = nbMaxHandle;
            order.pizzaLeft[i].second -= nbMaxHandle;
            nbMaxHandle = 0;
            _pizzasToCook.insert(_pizzasToCook.begin(), pair);
        }
    }
    return order;
}

void Kitchen::startToWork() noexcept
{
    prepareCooks();
    _isWorking = true;
    pthread_create(&this->_thread, NULL, task, (void *)this);
    pthread_detach(this->_thread);
}

void Kitchen::refreshStock() noexcept
{
    _stock->addIngredient();
}

bool Kitchen::checkStep() noexcept
{
    int needStep;
    bool work = false;

    if (!_cooks.size()) {
        _active++;
        return false;
    }
    for (auto i = 0; i != _cooks.size(); ++i) {
        if (!_cooks[i]->getState())
            continue;
        work = true;
        needStep = _plazza->getMultiplier() * getMultiPizza(_cooks[i]->getType());
        _cooks[i]->nextStep();
        if (_cooks[i]->getStep() == needStep)
            _cooks[i]->cookReady(needStep);
    }
    return work;
}

void Kitchen::assignWork() noexcept
{
    if (!_cooks.size())
        return;
    for (auto i = 0; i != _cooks.size() && _pizzasToCook.size() && _pizzasToCook.at(0).second; ++i) {
        if (_cooks[i]->getState())
            continue;
        if (!_stock->availableForPizza(_pizzasToCook.at(0).first))
            continue;
        _pizzasToCook.at(0).second--;
        _stock->getStockForPizza(_pizzasToCook.at(0).first);
        _cooks[i]->assign(_pizzasToCook.at(0).first);
    }
}

void Kitchen::pizzaReady(int type) noexcept
{
    _pizzasCookedMutex.lock();
    if (!_pizzasCooked.empty() && _pizzasCooked.at(0).first == type)
        _pizzasCooked.at(0).second += 1;
    else
        _pizzasCooked.insert(_pizzasCooked.begin(), {type-1, 1});
    _pizzasCookedMutex.unlock();
}

int Kitchen::getMultiPizza(int type) noexcept
{
    for (auto i = 0; i != 4; ++i)
        if (type == PizzaRecipeList[i].Type)
            return PizzaRecipeList[i].Time;
    return 1;
}

void Kitchen::displayCooks() const noexcept
{
    std::cout << BLUE << BOLD << "\tPizza(s) queue :"
    << NOR << NON_BOLD << std::endl << std::endl;
    for (auto i = 0; i != _pizzasToCook.size(); ++i) {
        std::cout << "\t\t-" << PizzaNames[_pizzasToCook[i].first - 1].first;
        std::cout << " x" << PizzaNames[_pizzasToCook[i].first - 1].second;
        std::cout << std::endl;
    }
    if (_pizzasToCook.size() == 0)
        std::cout << GREEN << BOLD << "\t\tAll clear !" << NOR << NON_BOLD << std::endl;
    std::cout << std::endl;
    std::cout << BLUE << BOLD << "\tCook(s) :" << NOR << NON_BOLD << std::endl;
    for (auto i = 0; i != _cooks.size(); ++i) {
        std::cout << "\t\t-Cook n°" << i+1 << std::endl;
        std::cout << "\t\t";
        _cooks[i]->display();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}