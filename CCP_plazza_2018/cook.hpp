/*
** EPITECH PROJECT, 2019
** Cook
** File description:
** Cook
*/


#ifndef COOK_HPP_
    #define COOK_HPP_

#include "kitchen.hpp"

class Cook : public Kitchen {
	public:
		Cook();
		~Cook();
	private:
        int time;
        bool busy;
        bool trade_run;
};

#endif /* !COOK_HPP_ */
