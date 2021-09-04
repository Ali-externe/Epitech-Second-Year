/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sfml5
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/interface.hpp"
#include "../include/SFML.hpp"
#include <dlfcn.h>
#include <string.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>
#define MAP_X 21
#define MAP_Y 19

void create_border(arcade *borne)
{
    for (int y = 1; y != MAP_Y + 1; y++) {
        for (int x = 1; x != MAP_X + 1; x++) {
            if (y == 1)
                borne->addObstacle(x, y);
            if (y == 19)
                borne->addObstacle(x, y);
            if (x == 1)
                borne->addObstacle(x, y);
            if (x == 21)
                borne->addObstacle(x, y);
        }
    }
    borne->addObstacle(3, 3);
    borne->addObstacle(4, 3);
    borne->addObstacle(6, 2);
    borne->addObstacle(6, 3);
    borne->addObstacle(8, 3);
    borne->addObstacle(9, 3);
    borne->addObstacle(10, 3);
    borne->addObstacle(11, 3);
    borne->addObstacle(12, 3);
    borne->addObstacle(13, 3);
    borne->addObstacle(14, 3);
    borne->addObstacle(16, 2);
    borne->addObstacle(16, 3);
    borne->addObstacle(18, 3);
    borne->addObstacle(19, 3);
    borne->addObstacle(2, 5);
    borne->addObstacle(4, 5);
    borne->addObstacle(6, 5);
    borne->addObstacle(7, 5);
    borne->addObstacle(8, 5);
    borne->addObstacle(11, 5);
    borne->addObstacle(14, 5);
    borne->addObstacle(15, 5);
    borne->addObstacle(16, 5);
    borne->addObstacle(18, 5);
    borne->addObstacle(20, 5);
    borne->addObstacle(4, 6);
    borne->addObstacle(11, 6);
    borne->addObstacle(18, 6);
    borne->addObstacle(2, 7);
    borne->addObstacle(4, 7);
    borne->addObstacle(5, 7);
    borne->addObstacle(6, 7);
    borne->addObstacle(8, 7);
    borne->addObstacle(9, 7);
    borne->addObstacle(10, 7);
    borne->addObstacle(11, 7);
    borne->addObstacle(12, 7);
    borne->addObstacle(13, 7);
    borne->addObstacle(14, 7);
    borne->addObstacle(16, 7);
    borne->addObstacle(17, 7);
    borne->addObstacle(18, 7);
    borne->addObstacle(20, 7);
    borne->addObstacle(2, 8);
    borne->addObstacle(20, 8);
    borne->addObstacle(2, 9);
    borne->addObstacle(4, 9);
    borne->addObstacle(5, 9);
    borne->addObstacle(6, 9);
    borne->addObstacle(16, 9);
    borne->addObstacle(17, 9);
    borne->addObstacle(18, 9);
    borne->addObstacle(20, 9);
    borne->addObstacle(2, 10);
    borne->addObstacle(4, 10);
    borne->addObstacle(18, 10);
    borne->addObstacle(20, 10);
    borne->addObstacle(20, 10);
    borne->addObstacle(2, 11);
    borne->addObstacle(4, 11);
    borne->addObstacle(6, 11);
    borne->addObstacle(16, 11);
    borne->addObstacle(18, 11);
    borne->addObstacle(20, 11);
    borne->addObstacle(6, 12);
    borne->addObstacle(16, 12);
    borne->addObstacle(2, 13);
    borne->addObstacle(4, 13);
    borne->addObstacle(5, 13);
    borne->addObstacle(6, 13);
    borne->addObstacle(7, 13);
    borne->addObstacle(8, 13);
    borne->addObstacle(11, 13);
    borne->addObstacle(14, 13);
    borne->addObstacle(15, 13);
    borne->addObstacle(16, 13);
    borne->addObstacle(17, 13);
    borne->addObstacle(18, 13);
    borne->addObstacle(20, 13);
    borne->addObstacle(2, 14);
    borne->addObstacle(11, 14);
    borne->addObstacle(20, 14);
    borne->addObstacle(2, 15);
    borne->addObstacle(4, 15);
    borne->addObstacle(5, 15);
    borne->addObstacle(6, 15);
    borne->addObstacle(8, 15);
    borne->addObstacle(9, 15);
    borne->addObstacle(10, 15);
    borne->addObstacle(11, 15);
    borne->addObstacle(12, 15);
    borne->addObstacle(13, 15);
    borne->addObstacle(14, 15);
    borne->addObstacle(16, 15);
    borne->addObstacle(17, 15);
    borne->addObstacle(18, 15);
    borne->addObstacle(20, 15);
    borne->addObstacle(3, 17);
    borne->addObstacle(4, 17);
    borne->addObstacle(6, 17);
    borne->addObstacle(7, 17);
    borne->addObstacle(8, 17);
    borne->addObstacle(11, 17);
    borne->addObstacle(14, 17);
    borne->addObstacle(15, 17);
    borne->addObstacle(16, 17);
    borne->addObstacle(18, 17);
    borne->addObstacle(19, 17);
    borne->addObstacle(3, 18);
    borne->addObstacle(4, 18);
    borne->addObstacle(6, 18);
    borne->addObstacle(11, 18);
    borne->addObstacle(16, 18);
    borne->addObstacle(18, 18);
    borne->addObstacle(19, 18);
    borne->addObstacle(3, 19);
    borne->addObstacle(4, 19);
    borne->addObstacle(6, 19);
    borne->addObstacle(8, 19);
    borne->addObstacle(9, 19);
    borne->addObstacle(10, 19);
    borne->addObstacle(11, 19);
    borne->addObstacle(12, 19);
    borne->addObstacle(13, 19);
    borne->addObstacle(14, 19);
    borne->addObstacle(16, 19);
    borne->addObstacle(18, 19);
    borne->addObstacle(19, 19);
}

void SFML::change_lib(std::string lib)
{
    int rect_pacman[] = {0, 0, 50, 50};
    //lib = "./lib_arcade_ncurses.so";
    name = this->name;

    this->handle_graph = dlopen(lib.c_str(), RTLD_LAZY);
    if (this->handle_graph == NULL)
        exit(84);
    this->create = (arcade* (*)())dlsym(this->handle_graph, "create_object");
    this->borne  = (arcade*)this->create();

    this->borne->start(this->name, this->handle_graph, this->create, this->borne);
    this->borne->create_sprite("./res/pacman.png", "pacman", rect_pacman);
    this->borne->create_map2d(MAP_X, MAP_Y);
    create_border(this->borne);
    this->borne->addBonus(10, 10);
    this->borne->placeGhost(10, 9);
    this->borne->placeHero(2, 2, "pacman");
    while (this->borne->window_loop() == 1) {
        this->borne->move_hero("pacman", 0.1);
        this->borne->set_animation("pacman", 0.08f, 50, 149);
        this->borne->draw_shape();
        this->borne->draw_sprite();
        this->borne->dislayScore();
        this->borne->window_display();
        this->borne->clear_window();
        this->borne->close_window();
    }
    dlclose(this->handle_graph);
}

void SFML::destroyBonus(int x, int y)
{
    int len = this->elem.size();
    std::string coor = std::to_string(y + 1) + "-" + std::to_string(x + 1);

    for (int i = 0; i != len; i++) {
            if (this->elem[i].name == coor) {
                this->elem.erase(this->elem.begin()+i);
                return;
            }
        }
}

int SFML::loadMenu()
{
    int ret_value = 0;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu");
    std::string menu = "Which game do you want to load ?\nPacman : Press A\n";
    sf::Font font;
    if (!font.loadFromFile("font/Arimo-Regular.ttf")) {
        std::cout << "Couldn't load font." << std::endl;
        exit(84);
    }
    sf::Text txt(menu, font);
    txt.setCharacterSize(50);
    txt.setStyle(sf::Text::Bold);
    txt.setFillColor(sf::Color::White);
    txt.setPosition(500, 500);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            ret_value = 1;
            window.close();
        }
        window.clear();
        window.draw(txt);
        window.display();
    }
    return (ret_value);
}


void SFML::move_ghost()
{
    int dir = rand() % 4;
    int len = this->elem.size();
    sf::Vector2f pos_ghost;
    int i = 0;

    for (int y = 0; this->mapentity[y] != nullptr; y++) {
        for (int x = 0; this->mapentity[y][x] != '\0'; x++) {
            if (this->mapentity[y][x] == 'G') {
                for (; i != len; i++) {
                    if (strcmp(this->elem[i].name.c_str(), "ghost") == 0)
                        break;
                }
                if (dir == 0) {
                    if (y != 0) {
                        if (this->mapentity[y - 1][x] == 'P') {
                            this->game_over();
                            exit (0);
                        }
                        if (mapitem[y - 1][x] == '0' || mapitem[y - 1][x] == 'B') {
                            this->mapentity[y][x] = '0';
                            this->mapentity[y - 1][x] = 'G';
                            pos_ghost = this->elem[i].sprite->getPosition();
                            pos_ghost.y -= 50;
                            this->elem[i].sprite->setPosition(pos_ghost);
                            return;
                        }
                        else {
                            this->move_ghost();
                            return;
                        }
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                if (dir == 1) {
                    if (this->mapentity[y][x + 1] == 'P') {
                        this->game_over();
                        exit (0);
                    }
                    if (mapitem[y][x + 1] == '0' || mapitem[y][x + 1] == 'B') {
                        this->mapentity[y][x] = '0';
                        this->mapentity[y][x + 1] = 'G';
                        pos_ghost = this->elem[i].sprite->getPosition();
                        pos_ghost.x += 50;
                        this->elem[i].sprite->setPosition(pos_ghost);
                        return;
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                if (dir == 2) {
                    if (this->mapentity[y + 1] != nullptr) {
                        if (this->mapentity[y + 1][x] == 'P') {
                            this->game_over();
                            exit (0);
                        }
                        if (mapitem[y + 1][x] == '0' || mapitem[y + 1][x] == 'B') {
                            this->mapentity[y][x] = '0';
                            this->mapentity[y + 1][x] = 'G';
                            pos_ghost = this->elem[i].sprite->getPosition();
                            pos_ghost.y += 50;
                            this->elem[i].sprite->setPosition(pos_ghost);
                            return;
                        }
                        else {
                            this->move_ghost();
                            return;
                        }
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                if (dir == 3) {
                    if (this->mapentity[y][x - 1] == 'P') {
                        this->game_over();
                        exit (0);
                    }
                    if (mapitem[y][x - 1] == '0' || mapitem[y][x - 1] == 'B') {
                        this->mapentity[y][x] = '0';
                        this->mapentity[y][x - 1] = 'G';
                        pos_ghost = this->elem[i].sprite->getPosition();
                        pos_ghost.x -= 50;
                        this->elem[i].sprite->setPosition(pos_ghost);
                        return;
                    }
                    else {
                        this->move_ghost();
                        return;
                    }
                }
                return;
            }
        }
    }
}

void SFML::game_over()
{
    this->window.close();
    sf::Font font;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME OVER");
    std::string over = "GAME OVER.";
    std::string scre = "Your score is : " + std::to_string(this->score) + "\nHigh Score is : " + std::to_string(this->getHighScore()) +" by " + this->getNameHighScore() + "\nMake better next time";

    if (!font.loadFromFile("font/Arimo-Regular.ttf")) {
        std::cout << "Couldn't load font." << std::endl;
        exit(84);
    }

    this->setScore(this->score);
    sf::Text txt(over, font);
    txt.setCharacterSize(200);
    txt.setStyle(sf::Text::Bold);
    txt.setFillColor(sf::Color::White);
    txt.setPosition(340, 300);

    sf::Text scr(scre, font);
    scr.setCharacterSize(100);
    scr.setStyle(sf::Text::Bold);
    scr.setFillColor(sf::Color::White);
    scr.setPosition(340, 550);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        window.clear();
        window.draw(txt);
        window.draw(scr);
        window.display();
    }
}

void SFML::addBonusRandom()
{
    int free_case = 0;
    int bonus_case = 0;
    int i = 0;

    for (int y = 0; this->mapentity[y] != nullptr; y++) {
        for (int x = 0; this->mapentity[y][x] != '\0'; x++) {
            if (this->mapentity[y][x] != 'G' && this->mapentity[y][x] != 'P' && this->mapitem[y][x] == '0') {
                free_case++;
            }
        }
    }
    bonus_case = rand() % free_case + 1;
    for (int y = 0; this->mapentity[y] != nullptr; y++) {
        for (int x = 0; this->mapentity[y][x] != '\0'; x++) {
            if (this->mapentity[y][x] != 'G' && this->mapentity[y][x] != 'P' && this->mapitem[y][x] == '0') {
                i++;
            }
            if (i == bonus_case) {
                if (this->mapentity[y][x] != 'G' && this->mapentity[y][x] != 'P' && this->mapitem[y][x] == '0') {
                    this->addBonus(x + 1, y + 1);
                    return;
                }
                else {
                    this->addBonusRandom();
                    return;
                }
            }
        }
    }
}

void SFML::setScore(int score)
{
    std::string str = this->name + " : ";
    std::string old_score;
    std::vector<std::string> result;

    str += std::to_string(this->score) + "\n";
    std::ifstream ifs;
    std::ofstream ofs;
    ifs.open("score.txt", std::ofstream::out);
    getline(ifs, old_score);
    boost::split(result, old_score, boost::is_any_of(":"));
    if (result.size() == 1) {
        ofs.open("score.txt", std::ofstream::out | std::ofstream::trunc);
        ofs << str;
        ofs.close();
    }
    else if (this->score > std::stoi(result[1])) {
        ofs.open("score.txt", std::ofstream::out | std::ofstream::trunc);
        ofs << str;
        ofs.close();
    }
    ifs.close();
}

int SFML::getHighScore()
{
    std::string old_score;
    std::vector<std::string> result;

    std::ifstream ifs;
    ifs.open("score.txt", std::ofstream::out);
    getline(ifs, old_score);
    boost::split(result, old_score, boost::is_any_of(":"));
    if (result.size() == 1) {
        return (0);
    }
    else if (this->score > std::stoi(result[1])) {
        return (this->score);
    }
    else {
        return (std::stoi(result[1]));
    }
    ifs.close();
}

std::string SFML::getNameHighScore()
{
    std::string old_score;
    std::vector<std::string> result;

    std::ifstream ifs;
    ifs.open("score.txt", std::ofstream::out);
    getline(ifs, old_score);
    boost::split(result, old_score, boost::is_any_of(":"));
    if (result.size() == 1) {
        return ("");
    }
    else if (this->score > std::stoi(result[1])) {
        return (this->name);
    }
    else {
        return (result[0]);
    }
    ifs.close();
}

std::string SFML::chooselib()
{
    std::string ret_value;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu");
    std::string menu = "Choose the lib you want to play on\nSDL : Press A\nNcurses : Press B\n";
    sf::Font font;
    if (!font.loadFromFile("font/Arimo-Regular.ttf")) {
        std::cout << "Couldn't load font." << std::endl;
        exit(84);
    }
    sf::Text txt(menu, font);
    txt.setCharacterSize(50);
    txt.setStyle(sf::Text::Bold);
    txt.setFillColor(sf::Color::White);
    txt.setPosition(500, 500);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit (0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            ret_value = "./lib_arcade_sdl.so";
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            ret_value = "./lib_arcade_ncurses.so";
            window.close();
        }
        window.clear();
        window.draw(txt);
        window.display();
    }
    return (ret_value);
}