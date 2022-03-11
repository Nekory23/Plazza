/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "Structure.hpp"
#include "Command.hpp"

class Reception {
    public:
        Reception() = default;
        ~Reception() = default;

        std::stack<pizzaOrder_t> getStack() const noexcept;
        Commands getInput() noexcept;

        void setOrder() noexcept;
        
        int checkOrder() noexcept;
        bool checkType(std::string value) noexcept;
        bool checkSize(std::string value) noexcept;
    protected:
        std::string _input;
        std::vector<std::string> _order;
        std::vector<int> _pizza;
        std::stack<pizzaOrder_t> _details;
    private:
};

#endif /* !RECEPTION_HPP_ */
