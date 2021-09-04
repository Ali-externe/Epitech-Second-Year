/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_ncurse3
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/ncurse.hpp"
#include <curses.h>
#include <string.h>

void ncurse::create_map(int size_rect1, int size_rect2, int pos1, int pos2)
{
    return;
}

void ncurse::move_hero(std::string name, float timing)
{
    int key = getch();  // sleep or clock

    if (key == 27) {
        this->end = 0;
        this->close_window();
    }
    for (int i = 0; this->mapentity[i] != nullptr; i++) {
        for(int x = 0; this->mapentity[i][x] != '\0'; x++) {
            if (this->mapentity[i][x] == 'P') {
                if (key == KEY_UP) {
                    if (i != 0) {
                        if (this->mapentity[i - 1][x] == 'G') {
                            this->end = 0;
                            endwin();
                            this->game_over();
                            exit (0);
                        }
                        if (mapitem[i - 1][x] == ' ') {
                            this->mapentity[i][x] = ' ';
                            this->mapentity[i - 1][x] = 'P';
                            this->move_ghost();
                            return;
                        }
                        else if (mapitem[i - 1][x] == 'B') {
                            this->mapentity[i][x] = ' ';
                            this->mapentity[i - 1][x] = 'P';
                            this->mapitem[i - 1][x] = ' ';
                            this->score += 100;
                            this->move_ghost();
                            this->addBonusRandom();
                            return;
                        }
                        else {
                            this->move_ghost();
                            return;
                        }
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                else if (key == KEY_RIGHT) {
                    if (this->mapentity[i][x + 1] == 'G') {
                            this->end = 0;
                            endwin();
                            this->game_over();
                            exit (0);
                    }
                    if (mapitem[i][x + 1] == ' ') {
                        this->mapentity[i][x] = ' ';
                        this->mapentity[i][x + 1] = 'P';
                        this->move_ghost();
                        return;
                    }
                    else if (mapitem[i][x + 1] == 'B') {
                        this->mapentity[i][x] = ' ';
                        this->mapentity[i][x + 1] = 'P';
                        this->mapitem[i][x + 1] = ' ';
                        this->score += 100;
                        this->move_ghost();
                        this->addBonusRandom();
                        return;
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                else if (key == KEY_DOWN) {
                    if (mapentity[i + 1] != nullptr) {
                        if (this->mapentity[i + 1][x] == 'G') {
                            this->end = 0;
                            endwin();
                            this->game_over();
                            exit (0);
                        }
                        if (mapitem[i + 1][x] == ' ') {
                            this->mapentity[i][x] = ' ';
                            this->mapentity[i + 1][x] = 'P';
                            this->move_ghost();
                            return;
                        }
                        else if (mapitem[i + 1][x] == 'B') {
                            this->mapentity[i][x] = ' ';
                            this->mapentity[i + 1][x] = 'P';
                            this->mapitem[i + 1][x] = ' ';
                            this->score += 100;
                            this->move_ghost();
                            this->addBonusRandom();
                            return;
                        }
                        else {
                            this->move_ghost();
                            return;
                        }
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                else if (key == 'g') {
                    this->end = 2;
                    clear();
                    endwin();
                    std::string next_lib = this->chooselib();
                    change_lib(next_lib);
                    return;
                }
                else if (key == KEY_LEFT) {
                    if (this->mapentity[i][x - 1] == 'G') {
                            this->end = 0;
                            endwin();
                            this->game_over();
                            exit (0);
                    }
                    if (mapitem[i][x - 1] == ' ') {
                        this->mapentity[i][x] = ' ';
                        this->mapentity[i][x - 1] = 'P';
                        this->move_ghost();
                        return;
                    }
                    else if (mapitem[i][x - 1] == 'B') {
                        this->mapentity[i][x] = ' ';
                        this->mapentity[i][x - 1] = 'P';
                        this->mapitem[i][x - 1] = ' ';
                        this->score += 100;
                        this->move_ghost();
                        this->addBonusRandom();
                        return;
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
            }
        }
    }
}

void ncurse::collision_shape(std::string name)
{
    return;
}

void ncurse::create_map2d(int x, int y)
{
    this->mapitem = (char **)malloc(sizeof(char *) * (y + 1));
    this->mapentity = (char **)malloc(sizeof(char *) * (y + 1));
    this->final_map = (char **)malloc(sizeof(char *) * (y + 1));
    this->mapitem[y] = nullptr;
    this->mapentity[y] = nullptr;
    this->final_map[y] = nullptr;
    for (int i = 0; i != y; i++) {
        this->mapitem[i] = (char *)malloc(sizeof(char) * (x + 1));
        this->mapitem[i][x] = '\0';
        for (int a = 0; a != x; a++) {
            this->mapitem[i][a] = ' ';
        }
        this->mapentity[i] = strdup(this->mapitem[i]);
        this->final_map[i] = strdup(this->mapitem[i]);
    }
}

void ncurse::addObstacle(int x, int y)
{
    if (this->mapitem == nullptr) {
        printf("Error placing Obstacle but map uninitialized.\n");
        exit(84);
    }
    if (this->mapitem[y - 1] == nullptr) {
        printf("Error placing Obstacle out of Map.\n");
        exit(84);
    }
    if (x -1 < 0) {
        printf("Error placing Obstacle out of Map.\n");
        exit(84);
    }
    if (this->mapitem[y - 1][x - 1] == '\0') {
        printf("Error placing Obstacle out of Map.\n");
        exit(84);
    }
    this->mapitem[y - 1][x - 1] = 'o';
}
