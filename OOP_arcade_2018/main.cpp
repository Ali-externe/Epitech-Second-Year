/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>
#include "include/interface.hpp"
#include "include/dl.hpp"

extern "C" typedef void (*game_t)(char *lib, std::string name);

int main(int argc, char **argv)
{
    int ret_menu = 0;
    dl dl;

    if (argv[1] == nullptr || argc > 3)
        return (84);
    void* handle_game = dl.open_dl((char *)"./lib_arcade_pacman.so");
    void* handle_graph = dl.open_dl(argv[1]);
    if (handle_game == nullptr)
        return (84);
    if (handle_graph == nullptr)
        return (84);
    arcade* (*create)();
    create = (arcade* (*)())dl.get_sym(handle_graph, (char *)"create_object");
    arcade *borne = (arcade*)create();
    ret_menu = borne->loadMenu();
    if (ret_menu == 1) {
        game_t game = (game_t)dlsym(handle_game, "game");
        if (argc == 3)
            game(argv[1], argv[2]);
        else
            game(argv[1], "Player");
    }
    dl.close_dl(handle_game);
    dl.close_dl(handle_graph);
    return (0);
}
