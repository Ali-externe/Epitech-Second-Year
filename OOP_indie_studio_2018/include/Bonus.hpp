/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** player
*/

#pragma once

#include "../irrlicht-1.8.4/include/irrlicht.h"

class Bonus
{
public:
    Bonus(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::core::vector3df pos);
    ~Bonus();
    irr::scene::ISceneNode *cube;
    irr::core::vector3df posBonus;
    int type;
private:
};
