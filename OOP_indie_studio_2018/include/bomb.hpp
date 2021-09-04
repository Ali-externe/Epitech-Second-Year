/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** player
*/

#pragma once
#include "../irrlicht-1.8.4/include/irrlicht.h"
#include <iostream>
#include <vector>

class Bomb
{
public:
    Bomb();
    ~Bomb();
    time_t timeur1;
    time_t opentime1;
    time_t current_time;
    time_t save_time;
    int d = 0;
    int egale = 0;
    int power = 1;
    irr::core::vector3df posBomb;
    irr::core::vector3df posExplosion;
    std::vector<irr::scene::ISceneNode *> tntcube;
    std::vector<irr::scene::ISceneNode *> explocube;
private:
};

bool isBomb(int destx, int desty, std::vector<std::string> map);