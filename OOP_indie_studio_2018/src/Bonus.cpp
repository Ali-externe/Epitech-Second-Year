/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** bomb
*/

#include "../include/Bonus.hpp"
#include "../include/map.hpp"

Bonus::Bonus(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::core::vector3df pos)
{
    this->cube = smgr->addCubeSceneNode(50);
    cube->setPosition(irr::core::vector3df(pos.X, pos.Y, pos.Z));
    this->posBonus.X = pos.X;
    this->posBonus.Z = pos.Z;
    this->posBonus.Y = pos.Y;
}

Bonus::~Bonus()
{

}
