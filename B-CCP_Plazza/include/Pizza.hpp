/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include <string>

class IPizza 
{
    public:
        enum PizzaType {
            Regina = 1,
            Margarita = 2,
            Americana = 4,
            Fantasia = 8,
            NullType = 0
        };

        enum PizzaSize {
            S = 1,
            M = 2,
            L = 4,
            XL = 8,
            XXL = 16,
            NullSize = 0
        };
        ~IPizza() = default;
};

typedef struct type_s
{
    std::string typeString;
    IPizza::PizzaType type;
} type_t;

static const type_t type[] =
{
    {"regina", IPizza::PizzaType::Regina},
    {"margarita", IPizza::PizzaType::Margarita},
    {"americana", IPizza::PizzaType::Americana},
    {"fantasia", IPizza::PizzaType::Fantasia}
};

typedef struct sizePizza_s
{
    std::string sizeString;
    IPizza::PizzaSize size;
} sizePizza_t;

static const sizePizza_t size[] =
{
    {"S", IPizza::PizzaSize::S},
    {"M", IPizza::PizzaSize::M},
    {"L", IPizza::PizzaSize::L},
    {"XL", IPizza::PizzaSize::XL},
    {"XXL", IPizza::PizzaSize::XXL}
};

#endif /* !PIZZA_HPP_ */
