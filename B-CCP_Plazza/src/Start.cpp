/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** Start
*/

#include <iostream>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include <sys/wait.h>
#include <cstring>

#include "Error.hpp"
#include "Plazza.hpp"

std::vector<double> ErrorHandling(int ac, char **av, std::vector<double> &values);

static int DisplayHelp(char *progName) noexcept
{
    std::cout << " _____  _                    " << std::endl;
    std::cout << "|  __ \\| |                   " << std::endl;
    std::cout << "| |__) | | __ _ __________ _ " << std::endl;
    std::cout << "|  ___/| |/ _` |_  /_  / _` |" << std::endl;
    std::cout << "| |    | | (_| |/ / / / (_| |" << std::endl;
    std::cout << "|_|    |_|\\__,_/___/___\\__,_|" << std::endl << std::endl;
    std::cout << "USAGE" << std::endl;
    std::cout << "\t" << progName << " [multiplier] [cooks] [time]" << std::endl;
    std::cout << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tmultiplier\tmultiplies the cooking time of the pizzas (must be a positive number)" << std::endl;
    std::cout << "\tcooks\t\tnumber of cooks per kitchen (must be a positive integer)" << std::endl;
    std::cout << "\ttime\t\ttime to refill the ingredients in milliseconds (must be a positive integer)" << std::endl;
    return SUCCESS;
}

static int printError(std::string func) noexcept
{
    perror(func.c_str());
    return ERROR;
}

int Start(int ac, char **av)
{
    int pid = 0;
    int memid = 0;
    commu_t *commu = NULL;
    std::vector<double> arg;

    if (ac == 2 && !strcmp(av[1], "-h"))
        return DisplayHelp(av[0]);
    pid = fork();
    memid = shmget(0x00042473, sizeof(commu_t), 0700 | IPC_CREAT);
    if (memid < 0)
        return printError("shmget");
    if (pid < 0)
        return printError("fork");
    commu = (commu_t *)shmat(memid, NULL, 0);
    try {
        arg = ErrorHandling(ac, av, arg);
    }
    catch (Error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return ERROR;
    }
    catch (...) {}
    Plazza plazza(arg);
    plazza.setCommu(commu);
    if (pid == 0)
        return SUCCESS;
    plazza.Run();
    wait(NULL);
    return SUCCESS;
}