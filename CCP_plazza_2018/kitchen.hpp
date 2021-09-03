/*
** EPITECH PROJECT, 2019
** kitchen
** File description:
** kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

#include "reception.hpp"

class Kitchen : public Reception {
    public:
        Kitchen();
        ~Kitchen();
        void run(struct s_struct *s_plazza);
    protected:
        int nb_ingrts;
        int nb_cooks;
        int time_regina;
        int time_americana;
        int time_fantasia;
        int time_margarita;
};

#endif /* !KITCHEN_HPP_ */
