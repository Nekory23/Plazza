/*
** EPITECH PROJECT, 2021
** B-CCP_ThePlazza
** File description:
** Stock
*/

#ifndef STOCK_HPP_
#define STOCK_HPP_

#include <string>

#include "PizzaData.hpp"

/* CLASS */
class Stock {
    public:
        Stock() noexcept;
        ~Stock() = default;

        bool availableForPizza(int type) noexcept;
        bool getStockForPizza(int type) noexcept;
        void removeIngredient(int elem) noexcept;
        int checkStock(int elem) noexcept;
        void addIngredient() noexcept;
        
        void display() noexcept;
    protected:
        std::pair<int, int> _products[9];
    private:
};

#endif /* !STOCK_HPP_ */