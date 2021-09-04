/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../irrlicht-1.8.4/include/irrlicht.h"

class Player
{
public:
    Player(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::IrrlichtDevice *device);
    ~Player();
    irr::scene::IAnimatedMesh* mesh;
    irr::scene::IAnimatedMeshSceneNode* node;
    irr::core::vector3df posNode;
    int speed;
    bool alive;
    bool wallpass;
    int power;
private:
};

#endif /* !PLAYER_HPP_ */
