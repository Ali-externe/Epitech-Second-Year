/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** main
*/

#include <thread>
#include <vector>
#include <sys/types.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <mutex>
#include <algorithm>
#include <vector>
#include <map>
#include <chrono>
#include <stdexcept>
#include <thread>
#include <iomanip>
#include <queue>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <tuple>
#include <future>

#pragma once

class Reception
{
    public:
        Reception();
        ~Reception();
    protected:
        int nb_cooks;
};

struct s_struct
{
    std::string name_pizza;

    int time_regina = 2;
    int time_americana = 2;
    int time_fantasia = 4;
    int time_margarita = 1;
    int nb_kitchen = 3;
    int id_pizza = 0;
    double multiplier = 0;
    int cook_p_k = 0;
    int nb_pizza = 0;
    int time_restock = 0;
    std::string input;
    std::string *tab;
    int nb_tab = 0;
    int size = 0;
    int speed = 0;
};

void create_kitchen(struct s_struct *s_plazza);
int check_size(std::string size, struct s_struct *s_plazza);
int check_pizza(std::string pizza, struct s_struct *s_plazza);
void cooks(struct s_struct *s_plazza);
