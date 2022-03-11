/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Structure
*/

#ifndef STRUCTURE_HPP_
#define STRUCTURE_HPP_

#include <vector>
#include <stack>

typedef struct commu_s
{
    int instruction;
    int val;
    int type;
    int size;
    int delay;
} commu_t;

typedef struct pizzaOrder_s
{
    int type;
    int size;
    int quantity;
} pizzaOrder_t;

typedef struct order_s
{
    std::vector<std::pair<int, int>> pizzaToCook;
    std::vector<std::pair<int, int>> pizzaLeft;
    std::vector<std::pair<int, int>> pizzaCooked;
    std::stack<pizzaOrder_t> details;
} order_t;

#endif /* !STRUCTURE_HPP_ */
