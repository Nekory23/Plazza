/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Color
*/

#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <string>

/* ENUM */
enum class Commands {
    Command,
    Quit,
    Help,
    Status,
};

/* STATIC CONST */
// Color //
static const std::string RED = "\x1B[31m";
static const std::string BLUE = "\x1B[34m";
static const std::string GREEN = "\x1B[32m";
static const std::string NOR = "\033[0m";
static const std::string BOLD = "\e[1m";
static const std::string NON_BOLD = "\e[0m";

// PRINT //
static const std::string PROMPT = "> ";
static const std::string INVALID = "Error in command format: ";
static const std::string HELP_ERROR = "Pizza Size x[1...9][0...9]*";

// RETURN //
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

#endif /* !COMMAND_HPP_ */
