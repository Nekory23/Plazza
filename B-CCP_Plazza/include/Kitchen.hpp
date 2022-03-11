/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <mutex>
#include <pthread.h>

#include "Plazza.hpp"
#include "Cooks.hpp"
#include "Stock.hpp"

enum KitchenState 
{
       Full,
       Work,
       Waiting
};

class Plazza;
class Cooks;

class Kitchen {
    public:
        Kitchen(Plazza *plazza) noexcept;
        ~Kitchen() noexcept;

        order_t prepareOrder(order_t order);
        void startToWork() noexcept;
        void stopToWork() noexcept;

        void prepareCooks() noexcept;
        void refreshStock() noexcept;
        bool checkStep() noexcept;
        void assignWork() noexcept;
        void pizzaReady(int type) noexcept;

        Plazza *getPlazza() const noexcept;
        Stock *getStock()const noexcept;
        int getMultiPizza(int type) noexcept;

        void displayCooks() const noexcept;

        std::mutex _pizzasCookedMutex;
        std::vector<std::pair<int, int>> _pizzasCooked;
        std::vector<std::pair<int, int>> _pizzasToCook;
        bool _isWorking;
        int _active;
    protected:
        Plazza *_plazza;
        pthread_t _thread;
        std::vector<Cooks *> _cooks;
        Stock *_stock;

    private:
};

#endif /* !KITCHEN_HPP_ */
