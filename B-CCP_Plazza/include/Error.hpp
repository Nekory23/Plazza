/*
** EPITECH PROJECT, 2021
** B-CCP_ThePlazza
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

/* INCLUDES */
#include <exception>
#include <iostream>
#include <string>

/* CLASS */
class Error : std::exception {
    public:
        Error(std::ostream &os, const std::string &msg) throw();
        virtual ~Error() throw() {};
        const char *what() const throw();

    private:
        std::string _msg;
        std::ostream &_os;
};

#endif /* !ERROR_HPP_ */