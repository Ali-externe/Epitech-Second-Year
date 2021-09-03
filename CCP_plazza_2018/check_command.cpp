/*
** EPITECH PROJECT, 2019
** plazza
** File description:
** check_command
*/

#include "reception.hpp"

int check_size(std::string size, struct s_struct *s_plazza)
{
    if (size == "s") {
        std::cout << "small" << std::endl;
        s_plazza->size = 1;
        return (0);
    }
    else if (size == "m") {
        std::cout << "medium" << std::endl;
        s_plazza->size = 2;
        return (0);
    }
    else if (size == "l") {
        std::cout << "large" << std::endl;
        s_plazza->size = 3;
        return (0);
    }
    else if (size == "xl") {
        std::cout << "extra large" << std::endl;
        s_plazza->size = 4;
        return (0);
    }
    else if (size == "xxl") {
        std::cout << "extra extra large" << std::endl;
        s_plazza->size = 5;
        return (0);
    }
    else {
        std::cout << "That's not a size" << std::endl;
        return (-1);
    }
}

int check_pizza(std::string pizza, struct s_struct *s_plazza)
{
    if (pizza == "regina") {
        s_plazza->id_pizza = 1;
        std::cout << "\nCool a regina" << std::endl;
        return (0);
    }
    else if (pizza == "margarita") {
        s_plazza->id_pizza = 2;
        std::cout << "\nCool a Margarita" << std::endl;
        return (0);
    }
    else if (pizza == "americana") {
        s_plazza->id_pizza = 3;
        std::cout << "\nCool an Americana" << std::endl;
        return (0);
    }
    else if (pizza == "fantasia") {
        s_plazza->id_pizza = 4;
        std::cout << "\nCool a Fantasia" << std::endl;
        return (0);
    }
    else {
        std::cout << "That's not a pizza" << std::endl;
        return (-1);
    }
}
