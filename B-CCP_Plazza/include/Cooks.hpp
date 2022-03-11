/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** Cooks
*/

#ifndef COOKS_HPP_
#define COOKS_HPP_

#include "Kitchen.hpp"

enum CooksState 
{
    Sleeping = 0,
    Cooking
};

class Kitchen;

class Cooks {
    public:
        Cooks(Kitchen *kitchen) noexcept;
        ~Cooks() = default;

        void assign(int type) noexcept;
        void nextStep() noexcept;
        void cookReady(int mult) noexcept;

        int getType() const noexcept;
        int getStep() const noexcept;
        int getState() const noexcept;
        
        void display() const noexcept;
    protected:
        Kitchen *_kitchen;
        int _type;
        int _step;
        int _state;
    private:
};

#endif /* !COOKS_HPP_ */
