/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** event
*/

#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "player.hpp"
#include "bomb.hpp"
#include "Bonus.hpp"

class Map
{
public:
    Map();
    ~Map();
    void print_map();
    std::vector<std::vector<irr::scene::ISceneNode*>> create_3d_map(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, Map map, std::vector<std::vector<irr::scene::ISceneNode*>> irrMap);
    std::vector<std::string> base_map;
    std::vector<std::string> map_random_maker(std::vector<std::string> str);
    std::vector<Player> players;
    std::vector<Bomb> bombs;
    std::vector<Bonus> bonuss;
private:
};

std::vector<std::string> map_random_maker(std::vector<std::string> str);
int getXon3D(int destx);
int getZon3D(int desty);
int toCaseX(int destx);
int toCaseZ(int desty);
bool isObstacle(int destx, int desty, Map *map);
bool isObstacle_to_explose(int destx, int desty, std::vector<std::string> map);
void bombEvent(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, Map *map, std::vector<std::vector<irr::scene::ISceneNode*>> irrMap);
void posbonus(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::core::vector3df pos, Map *map);
void checkDeath(Map *map, Bomb *bomb);
void rand_stone_text(irr::scene::ISceneNode *cube, irr::video::IVideoDriver* driver);
