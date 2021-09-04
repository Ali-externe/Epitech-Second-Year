/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_ncurse2
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/ncurse.hpp"
#include <curses.h>

void ncurse::close_window()
{
    clear();
    refresh();
    endwin();
    if (this->end == 0) {
        this->game_over();
    }
    return;
}

void ncurse::draw_sprite()
{
    return;
}

void ncurse::draw_shape()
{
    return;
}

void ncurse::set_animation(std::string name, float time, int inc, int reset)
{
    return;
}

void ncurse::clear_window()
{
    refresh();
}