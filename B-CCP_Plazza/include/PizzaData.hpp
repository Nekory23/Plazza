/*
** EPITECH PROJECT, 2021
** plazza
** File description:
** PizzaData
*/

#ifndef PIZZADATA_HPP_
#define PIZZADATA_HPP_

#include <stack>

static const int pizzaLen = 4;
static const int sizeLen = 5;
static const int maxContentLen = 6;

enum PizzaType
{
    Nil = 0,
    Regina = 1,
    Margarita = 2,
    Americana = 3,
    Fantasia = 4
};

enum PizzaSize
{
    O = 0,
    S = 1,
    M = 2,
    L = 3,
    XL = 4,
    XXL = 5
};

enum PizzaContent
{
    EMPTY = -1,
    DOE = 0,
    TOMATO = 1,
    GRUYERE = 2,
    HAM = 3,
    MUSHROOMS = 4,
    STEAK = 5,
    EGGPLANT = 6,
    GOAT_CHEESE = 7,
    CHIEF_LOVE = 8,
};

typedef struct pizzaRecipe_s {
    PizzaType Type;
    PizzaContent Elems[maxContentLen];
    int Time;
} pizzaRecipe_t;

static std::pair<const char *, PizzaSize> SizeNames[] =
{
    { "S", S },
    { "M", M },
    { "L", L },
    { "XL", XL },
    { "XXL", XXL },
    { "", O }
};

static std::pair<const char *, PizzaType> PizzaNames[] =
{
    { "regina", Regina },
    { "margarita", Margarita },
    { "americana", Americana },
    { "fantasia", Fantasia },
    { "", Nil }
};

static std::pair<const char *, PizzaContent> ElemsNames[] =
{
    { "doe", DOE },
    { "tomato", TOMATO },
    { "gruyere", GRUYERE },
    { "ham", HAM },
    { "mushrooms", MUSHROOMS },
    { "steak", STEAK },
    { "eggplant", EGGPLANT },
    { "goat cheese", GOAT_CHEESE },
    { "chief love", CHIEF_LOVE },
    { "", EMPTY }
};

static pizzaRecipe_t PizzaRecipeList[] =
{
    { Regina, { DOE, TOMATO, GRUYERE, HAM, MUSHROOMS, EMPTY }, 2 },
    { Margarita, { DOE, TOMATO, GRUYERE, EMPTY }, 1 },
    { Americana, { DOE, TOMATO, GRUYERE, STEAK, EMPTY }, 2},
    { Fantasia, { DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE, EMPTY}, 4},
    { Nil, { EMPTY } }
};

#endif /* !PIZZADATA_HPP_ */
