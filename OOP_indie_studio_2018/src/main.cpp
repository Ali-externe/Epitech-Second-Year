#include "../irrlicht-1.8.4/include/irrlicht.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include "../SFML-2.5.1/SFML-2.5.1/include/SFML/Audio/Music.hpp"


#include "../include/event.hpp"
#include "../include/map.hpp"
#include "../include/menu.hpp"
#include "../include/bomb.hpp"
#include "../include/Ia.hpp"
#include "../include/Bonus.hpp"
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
#define MAP_X 21
#define MAP_Y 15

bool isObstacle(int destx, int desty, Map *map, Player *player)
{
    //début map x -550 z 350
    int tocasex = 0;
    int tocasey = 0;

    if (destx > 0)
        tocasex = ((destx / 50) + 11);
    else
        tocasex = ((destx / 50) + 11) - 1;
    if (desty > 0)
        tocasey = ((-desty / 50) + 7) - 1;
    else
        tocasey = ((-desty / 50) + 7);
    //printf("X = %d  Y = %d\n", destx, desty);
    //printf("X = %d  Y = %d\n", tocasex, tocasey);
    if (map->base_map[tocasey][tocasex] == 'M') {
        for (int s = 0; s < map->bonuss.size(); s++) {
            if ((int)getXon3D(tocasex) == (int)map->bonuss[s].posBonus.X && (int)getZon3D(tocasey) == (int)map->bonuss[s].posBonus.Z && (int)map->bonuss[s].posBonus.Y == 50) {
                map->bonuss[s].cube->setVisible(false);
                map->bonuss.erase(map->bonuss.begin()+s);
            }
        }
        player->power += 1;
        map->base_map[tocasey][tocasex] = ' ';
        return (true);
    }
    else if (map->base_map[tocasey][tocasex] == 'S') {
        for (int s = 0; s < map->bonuss.size(); s++) {
            if ((int)getXon3D(tocasex) == (int)map->bonuss[s].posBonus.X && (int)getZon3D(tocasey) == (int)map->bonuss[s].posBonus.Z && (int)map->bonuss[s].posBonus.Y == 50) {
                map->bonuss[s].cube->setVisible(false);
                map->bonuss.erase(map->bonuss.begin()+s);
            }
        }
        if (player->speed < 12) {
            player->speed += 1;
        }
        map->base_map[tocasey][tocasex] = ' ';
        return (true);
    }
    else if (map->base_map[tocasey][tocasex] == 'W') {
        for (int s = 0; s < map->bonuss.size(); s++) {
            if ((int)getXon3D(tocasex) == (int)map->bonuss[s].posBonus.X && (int)getZon3D(tocasey) == (int)map->bonuss[s].posBonus.Z && (int)map->bonuss[s].posBonus.Y == 50) {
                map->bonuss[s].cube->setVisible(false);
                map->bonuss.erase(map->bonuss.begin()+s);
            }
        }
        player->wallpass = true;
        map->base_map[tocasey][tocasex] = ' ';
        return (true);
    }
    if (map->base_map[tocasey][tocasex] == ' ' || map->base_map[tocasey][tocasex] == 'P' || map->base_map[tocasey][tocasex] == 'B')
        return (true);
    if (map->base_map[tocasey][tocasex] == 'O' && player->wallpass == true)
        return (true);
    return (false);
}

bool isObstacle_to_explose(int destx, int desty, std::vector<std::string> map)
{
    int tocasex = toCaseX(destx);
    int tocasey = toCaseZ(desty);

    if (tocasex < 0 || tocasex > 20) {
        return (false);
    }
    if (tocasey < 0 || tocasey > 14) {
        return (false);
    }
    if (map[tocasey][tocasex] == ' ' || map[tocasey][tocasex] == 'P' || map[tocasey][tocasex] == 'O')
        return (true);
    return (false);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    sf::Music ambiance;
    ambiance.openFromFile("./res/ambiance.wav");
    ambiance.play();
    ambiance.setLoop(true);
    bool isIa = false;
    int scene = 0;
    Map map;
    MyEventReceiver receiver;
    irr::IrrlichtDevice *device = irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 32, false, false, false, &receiver); // ancienne taille 1020 750

    if (ac > 1) {
        if (strcmp(av[1], "-ia") == 0)
            isIa = true;
    }
    if (!device)
        return (84);
    device->setWindowCaption(L"Best bomberman ever");
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
    irr::scene::ICameraSceneNode *camera;
    irr::core::vector3df posExplosion;
    int sizeY = ((MAP_Y * 50) / 2) - 50;
    int sizeX = (MAP_X * 50) / 2;
    std::vector<std::vector<irr::scene::ISceneNode*>> irrMap;
    irr::scene::ISceneNode *cube;

    //device->getCursorControl()->setVisible(false);                                                //à voir!
    smgr->getParameters()->setAttribute(irr::scene::COLLADA_CREATE_SCENE_INSTANCES, true);
    driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_32_BIT, true);
    smgr->addLightSceneNode(0, irr::core::vector3df(200, 200, 200), irr::video::SColorf(1.0f, 1.0f, 1.0f), 2000);
    smgr->setAmbientLight(irr::video::SColorf(0.3f, 0.3f, 0.3f));
    camera = smgr->addCameraSceneNode();
    camera->setPosition(irr::core::vector3df(0, (sizeX + 500), -(sizeY + 1)));
    irr::video::ITexture *image = driver->getTexture ("./res/menu.bmp");

    //SCENE
    while(device->run())
    {
        if (scene == 0) {
            if(receiver.GetMouseState().LeftButtonDown == true) {
                printf("x = %d   y = %d\n", receiver.GetMouseState().Position.X, receiver.GetMouseState().Position.Y);
                if (receiver.GetMouseState().Position.X > 113 && receiver.GetMouseState().Position.X < 858 && receiver.GetMouseState().Position.Y > 858 && receiver.GetMouseState().Position.Y < 1080){
                    Player player(driver, smgr, device);
                    map.players.push_back(player);
                    map.players[0].posNode.Y = 50;
                    map.players[0].posNode.X = 425;
                    map.players[0].posNode.Z = -275;
                    Player player2(driver, smgr, device);
                    map.players.push_back(player2);
                    map.players[1].posNode.Y = 50;
                    map.players[1].posNode.X = -475;
                    map.players[1].posNode.Z = -275;
                    map.base_map = map.map_random_maker(map.base_map);
                    irrMap = map.create_3d_map(driver, smgr, map, irrMap);
                    scene = 1;
                }
                if (receiver.GetMouseState().Position.X > 948 && receiver.GetMouseState().Position.X < 1787 && receiver.GetMouseState().Position.Y > 658 && receiver.GetMouseState().Position.Y < 802){
                    Player player(driver, smgr, device);
                    map.players.push_back(player);
                    map.players[0].posNode.Y = 50;
                    map.players[0].posNode.X = 425;
                    map.players[0].posNode.Z = -275;
                    Player player2(driver, smgr, device);
                    map.players.push_back(player2);
                    map.players[1].posNode.Y = 50;
                    map.players[1].posNode.X = -475;
                    map.players[1].posNode.Z = -275;
                    Player player3(driver, smgr, device);
                    map.players.push_back(player3);
                    map.players[2].posNode.Y = 50;
                    map.players[2].posNode.X = -475;
                    map.players[2].posNode.Z = 275;
                    map.base_map = map.map_random_maker(map.base_map);
                    irrMap = map.create_3d_map(driver, smgr, map, irrMap);
                    scene = 1;
                }
                if (receiver.GetMouseState().Position.X > 948 && receiver.GetMouseState().Position.X < 1884 && receiver.GetMouseState().Position.Y > 858 && receiver.GetMouseState().Position.Y < 1080){
                    Player player(driver, smgr, device);
                    map.players.push_back(player);
                    map.players[0].posNode.Y = 50;
                    map.players[0].posNode.X = 425;
                    map.players[0].posNode.Z = -275;
                    Player player2(driver, smgr, device);
                    map.players.push_back(player2);
                    map.players[1].posNode.Y = 50;
                    map.players[1].posNode.X = -475;
                    map.players[1].posNode.Z = -275;
                    Player player3(driver, smgr, device);
                    map.players.push_back(player3);
                    map.players[2].posNode.Y = 50;
                    map.players[2].posNode.X = -475;
                    map.players[2].posNode.Z = 275;
                    Player player4(driver, smgr, device);
                    map.players.push_back(player4);
                    map.players[3].posNode.Y = 50;
                    map.players[3].posNode.X = 425;
                    map.players[3].posNode.Z = 275;
                    map.base_map = map.map_random_maker(map.base_map);
                    irrMap = map.create_3d_map(driver, smgr, map, irrMap);
                    scene = 1;
                }
            }
        }
        if (scene == 1) {
            if(receiver.IsKeyDown(irr::KEY_KEY_Z) && map.players[0].alive == true) {
                if (isObstacle(map.players[0].posNode.X, map.players[0].posNode.Z + map.players[0].speed, &map, &map.players[0]) == true)
                    map.players[0].posNode.Z += map.players[0].speed;
            }
            else if(receiver.IsKeyDown(irr::KEY_KEY_S) && map.players[0].alive == true) {
                if (isObstacle(map.players[0].posNode.X, map.players[0].posNode.Z - map.players[0].speed, &map, &map.players[0]) == true)
                    map.players[0].posNode.Z -= map.players[0].speed;
            }
            else if(receiver.IsKeyDown(irr::KEY_KEY_Q) && map.players[0].alive == true) {
                if (isObstacle(map.players[0].posNode.X - map.players[0].speed, map.players[0].posNode.Z, &map, &map.players[0]) == true)
                    map.players[0].posNode.X -= map.players[0].speed;
            }
            else if(receiver.IsKeyDown(irr::KEY_KEY_D) && map.players[0].alive == true) {
                if (isObstacle(map.players[0].posNode.X + map.players[0].speed, map.players[0].posNode.Z, &map, &map.players[0]) == true)
                    map.players[0].posNode.X += map.players[0].speed;
            }
            if(receiver.IsKeyDown(irr::KEY_SPACE) && map.players[0].alive == true) {
                if (isBomb(map.players[0].posNode.X, map.players[0].posNode.Z, map.base_map) == false) {
                    Bomb bomb;
                    bomb.power = map.players[0].power;
                    map.base_map[toCaseZ(map.players[0].posNode.Z)][toCaseX(map.players[0].posNode.X)] = 'B';
                    bomb.posBomb.X = getXon3D(toCaseX(map.players[0].posNode.X));
                    bomb.posBomb.Y = 50;
                    bomb.posBomb.Z = getZon3D(toCaseZ(map.players[0].posNode.Z));
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(bomb.posBomb.X, 50, bomb.posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/bomb.jpg"));
                    bomb.tntcube.push_back(cube);
                    map.bombs.push_back(bomb);
                    //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                }
            }
            if (map.players.size() > 1) {
                if(receiver.IsKeyDown(irr::KEY_KEY_O) && isIa == false && map.players[1].alive == true) {
                    if (isObstacle(map.players[1].posNode.X, map.players[1].posNode.Z + map.players[1].speed, &map, &map.players[1]) == true)
                        map.players[1].posNode.Z += map.players[1].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_KEY_L) && isIa == false && map.players[1].alive == true) {
                    if (isObstacle(map.players[1].posNode.X, map.players[1].posNode.Z - map.players[1].speed, &map, &map.players[1]) == true)
                        map.players[1].posNode.Z -= map.players[1].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_KEY_K) && isIa == false && map.players[1].alive == true) {
                    if (isObstacle(map.players[1].posNode.X - map.players[1].speed, map.players[1].posNode.Z, &map, &map.players[1]) == true)
                        map.players[1].posNode.X -= map.players[1].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_KEY_M) && isIa == false && map.players[1].alive == true) {
                    if (isObstacle(map.players[1].posNode.X + map.players[1].speed, map.players[1].posNode.Z, &map, &map.players[1]) == true)
                        map.players[1].posNode.X += map.players[1].speed;
                }
                if(receiver.IsKeyDown(irr::KEY_KEY_P) && isIa == false && map.players[1].alive == true) {
                    if (isBomb(map.players[1].posNode.X, map.players[1].posNode.Z, map.base_map) == false) {
                        Bomb bomb;
                        bomb.power = map.players[1].power;
                        map.base_map[toCaseZ(map.players[1].posNode.Z)][toCaseX(map.players[1].posNode.X)] = 'B';
                        bomb.posBomb.X = getXon3D(toCaseX(map.players[1].posNode.X));
                        bomb.posBomb.Y = 50;
                        bomb.posBomb.Z = getZon3D(toCaseZ(map.players[1].posNode.Z));
                        cube = smgr->addCubeSceneNode(50);
                        cube->setPosition(irr::core::vector3df(bomb.posBomb.X, 50, bomb.posBomb.Z));
                        cube->setMaterialTexture(0, driver->getTexture("./res/bomb.jpg"));
                        bomb.tntcube.push_back(cube);
                        map.bombs.push_back(bomb);
                        //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    }
                }
                if (isIa == true) {
                    ia_player(&map, &map.players[1]);
                }
            }
            if (map.players.size() > 2) {
                if(receiver.IsKeyDown(irr::KEY_UP) && isIa == false && map.players[2].alive == true) {
                    if (isObstacle(map.players[2].posNode.X, map.players[2].posNode.Z + map.players[2].speed, &map, &map.players[2]) == true)
                        map.players[2].posNode.Z += map.players[2].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_DOWN) && isIa == false && map.players[2].alive == true) {
                    if (isObstacle(map.players[2].posNode.X, map.players[2].posNode.Z - map.players[2].speed, &map, &map.players[2]) == true)
                        map.players[2].posNode.Z -= map.players[2].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_LEFT) && isIa == false && map.players[2].alive == true) {
                    if (isObstacle(map.players[2].posNode.X - map.players[2].speed, map.players[2].posNode.Z, &map, &map.players[2]) == true)
                        map.players[2].posNode.X -= map.players[2].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_RIGHT) && isIa == false && map.players[2].alive == true) {
                    if (isObstacle(map.players[2].posNode.X + map.players[2].speed, map.players[2].posNode.Z, &map, &map.players[2]) == true)
                        map.players[2].posNode.X += map.players[2].speed;
                }
                if(receiver.IsKeyDown(irr::KEY_NEXT) && isIa == false && map.players[2].alive == true) {
                    if (isBomb(map.players[2].posNode.X, map.players[2].posNode.Z, map.base_map) == false) {
                        Bomb bomb;
                        bomb.power = map.players[2].power;
                        map.base_map[toCaseZ(map.players[2].posNode.Z)][toCaseX(map.players[2].posNode.X)] = 'B';
                        bomb.posBomb.X = getXon3D(toCaseX(map.players[2].posNode.X));
                        bomb.posBomb.Y = 50;
                        bomb.posBomb.Z = getZon3D(toCaseZ(map.players[2].posNode.Z));
                        cube = smgr->addCubeSceneNode(50);
                        cube->setPosition(irr::core::vector3df(bomb.posBomb.X, 50, bomb.posBomb.Z));
                        cube->setMaterialTexture(0, driver->getTexture("./res/bomb.jpg"));
                        bomb.tntcube.push_back(cube);
                        map.bombs.push_back(bomb);
                        //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    }
                }
                if (isIa == true) {
                    ia_player(&map, &map.players[2]);
                }
            }
            if (map.players.size() > 3) {
                if(receiver.IsKeyDown(irr::KEY_KEY_T) && isIa == false && map.players[3].alive == true) {
                    if (isObstacle(map.players[3].posNode.X, map.players[3].posNode.Z + map.players[3].speed, &map, &map.players[3]) == true)
                        map.players[3].posNode.Z += map.players[3].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_KEY_G) && isIa == false && map.players[3].alive == true) {
                    if (isObstacle(map.players[3].posNode.X, map.players[3].posNode.Z - map.players[3].speed, &map, &map.players[3]) == true)
                        map.players[3].posNode.Z -= map.players[3].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_KEY_F) && isIa == false && map.players[3].alive == true) {
                    if (isObstacle(map.players[3].posNode.X - map.players[3].speed, map.players[3].posNode.Z, &map, &map.players[3]) == true)
                        map.players[3].posNode.X -= map.players[3].speed;
                }
                else if(receiver.IsKeyDown(irr::KEY_KEY_H) && isIa == false && map.players[3].alive == true) {
                    if (isObstacle(map.players[3].posNode.X + map.players[3].speed, map.players[3].posNode.Z, &map, &map.players[3]) == true)
                        map.players[3].posNode.X += map.players[3].speed;
                }
                if(receiver.IsKeyDown(irr::KEY_KEY_Y) && isIa == false && map.players[3].alive == true) {
                    if (isBomb(map.players[3].posNode.X, map.players[3].posNode.Z, map.base_map) == false) {
                        Bomb bomb;
                        bomb.power = map.players[3].power;
                        map.base_map[toCaseZ(map.players[3].posNode.Z)][toCaseX(map.players[3].posNode.X)] = 'B';
                        bomb.posBomb.X = getXon3D(toCaseX(map.players[3].posNode.X));
                        bomb.posBomb.Y = 50;
                        bomb.posBomb.Z = getZon3D(toCaseZ(map.players[3].posNode.Z));
                        cube = smgr->addCubeSceneNode(50);
                        cube->setPosition(irr::core::vector3df(bomb.posBomb.X, 50, bomb.posBomb.Z));
                        cube->setMaterialTexture(0, driver->getTexture("./res/bomb.jpg"));
                        bomb.tntcube.push_back(cube);
                        map.bombs.push_back(bomb);
                        //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    }
                }
                if (isIa == true) {
                    ia_player(&map, &map.players[3]);
                }
            }
            bombEvent(driver, smgr, &map, irrMap);
            for (int size = 0; size != map.players.size(); size++) {
                map.players[size].node->setPosition(map.players[size].posNode);
            }
        }
        driver->beginScene(true, true, irr::video::SColor(0, 120, 120, 120));
        if (scene == 0) {
            driver->draw2DImage(image, irr::core::position2d<irr::s32>(0,0), irr::core::rect<irr::s32>(0,0,1920,1080), 0, irr::video::SColor (255,255,255,255), true);
        }
        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }
    device->drop();

    return (0);
}

void bombEvent(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, Map *map, std::vector<std::vector<irr::scene::ISceneNode*>> irrMap)
{
    irr::scene::ISceneNode *cube;
    //sf::Music explosion;
    ////explosion.openFromFile("./res/explosion.ogg");

    for (int s = 0; s < map->bombs.size(); s++) {
        time(&map->bombs[s].current_time);
        if (map->bombs[s].d == 0) {
            map->bombs[s].save_time = map->bombs[s].current_time;
            map->bombs[s].d = 3;
        }
        if ((map->bombs[s].current_time - map->bombs[s].save_time) >= 2) {
            int mapx = (((int)map->bombs[s].posBomb.X / 50) + 11) - 1;
            int mapy = 0;
            //printf("x = %d  z = %d\n", (int)posBomb.X, (int)posBomb.Z);
            if (map->bombs[s].posBomb.X > 0)
                mapx = (((int)map->bombs[s].posBomb.X / 50) + 11);
            else
                mapx = (((int)map->bombs[s].posBomb.X / 50) + 11) - 1;
            if (map->bombs[s].posBomb.Z > 0)
                mapy = (((int)-map->bombs[s].posBomb.Z / 50) + 7) - 1;
            else
                mapy = (((int)-map->bombs[s].posBomb.Z / 50) + 7);
            //printf("x = %d  z = %d\n", mapx, mapy);
            bool up = true;
            bool down = true;
            bool right = true;
            bool left = true;
            for (int power = 0, range = 50; power != map->bombs[s].power; power++, range += 50) {
                int pow = power + 1;
                if (isObstacle_to_explose(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Z + range, map->base_map) == true && up == true) {
                    map->base_map[mapy - pow][mapx] = ' ';
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z + range));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    for (int l = 0; l != irrMap.size(); l++) {
                        for (int k = 0; k != irrMap[l].size(); k++) {
                            if (irrMap[l][k]->getPosition().X == map->bombs[s].posBomb.X && irrMap[l][k]->getPosition().Z == map->bombs[s].posBomb.Z + range && irrMap[l][k]->getPosition().Y == map->bombs[s].posBomb.Y && irrMap[l][k]->isVisible() == true) {
                                irrMap[l][k]->setVisible(false);
                                map->bombs[s].posBomb.Z += range;
                                posbonus(driver, smgr, map->bombs[s].posBomb, map);
                                map->bombs[s].posBomb.Z -= range;
                            }
                        }
                    }
                }
                else
                    up = false;
                if (isObstacle_to_explose(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Z - range, map->base_map) == true && down == true) {
                    map->base_map[mapy + pow][mapx] = ' ';
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z - range));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    for (int l = 0; l != irrMap.size(); l++) {
                        for (int k = 0; k != irrMap[l].size(); k++) {
                            if (irrMap[l][k]->getPosition().X == map->bombs[s].posBomb.X && irrMap[l][k]->getPosition().Z == map->bombs[s].posBomb.Z - range && irrMap[l][k]->getPosition().Y == map->bombs[s].posBomb.Y && irrMap[l][k]->isVisible() == true) {
                                irrMap[l][k]->setVisible(false);
                                map->bombs[s].posBomb.Z -= range;
                                posbonus(driver, smgr, map->bombs[s].posBomb, map);
                                map->bombs[s].posBomb.Z += range;
                            }
                        }
                    }
                }
                else
                    down = false;
                if (isObstacle_to_explose(map->bombs[s].posBomb.X - range, map->bombs[s].posBomb.Z, map->base_map) == true && left == true) {
                    map->base_map[mapy][mapx - pow] = ' ';
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X - range, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    for (int l = 0; l != irrMap.size(); l++) {
                        for (int k = 0; k != irrMap[l].size(); k++) {
                            if (irrMap[l][k]->getPosition().X == map->bombs[s].posBomb.X - range && irrMap[l][k]->getPosition().Z == map->bombs[s].posBomb.Z && irrMap[l][k]->getPosition().Y == map->bombs[s].posBomb.Y && irrMap[l][k]->isVisible() == true) {
                                irrMap[l][k]->setVisible(false);
                                map->bombs[s].posBomb.X -= range;
                                posbonus(driver, smgr, map->bombs[s].posBomb, map);
                                map->bombs[s].posBomb.X += range;
                            }
                        }
                    }
                }
                else
                    left = false;
                if (isObstacle_to_explose(map->bombs[s].posBomb.X + range, map->bombs[s].posBomb.Z, map->base_map) == true && right == true) {
                    map->base_map[mapy][mapx + pow] = ' ';
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X + range, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    cube = smgr->addCubeSceneNode(50);
                    cube->setPosition(irr::core::vector3df(map->bombs[s].posBomb.X, map->bombs[s].posBomb.Y, map->bombs[s].posBomb.Z));
                    cube->setMaterialTexture(0, driver->getTexture("./res/explosion.jpg"));
                    //explosion.openFromFile("./res/explosion.ogg");
                    //explosion.setVolume(200);
                    //explosion.play();
                    map->bombs[s].explocube.push_back(cube);
                    for (int l = 0; l != irrMap.size(); l++) {
                        for (int k = 0; k != irrMap[l].size(); k++) {
                            if (irrMap[l][k]->getPosition().X == map->bombs[s].posBomb.X + range && irrMap[l][k]->getPosition().Z == map->bombs[s].posBomb.Z && irrMap[l][k]->getPosition().Y == map->bombs[s].posBomb.Y && irrMap[l][k]->isVisible() == true) {
                                irrMap[l][k]->setVisible(false);
                                map->bombs[s].posBomb.X += range;
                                posbonus(driver, smgr, map->bombs[s].posBomb, map);
                                map->bombs[s].posBomb.X -= range;
                            }
                        }
                    }
                }
                else
                    right = false;
            }
            //map.print_map();
            for (int i = 0; i != map->bombs[s].tntcube.size(); i++)
                map->bombs[s].tntcube[i]->setVisible(false);
            map->bombs[s].tntcube.clear();
            map->base_map[toCaseZ(map->bombs[s].posBomb.Z)][toCaseX(map->bombs[s].posBomb.X)] = ' ';
            map->bombs[s].d = 0;
            map->bombs[s].save_time = map->bombs[s].current_time;
            checkDeath(map, &map->bombs[s]);
        }
        if (map->bombs[s].explocube.size() != 0) {
            time(&map->bombs[s].opentime1);
            if (map->bombs[s].egale == 0) {
                map->bombs[s].timeur1 = map->bombs[s].opentime1;
                map->bombs[s].egale = 1;
            }
            if (map->bombs[s].opentime1 - map->bombs[s].timeur1 >= 1) {
                for (int i = 0; i != map->bombs[s].explocube.size(); i++)
                    map->bombs[s].explocube[i]->setVisible(false);
                map->bombs[s].explocube.clear();
                map->bombs[s].egale = 0;
                map->bombs.erase(map->bombs.begin()+s);
            }
        }
    }
}

void posbonus(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, irr::core::vector3df pos, Map *map)
{
    int r = rand() % 31;
    int X = toCaseX((int)pos.X);
    int Z = toCaseZ((int)pos.Z);

    if (r == 1 || r == 2 || r == 3 || r == 12 || r == 13 || r == 14) {
        map->base_map[Z][X] = 'S';
        Bonus bonus(driver, smgr, pos);
        bonus.type = 1;
        bonus.cube->setMaterialTexture(0, driver->getTexture("./res/speedup.jpg"));
        map->bonuss.push_back(bonus);
    }
    else if (r == 6 || r == 7 || r == 8 || r == 21 || r == 22 || r == 23) {
        map->base_map[Z][X] = 'M';
        Bonus bonus(driver, smgr, pos);
        bonus.type = 2;
        bonus.cube->setMaterialTexture(0, driver->getTexture("./res/powerup.jpg"));
        map->bonuss.push_back(bonus);
    }
    else if (r == 0 || r == 30) {
        map->base_map[Z][X] = 'W';
        Bonus bonus(driver, smgr, pos);
        bonus.type = 3;
        bonus.cube->setMaterialTexture(0, driver->getTexture("./res/wallpass.jpg"));
        map->bonuss.push_back(bonus);
    }
}

void ia_player(Map *map, Player *player)
{
    int dir = rand() % 4;
    int p_bomb = rand() % 2;

    if(dir == 0) {
        if (isObstacle(player->posNode.X, player->posNode.Z + player->speed, map, player) == true)
            player->posNode.Z += player->speed;
        else
            ia_player(map, player);
    }
    else if(dir == 1) {
        if (isObstacle(player->posNode.X, player->posNode.Z - player->speed, map, player) == true)
            player->posNode.Z -= player->speed;
            else
                ia_player(map, player);
    }
    else if(dir == 2) {
        if (isObstacle(player->posNode.X - player->speed, player->posNode.Z, map, player) == true)
            player->posNode.X -= player->speed;
            else
                ia_player(map, player);
    }
    else if(dir == 3) {
        if (isObstacle(player->posNode.X + player->speed, player->posNode.Z, map, player) == true)
            player->posNode.X += player->speed;
            else
                ia_player(map, player);
    }
}

void checkDeath(Map *map, Bomb *bomb)
{
    int X = toCaseX(bomb->posBomb.X);
    int Z = toCaseZ(bomb->posBomb.Z);
    int Xh = 0;
    int Zh = 0;
    int nbAlive = 0;

    for (int s = 0; s != map->players.size(); s++) {
        Xh = toCaseX(map->players[s].posNode.X);
        Zh = toCaseZ(map->players[s].posNode.Z);
        if (Xh == X && Zh == Z) {
            map->players[s].alive = false;
            map->players[s].node->setVisible(false);
        }
        for (int power = 0; power != bomb->power; power++) {
            int pow = power + 1;
            if (Xh + pow == X && Zh == Z) {
                map->players[s].alive = false;
                map->players[s].node->setVisible(false);
            }
            else if (Xh - pow == X && Zh == Z) {
                map->players[s].alive = false;
                map->players[s].node->setVisible(false);
            }
            else if (Xh == X && Zh + pow == Z) {
                map->players[s].alive = false;
                map->players[s].node->setVisible(false);
            }
            else if (Xh == X && Zh - pow == Z) {
                map->players[s].alive = false;
                map->players[s].node->setVisible(false);
            }
        }
        if (map->players[s].alive == true)
            nbAlive++;
    }
    if (nbAlive == 1) {
        int n = 0;
         for (; n != map->players.size(); n++) {
            if (map->players[n].alive == true)
                break;
         }
        printf("Player %d won.\n", n + 1);
        exit(0);
    }
    if (nbAlive == 0) {
        printf("Draw.\n");
        exit(0);
    }
}
