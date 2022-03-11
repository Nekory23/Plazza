/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Plazza
*/

#include <fstream>
#include <iostream>
#include <ctime>

#include "Plazza.hpp"
#include "Reception.hpp"
#include "Pizza.hpp"

void *shell(void *plazza);
void *compute(void *plazza);

Plazza::Plazza(std::vector<double> arg) noexcept
{
    _multiplier = arg[0];
    _cooks = arg[1];
    _refreshTime = arg[2];
}

Plazza::~Plazza() noexcept
{
    while (!_kitchens.empty()) {
        if (!_kitchens.at(0))
            break;
        _kitchens.at(0) = NULL;
        delete(_kitchens.at(0));
        _kitchens.erase(_kitchens.begin());
    }
    _order.clear();
    pthread_cancel(_thread);
}

void Plazza::Run() noexcept
{
    Reception rec;

    _isRunning = true;
    setReception(&rec);
    pthread_create(&this->_thread, NULL, shell, (void *)this);
    compute(this);
    _isRunning = false;
}

void Plazza::updateOrder() noexcept
{
    if (_kitchens.empty())
        return;
    for (auto i = 0; i < _kitchens.size(); ++i) {
        _kitchens.at(i)->_pizzasCookedMutex.lock();
        while (!_kitchens.at(i)->_pizzasCooked.empty()) {
            std::pair<int, int> pair = _kitchens.at(i)->_pizzasCooked.at(0);
            _order[0].pizzaCooked[pair.first].second += pair.second;
            _kitchens.at(i)->_pizzasCooked.erase(_kitchens.at(i)->_pizzasCooked.begin());
        }
        _kitchens.at(i)->_pizzasCookedMutex.unlock();
    }
}

bool Plazza::orderIsReady() noexcept
{
    int a = 0;
    int b = 0;

    if (!_order.size())
        return false;
    for (auto i = 0; i != 4; ++i) {
        a = _order[0].pizzaCooked[i].second;
        b = _order[0].pizzaToCook[i].second;
        if (a != b)
            return false;
    }
    return true;
}

void Plazza::removeOrder() noexcept
{
    std::time_t result = std::time(nullptr);

    if (!_order.size())
        return;
    std::ofstream logs("logs.txt", std::ios::app);
    logs << std::asctime(std::localtime(&result)) << std::endl;
    std::cout << "An order is ready" << std::endl;
    while (!_order[0].details.empty()) {
        std::cout << "\t" << PizzaNames[_order[0].details.top().type - 1].first;
        std::cout << " " << SizeNames[_order[0].details.top().size - 1].first;
        std::cout << " x" << _order[0].details.top().quantity << std::endl;
        logs << "\t" << PizzaNames[_order[0].details.top().type - 1].first
            << " " << SizeNames[_order[0].details.top().size - 1].first
            << " x" << _order[0].details.top().quantity << std::endl;
        _order[0].details.pop();
    }
    logs << std::endl;
    logs.close();
    _order.erase(_order.begin());
}

void Plazza::addKitchen(Kitchen *kitchen) noexcept
{
    _kitchens.push_back(kitchen);
}

bool Plazza::checkKitchens() noexcept
{
    for (auto i = 0; i != _kitchens.size(); ++i) {
        if (_kitchens[i] && !_kitchens[i]->_isWorking) {
            Kitchen *tmp = _kitchens[i];
            _kitchens.erase(_kitchens.begin() + i);
            tmp = NULL;
            delete(tmp);
            return true;
        }
    }
    return false;
}

void Plazza::closeKitchens() noexcept
{
    for (auto i = 0; i != _kitchens.size(); ++i)
        if (_kitchens[i]) {
            _kitchens[i]->_isWorking = false;
            _kitchens[i] = NULL;
            delete(_kitchens[i]);
        }
}

void Plazza::DisplayStatus() const noexcept
{
    std::cout << std::endl << BLUE << BOLD << "Order(s) status :" << NOR << NON_BOLD << std::endl << std::endl;
    for (auto i = 0; i != _order.size(); ++i) {
        std::cout << "\t-Order n°" << i << std::endl;
        for (auto p = 0; p != 4; ++p) {
            if (!_order[i].pizzaToCook[p].second)
                continue;
            std::cout << "\t" << PizzaNames[p].first << " ";
            std::cout << _order[i].pizzaCooked[p].second << " / " << _order[i].pizzaToCook[p].second << std::endl;
        }
        std::cout << std::endl;
    }
    if (_order.size() == 0)
        std::cout << GREEN << BOLD << "\tAll clear !" << NOR << NON_BOLD << std::endl << std::endl;
    std::cout << BLUE << BOLD << "Kitchen(s) status :" << NOR << NON_BOLD << std::endl << std::endl;
    for (auto i = 0; i != _kitchens.size(); ++i) {
        std::cout << BLUE << BOLD << "Kitchen n°" << i + 1 << NOR << NON_BOLD << std::endl << std::endl;
        _kitchens[i]->getStock()->display();
        _kitchens[i]->displayCooks();
        std::cout << std::endl;
    }
    if (_kitchens.size() == 0)
        std::cout << GREEN << BOLD << "\tAll kitchens are closed." << NOR << NON_BOLD << std::endl << std::endl;
}