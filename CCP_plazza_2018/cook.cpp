/*
** EPITECH PROJECT, 2019
** cook
** File description:
** cook
*/

#include "cook.hpp"

Cook::Cook() {
    this->time = 0;
    this->busy = false;
    this->trade_run = false;
}

Cook::~Cook() {

}

void pizza_regina(struct s_struct *s_plazza)
{
    if (s_plazza->multiplier == 0)
        s_plazza->multiplier = 0.0001;
    int speed = s_plazza->multiplier * 2;
    std::this_thread::sleep_for (std::chrono::seconds(speed));
    std::cout << "Regina Ready" << std::endl;
}

void pizza_margarita(struct s_struct *s_plazza)
{
    if (s_plazza->multiplier == 0)
        s_plazza->multiplier = 0.0001;
    int speed = s_plazza->multiplier * 1;
    std::this_thread::sleep_for (std::chrono::seconds(speed));
    std::cout << "Margarita Ready" << std::endl;
}

void pizza_americana(struct s_struct *s_plazza)
{
    if (s_plazza->multiplier == 0)
        s_plazza->multiplier = 0.0001;
    int speed = s_plazza->multiplier * 2;
    std::this_thread::sleep_for (std::chrono::seconds(speed));
    std::cout << "Americana Ready" << std::endl;
}

void pizza_fantasia(struct s_struct *s_plazza)
{
    if (s_plazza->multiplier == 0)
        s_plazza->multiplier = 0.0001;
    int speed = s_plazza->multiplier * 4;
    std::this_thread::sleep_for (std::chrono::seconds(speed));
    std::cout << "Fantasia Ready" << std::endl;
}

void cooking(struct s_struct *s_plazza)
{
    std::mutex mutex;

    mutex.lock();
    switch (s_plazza->id_pizza)
    {
        case 1:
            pizza_regina(s_plazza);
            break;
        case 2:
            pizza_margarita(s_plazza);
            break;
        case 3:
            pizza_americana(s_plazza);
            break;
        case 4:
            pizza_fantasia(s_plazza);
            break;
    
        default:
            break;
    }
    mutex.unlock();
}

void cooks(struct s_struct *s_plazza)
{
    using namespace std::chrono_literals;

    int cook = s_plazza->cook_p_k;
    static int i = 0;
    std::mutex mutex;
    std::thread th[cook];
    int nb = 1;

    if (i == s_plazza->cook_p_k) {
        i = 0;
    }

    /*while (i != cook) {
        th[i] = std::thread(cooking, s_plazza);
        th[i].join();
        i++;
    }*/
    
    //while (i != cook) {
            th[i] = std::thread(cooking, s_plazza);
            th[i].join();
      //  i++;
   // }
}