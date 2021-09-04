/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_ncurse
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/ncurse.hpp"
#include <curses.h>

extern "C" ncurse* create_object()
{
  return new ncurse;
}

int ncurse::loadMenu()
{
    int ret_value = 0;
    int key;

    initscr();
    printw("Which game do you want to load ?\nPacman : Press A\nQuit : Press Space");
    refresh();
    noecho();
    keypad(stdscr, TRUE);
    for (int i = 0; i == 0; ) {
      key = getch();
      if (key == 65 || key == 97) {
        ret_value = 1;
        i = 1;
      }
      if (key == 32)
        i = 1;
    }
    endwin();
    return (ret_value);
}

void ncurse::start(std::string name, void* handle_graph, arcade *(*create)(), arcade* borne)
{
    this->create = create;
    this->borne = borne;
    this->handle_graph = handle_graph;
    this->name = name;
    initscr();
    refresh();
    noecho();
    keypad(stdscr, TRUE);
}

int ncurse::create_sprite(std::string, std::string name, int *rect)
{
  return (0);
}

char **assemble_maps(char **first, char**second, char **res)
{
  for (int i = 0; res[i] != nullptr; i++) {
    for (int x = 0; res[i][x] != '\0'; x++) {
      if (second[i][x] == 'P' || second [i][x] == 'G')
        res[i][x] = second[i][x];
      else if (first[i][x] == 'B')
        res[i][x] = 'B';
      else if (first[i][x] == 'o')
        res[i][x] = 'o';
      else if (first[i][x] == ' ')
        res[i][x] = ' ';
    }
  }
  return (res);
}

int ncurse::window_loop()
{
  clear();
  if (this->final_map == nullptr) {
    this->end = 0;
    endwin();
    std::cout << "Map uninitialized." << std::endl;
    exit(84);
  }
  this->final_map = assemble_maps(this->mapitem, this->mapentity, this->final_map);
  for (int i = 0; this->final_map[i] != nullptr; i++)
    printw("%s\n", this->final_map[i]);
  printw("%s : %d\n", this->name.c_str(), this->score);
  return (this->end);
}

void ncurse::window_display()
{
  return;
}
