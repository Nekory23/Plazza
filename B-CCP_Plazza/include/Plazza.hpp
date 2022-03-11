/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <pthread.h>

#include "Reception.hpp"
#include "Structure.hpp"
#include "Kitchen.hpp"

/* CLASS */

class Kitchen;

class Plazza {
    public:
        Plazza(std::vector<double> arg) noexcept;
        ~Plazza() noexcept;

        void Run() noexcept;

        void setCommu(commu_t *commu) noexcept;
        void setStack(std::stack<pizzaOrder_t> stack) noexcept;
        void setOrder() noexcept;
        void setReception(Reception *rec) noexcept;

        std::vector<order_t> getOrder() const noexcept;
        std::vector<Kitchen *> getKitchens() const noexcept;
        int getCooks() const noexcept;
        int getRefresh() const noexcept;
        double getMultiplier() const noexcept;

        void updateOrder() noexcept;
        bool orderIsReady() noexcept;
        void removeOrder() noexcept;
        void addKitchen(Kitchen *kitchen) noexcept;
        bool checkKitchens() noexcept;
        void closeKitchens() noexcept;
        
        void DisplayStatus() const noexcept;

        bool _isRunning;
        Reception *_rec;
    protected:
        double _multiplier;
        int _cooks;
        int _refreshTime;
        commu_t *_commu;
        pthread_t _thread;
        std::stack<pizzaOrder_t> _stack;
        std::vector<order_t> _order;
        std::vector<Kitchen *> _kitchens;
    private:
};

#endif /* !PLAZZA_HPP_ */
