/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** game
*/

#include "../include/interface.hpp"
#include <iostream>
#include <dlfcn.h>
#define MAP_X 21
#define MAP_Y 19

void create_border(arcade *borne)
{
    for (int y = 1; y != MAP_Y + 1; y++) {
        for (int x = 1; x != MAP_X + 1; x++) {
            if (y == 1)
                borne->addObstacle(x, y);
            if (y == 19)
                borne->addObstacle(x, y);
            if (x == 1)
                borne->addObstacle(x, y);
            if (x == 21)
                borne->addObstacle(x, y);
        }
    }
    borne->addObstacle(3, 3);
    borne->addObstacle(4, 3);
    borne->addObstacle(6, 2);
    borne->addObstacle(6, 3);
    borne->addObstacle(8, 3);
    borne->addObstacle(9, 3);
    borne->addObstacle(10, 3);
    borne->addObstacle(11, 3);
    borne->addObstacle(12, 3);
    borne->addObstacle(13, 3);
    borne->addObstacle(14, 3);
    borne->addObstacle(16, 2);
    borne->addObstacle(16, 3);
    borne->addObstacle(18, 3);
    borne->addObstacle(19, 3);
    borne->addObstacle(2, 5);
    borne->addObstacle(4, 5);
    borne->addObstacle(6, 5);
    borne->addObstacle(7, 5);
    borne->addObstacle(8, 5);
    borne->addObstacle(11, 5);
    borne->addObstacle(14, 5);
    borne->addObstacle(15, 5);
    borne->addObstacle(16, 5);
    borne->addObstacle(18, 5);
    borne->addObstacle(20, 5);
    borne->addObstacle(4, 6);
    borne->addObstacle(11, 6);
    borne->addObstacle(18, 6);
    borne->addObstacle(2, 7);
    borne->addObstacle(4, 7);
    borne->addObstacle(5, 7);
    borne->addObstacle(6, 7);
    borne->addObstacle(8, 7);
    borne->addObstacle(9, 7);
    borne->addObstacle(10, 7);
    borne->addObstacle(11, 7);
    borne->addObstacle(12, 7);
    borne->addObstacle(13, 7);
    borne->addObstacle(14, 7);
    borne->addObstacle(16, 7);
    borne->addObstacle(17, 7);
    borne->addObstacle(18, 7);
    borne->addObstacle(20, 7);
    borne->addObstacle(2, 8);
    borne->addObstacle(20, 8);
    borne->addObstacle(2, 9);
    borne->addObstacle(4, 9);
    borne->addObstacle(5, 9);
    borne->addObstacle(6, 9);
    borne->addObstacle(16, 9);
    borne->addObstacle(17, 9);
    borne->addObstacle(18, 9);
    borne->addObstacle(20, 9);
    borne->addObstacle(2, 10);
    borne->addObstacle(4, 10);
    borne->addObstacle(18, 10);
    borne->addObstacle(20, 10);
    borne->addObstacle(20, 10);
    borne->addObstacle(2, 11);
    borne->addObstacle(4, 11);
    borne->addObstacle(6, 11);
    borne->addObstacle(16, 11);
    borne->addObstacle(18, 11);
    borne->addObstacle(20, 11);
    borne->addObstacle(6, 12);
    borne->addObstacle(16, 12);
    borne->addObstacle(2, 13);
    borne->addObstacle(4, 13);
    borne->addObstacle(5, 13);
    borne->addObstacle(6, 13);
    borne->addObstacle(7, 13);
    borne->addObstacle(8, 13);
    borne->addObstacle(11, 13);
    borne->addObstacle(14, 13);
    borne->addObstacle(15, 13);
    borne->addObstacle(16, 13);
    borne->addObstacle(17, 13);
    borne->addObstacle(18, 13);
    borne->addObstacle(20, 13);
    borne->addObstacle(2, 14);
    borne->addObstacle(11, 14);
    borne->addObstacle(20, 14);
    borne->addObstacle(2, 15);
    borne->addObstacle(4, 15);
    borne->addObstacle(5, 15);
    borne->addObstacle(6, 15);
    borne->addObstacle(8, 15);
    borne->addObstacle(9, 15);
    borne->addObstacle(10, 15);
    borne->addObstacle(11, 15);
    borne->addObstacle(12, 15);
    borne->addObstacle(13, 15);
    borne->addObstacle(14, 15);
    borne->addObstacle(16, 15);
    borne->addObstacle(17, 15);
    borne->addObstacle(18, 15);
    borne->addObstacle(20, 15);
    borne->addObstacle(3, 17);
    borne->addObstacle(4, 17);
    borne->addObstacle(6, 17);
    borne->addObstacle(7, 17);
    borne->addObstacle(8, 17);
    borne->addObstacle(11, 17);
    borne->addObstacle(14, 17);
    borne->addObstacle(15, 17);
    borne->addObstacle(16, 17);
    borne->addObstacle(18, 17);
    borne->addObstacle(19, 17);
    borne->addObstacle(3, 18);
    borne->addObstacle(4, 18);
    borne->addObstacle(6, 18);
    borne->addObstacle(11, 18);
    borne->addObstacle(16, 18);
    borne->addObstacle(18, 18);
    borne->addObstacle(19, 18);
    borne->addObstacle(3, 19);
    borne->addObstacle(4, 19);
    borne->addObstacle(6, 19);
    borne->addObstacle(8, 19);
    borne->addObstacle(9, 19);
    borne->addObstacle(10, 19);
    borne->addObstacle(11, 19);
    borne->addObstacle(12, 19);
    borne->addObstacle(13, 19);
    borne->addObstacle(14, 19);
    borne->addObstacle(16, 19);
    borne->addObstacle(18, 19);
    borne->addObstacle(19, 19);
}

extern "C" void game(char *lib, std::string name)
{
    void* handle_graph = dlopen(lib, RTLD_LAZY);
    int rect_pacman[] = {0, 0, 50, 50};
    if (handle_graph == nullptr)
        exit(84);
    arcade* (*create)();
    create = (arcade* (*)())dlsym(handle_graph, "create_object");
    arcade *borne = (arcade*)create();
    borne->start(name, handle_graph, create, borne);
    borne->create_sprite("./res/pacman.png", "pacman", rect_pacman);
    borne->create_map2d(MAP_X, MAP_Y);
    create_border(borne);
    borne->addBonus(10, 10);
    borne->placeGhost(10, 9);
    borne->placeHero(2, 2, "pacman");
    while (borne->window_loop() == 1) {
        borne->move_hero("pacman", 0.1);
        borne->set_animation("pacman", 0.08f, 50, 149);
        borne->draw_shape();
        borne->draw_sprite();
        borne->dislayScore();
        borne->window_display();
        borne->clear_window();
        borne->close_window();
    }
    dlclose(handle_graph);
}
