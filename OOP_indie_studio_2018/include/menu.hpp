/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** menu
*/

#pragma once
#include "event.hpp"
#include "../irrlicht-1.8.4/include/irrlicht.h"
#include <iostream>

class Menu
{
public:
    Menu(MyEventReceiver receiver);
    ~Menu();
    void start(MyEventReceiver receiver);
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver* driver;
    irr::scene::ISceneManager* smgr;
    irr::gui::IGUIEnvironment* guienv;
    irr::scene::ICameraSceneNode *camera;

private:
};
