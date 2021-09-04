/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sfml4
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/interface.hpp"
#include "../include/SFML.hpp"

void SFML::placeHero(int x, int y, std::string name)
{
    int len = this->elem.size();
    sf::Vector2f pos((50 * x) - 50, (50 * y) - 50);

    if (this->mapentity == nullptr) {
        printf("Error placing Hero but map uninitialized.\n");
        exit(84);
    }
    if (this->mapentity[y - 1] == nullptr) {
        printf("Error placing Hero out of Map.\n");
        exit(84);
    }
    if (x -1 < 0) {
        printf("Error placing Hero out of Map.\n");
        exit(84);
    }
    if (this->mapentity[y - 1][x - 1] == '\0') {
        printf("Error placing Hero out of Map.\n");
        exit(84);
    }
    this->mapentity[y - 1][x - 1] = 'P';
    for (int i = 0; i != len; i++) {
            if (this->elem[i].name == name) {
                pos.x += 25;
                pos.y += 25;
                this->elem[i].sprite->setPosition(pos);
                return;
            }
        }
}

int SFML::moveHeroOnMap(int direction)
{
    for (int i = 0; this->mapentity[i] != nullptr; i++) {
        for(int x = 0; this->mapentity[i][x] != '\0'; x++) {
            if (this->mapentity[i][x] == 'P') {
                if (direction == 0) {
                    if (i != 0) {
                        if (this->mapentity[i - 1][x] == 'G') {
                            this->game_over();
                            exit (0);
                        }
                        if (mapitem[i - 1][x] == '0') {
                            this->mapentity[i][x] = '0';
                            this->mapentity[i - 1][x] = 'P';
                            this->move_ghost();
                            return (1);
                        }
                        else if (mapitem[i - 1][x] == 'B') {
                            this->mapentity[i][x] = '0';
                            this->mapentity[i - 1][x] = 'P';
                            this->mapitem[i - 1][x] = '0';
                            this->score += 100;
                            this->destroyBonus(x, i - 1);
                            this->move_ghost();
                            this->addBonusRandom();
                            return (1);
                        }
                        else {
                            this->move_ghost();
                            return (-1);
                        }
                    }
                    else {
                        this->move_ghost();
                        return (-1);
                    }
                }
                else if (direction == 1) {
                    if (this->mapentity[i][x + 1] == 'G') {
                        this->game_over();
                        exit (0);
                    }
                    if (mapitem[i][x + 1] == '0') {
                        this->mapentity[i][x] = '0';
                        this->mapentity[i][x + 1] = 'P';
                        this->move_ghost();
                        return (1);
                    }
                    else if (mapitem[i][x + 1] == 'B') {
                        this->mapentity[i][x] = '0';
                        this->mapentity[i][x + 1] = 'P';
                        this->mapitem[i][x + 1] = '0';
                        this->score += 100;
                        this->destroyBonus(x + 1, i);
                        this->move_ghost();
                        this->addBonusRandom();
                        return (1);
                    }
                    else {
                        this->move_ghost();
                        return (-1);
                    }
                }
                else if (direction == 2) {
                    if (mapentity[i + 1] != nullptr) {
                        if (this->mapentity[i + 1][x] == 'G') {
                            this->game_over();
                            exit (0);
                        }
                        if (mapitem[i + 1][x] == '0') {
                            this->mapentity[i][x] = '0';
                            this->mapentity[i + 1][x] = 'P';
                            this->move_ghost();
                            return (1);
                        }
                        else if (mapitem[i + 1][x] == 'B') {
                            this->mapentity[i][x] = '0';
                            this->mapentity[i + 1][x] = 'P';
                            this->mapitem[i + 1][x] = '0';
                            this->score += 100;
                            this->destroyBonus(x, i + 1);
                            this->move_ghost();
                            this->addBonusRandom();
                            return (1);
                        }
                        else {
                            this->move_ghost();
                            return (-1);
                        }
                    }
                    else {
                        this->move_ghost();
                        return (-1);
                    }
                }
                else if (direction == 3) {
                    if (this->mapentity[i][x - 1] == 'G') {
                            this->game_over();
                            exit (0);
                    }
                    if (mapitem[i][x - 1] == '0') {
                        this->mapentity[i][x] = '0';
                        this->mapentity[i][x - 1] = 'P';
                        this->move_ghost();
                        return (1);
                    }
                    else if (mapitem[i][x - 1] == 'B') {
                        this->mapentity[i][x] = '0';
                        this->mapentity[i][x - 1] = 'P';
                        this->mapitem[i][x - 1] = '0';
                        this->score += 100;
                        this->destroyBonus(x - 1, i);
                        this->move_ghost();
                        this->addBonusRandom();
                        return (1);
                    }
                    else {
                        this->move_ghost();
                        return (-1);
                    }
                }
            }
        }
    }
}

void SFML::addBonus(int x, int y)
{
    int size = this->elem.size();
    std::string name = std::to_string(y) + "-" + std::to_string(x);
    sf::Vector2f pos((50 * x) - 50, (50 * y) - 50);

    if (this->mapentity == nullptr) {
        printf("Error placing Bonus but map uninitialized.\n");
        exit(84);
    }
    if (this->mapentity[y - 1] == nullptr) {
        printf("Error placing Bonus out of Map.\n");
        exit(84);
    }
    if (x -1 < 0) {
        printf("Error placing Bonus out of Map.\n");
        exit(84);
    }
    if (this->mapentity[y - 1][x - 1] == '\0') {
        printf("Error placing Bonus out of Map.\n");
        exit(84);
    }
    this->elem.push_back(spriteList());
    this->elem[size].name = name;
    this->elem[size].texture = new sf::Texture;
    if (!this->elem[size].texture->loadFromFile("res/bonus.png"))
        exit(EXIT_FAILURE);
    this->elem[size].sprite = new sf::Sprite;
    this->elem[size].sprite->setTexture(*this->elem[size].texture, false);
    this->elem[size].sprite->setPosition(pos);
    this->mapitem[y - 1][x - 1] = 'B';
}

void SFML::placeGhost(int x, int y)
{
    static int nb_ghost = 0;
    int size = this->elem.size();
    std::string name = "ghost";
    sf::Vector2f pos((50 * x) - 50, (50 * y) - 50);

    if (this->mapentity == nullptr) {
        printf("Error placing Ghost but map uninitialized.\n");
        exit(84);
    }
    if (this->mapentity[y - 1] == nullptr) {
        printf("Error placing Ghost out of Map.\n");
        exit(84);
    }
    if (x -1 < 0) {
        printf("Error placing Ghost out of Map.\n");
        exit(84);
    }
    if (this->mapentity[y - 1][x - 1] == '\0') {
        printf("Error placing Ghost out of Map.\n");
        exit(84);
    }
    this->elem.push_back(spriteList());
    this->elem[size].name = name;
    this->elem[size].texture = new sf::Texture;
    if (!this->elem[size].texture->loadFromFile("res/ghost.png"))
        exit(EXIT_FAILURE);
    this->elem[size].sprite = new sf::Sprite;
    this->elem[size].sprite->setTexture(*this->elem[size].texture, false);
    this->elem[size].sprite->setPosition(pos);
    this->mapentity[y - 1][x - 1] = 'G';
    nb_ghost++;
}

void SFML::dislayScore()
{
    bool one_time = false;
    sf::Font font;
    std::string score = this->name +" : " + std::to_string(this->score);

    if (one_time == false) {
        one_time = true;
        if (!font.loadFromFile("font/Arimo-Regular.ttf")) {
            std::cout << "Couldn't load font." << std::endl;
            exit(84);
        }
    }
    sf::Text txt(score, font);
    txt.setCharacterSize(30);
    txt.setStyle(sf::Text::Bold);
    txt.setFillColor(sf::Color::Red);
    txt.setPosition(1700, 0);
    this->window.draw(txt);
}
