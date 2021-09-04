/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** event
*/

#define MAP_X 21
#define MAP_Y 15
#include "../include/map.hpp"

Map::Map() {
    this->base_map.push_back("XXXXXXXXXXXXXXXXXXXXX\n");
    this->base_map.push_back("XPP               PPX\n");
    this->base_map.push_back("XPx x x x x x x x xPX\n");
    this->base_map.push_back("X                   X\n");
    this->base_map.push_back("X x x x x x x x x x X\n");
    this->base_map.push_back("X                   X\n");
    this->base_map.push_back("X x x x x x x x x x X\n");
    this->base_map.push_back("X                   X\n");
    this->base_map.push_back("X x x x x x x x x x X\n");
    this->base_map.push_back("X                   X\n");
    this->base_map.push_back("X x x x x x x x x x X\n");
    this->base_map.push_back("X                   X\n");
    this->base_map.push_back("XPx x x x x x x x xPX\n");
    this->base_map.push_back("XPP               PPX\n");
    this->base_map.push_back("XXXXXXXXXXXXXXXXXXXXX");
}

Map::~Map() {
}

void vector_printer(std::vector<std::string> str)
{
    for (int i = 0; i < str.size(); i++) {
        std::cout << str.at(i);
    }
}

char random_char()
{
    int r = 0;

    r = rand() % 3;
        if (r == 0)
            return ' ';
        else
            return 'O';
}

std::vector<std::string> Map::map_random_maker(std::vector<std::string> str)
{
    int a=0;
    int b=0;

    while (a != 14) {
        if (str[a][b] == '\n') {
            b=-1;
            a++;
        }
        else if (str[a][b] == ' ') {
            str[a][b] = random_char();
        }
        b++;
    }
    return str;
}

void put_blocks(std::vector<std::string> str)
{
    int a=0;
    int b=0;

    while (a != 14) {
        switch (str[a][b]) {
            case 'x':
                std::cout << str[a][b];
                //posey le block invinsible
                break;
            case '\n':
                std::cout << str[a][b];
                //paaser a la ligne de block suivante
                b=-1;
                a++;
                break;
            case ' ':
                std::cout << str[a][b];
                //ne rien poser c la ou le mec pourra bouger
                break;
            case 'P':
                std::cout << str[a][b];
                //poser le perso ou rien
                break;
            case 'O':
                std::cout << str[a][b];
                //poser les blocks cassable
                break;
            default:
                break;
        }
        b++;
    }
}

void Map::print_map()
{
    for (int i = 0; i != this->base_map.size(); i++)
        std::cout << this->base_map[i];
    std::cout << std::endl;
}

void rand_stone_text(irr::scene::ISceneNode *cube, irr::video::IVideoDriver* driver)
{
    static int f = 0;
    static int stone = 0;
    int r = rand() % 13;
    if (f == 0) {
        stone = r;
        f = 100;
    }
    switch (stone) {
        case 0:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone1.jpeg"));
            break;
        case 1:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone2.jpeg"));
            break;
        case 2:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone3.jpeg"));
            break;
        case 3:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone4.jpeg"));
            break;
        case 4:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone5.jpeg"));
            break;
        case 5:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone6.jpeg"));
            break;
        case 6:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone7.jpeg"));
            break;
        case 7:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone8.jpeg"));
            break;
        case 8:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone9.jpeg"));
            break;
        case 9:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone10.jpeg"));
            break;
        case 10:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone11.jpeg"));
            break;
        case 11:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone12.jpeg"));
            break;
        case 12:
            cube->setMaterialTexture(0, driver->getTexture("./res/stone13.jpeg"));
            break;
    }
}

void rand_grass_text(irr::scene::ISceneNode *cube, irr::video::IVideoDriver* driver)
{
    static int f = 0;
    static int stone = 0;
    int r = rand() % 12;
    if (f == 0) {
        stone = r;
        f = 100;
    }
    switch (stone) {
        case 0:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass.jpeg"));
            break;
        case 1:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass1.jpeg"));
            break;
        case 2:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass2.jpeg"));
            break;
        case 3:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass3.jpeg"));
            break;
        case 4:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass4.jpeg"));
            break;
        case 5:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass5.jpeg"));
            break;
        case 6:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass6.jpeg"));
            break;
        case 7:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass7.jpeg"));
            break;
        case 8:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass8.jpeg"));
            break;
        case 9:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass9.jpeg"));
            break;
        case 10:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass10.jpeg"));
            break;
        case 11:
            cube->setMaterialTexture(0, driver->getTexture("./res/grass11.jpeg"));
            break;
    }
}

void rand_wood_text(irr::scene::ISceneNode *cube, irr::video::IVideoDriver* driver)
{
    static int f = 0;
    static int stone = 0;
    int r = rand() % 5;
    if (f == 0) {
        stone = r;
        f = 100;
    }
    switch (stone) {
        case 0:
            cube->setMaterialTexture(0, driver->getTexture("./res/wood1.jpeg"));
            break;
        case 1:
            cube->setMaterialTexture(0, driver->getTexture("./res/wood2.jpeg"));
            break;
        case 2:
            cube->setMaterialTexture(0, driver->getTexture("./res/wood3.jpeg"));
            break;
        case 3:
            cube->setMaterialTexture(0, driver->getTexture("./res/wood4.jpeg"));
            break;
        case 4:
            cube->setMaterialTexture(0, driver->getTexture("./res/wood5.jpeg"));
            break;
    }
}


std::vector<std::vector<irr::scene::ISceneNode*>> Map::create_3d_map(irr::video::IVideoDriver* driver, irr::scene::ISceneManager* smgr, Map map, std::vector<std::vector<irr::scene::ISceneNode*>> irrMap)
{
    std::vector<irr::scene::ISceneNode*> lineIrrMap;
    irr::scene::ISceneNode *cube;
    int sizeY = ((MAP_Y * 50) / 2) - 50;
    int sizeX = (MAP_X * 50) / 2;
    for (int i = sizeY, f = 0; i > (-sizeY - 100); i-=50, f++) {
        for (int j = -sizeX, g = 0; j < sizeX; j+=50, g++) {
            cube = smgr->addCubeSceneNode(50);
            cube->setPosition(irr::core::vector3df(j, 0, i));
            rand_grass_text(cube, driver);
            //cube->setMaterialTexture(0, driver->getTexture("./res/grass.jpeg"));
            //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            if (map.base_map[f][g] == 'O') {
                cube = smgr->addCubeSceneNode(50);
                cube->setPosition(irr::core::vector3df(j, 50, i));
                rand_wood_text(cube, driver);
                //cube->setMaterialTexture(0, driver->getTexture("./res/wood.jpeg"));
                //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                lineIrrMap.push_back(cube);
            }
            if (map.base_map[f][g] == 'x' || map.base_map[f][g] == 'X') {
                cube = smgr->addCubeSceneNode(50);
                cube->setPosition(irr::core::vector3df(j, 50, i));
                rand_stone_text(cube, driver);
                //cube->setMaterialTexture(0, driver->getTexture("./res/stone.jpeg"));
                //cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                lineIrrMap.push_back(cube);
            }
            else
                lineIrrMap.push_back(cube);
        }
        irrMap.push_back(lineIrrMap);
        lineIrrMap.clear();
    }
    return (irrMap);
}
