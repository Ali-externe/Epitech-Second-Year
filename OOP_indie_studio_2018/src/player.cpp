/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** player
*/

#include "../include/player.hpp"

Player::Player(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::IrrlichtDevice *device)
{
    this->mesh = smgr->getMesh("res/sydney.md2");
    if (!this->mesh) {
        device->drop();
        exit (84);
    }
    this->node = smgr->addAnimatedMeshSceneNode(this->mesh);
    if (this->node)
    {
        this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->node->setMD2Animation(irr::scene::EMAT_STAND);
        this->node->setMaterialTexture( 0, driver->getTexture("res/sydney.bmp"));
    }
    this->speed = 5;
    this->alive = true;
    this->wallpass = false;
    this->power = 1;
}

Player::~Player()
{
    
}