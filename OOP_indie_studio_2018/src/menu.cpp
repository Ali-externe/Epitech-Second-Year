/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** menu
*/

#include "../include/menu.hpp"

Menu::Menu(MyEventReceiver receiver)
{
    this->device =
        irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1020, 750), 32, false, false, false, &receiver);
    if (!this->device)
        exit(84);
    this->device->setWindowCaption(L"Bomberman - Irrlicht Engine Demo");
    this->driver = device->getVideoDriver();
    this->smgr = device->getSceneManager();
    this->guienv = device->getGUIEnvironment();
    this->smgr->getParameters()->setAttribute(irr::scene::COLLADA_CREATE_SCENE_INSTANCES, true);
    this->driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);
    this->smgr->addLightSceneNode(0, irr::core::vector3df(200, 200, 200), irr::video::SColorf(1.0f, 1.0f, 1.0f), 2000);
    this->smgr->setAmbientLight(irr::video::SColorf(0.3f, 0.3f, 0.3f));
    this->camera = smgr->addCameraSceneNode();
    this->camera->setPosition(irr::core::vector3df(0, 1000, -500));
}

Menu::~Menu()
{

}

void Menu::start(MyEventReceiver receiver)
{
    while(this->device->run())
    {
        printf("test\n");
        if(receiver.IsKeyDown(irr::KEY_ESCAPE)) {
            this->device->closeDevice();
        }
        this->driver->beginScene(true, true, irr::video::SColor(0, 120, 120, 120));
        this->smgr->drawAll();
        this->guienv->drawAll();
        this->driver->endScene();
    }
    this->device->drop();
}