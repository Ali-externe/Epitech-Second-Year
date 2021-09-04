/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sfml3
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "../include/interface.hpp"
#include "../include/SFML.hpp"

void SFML::move_hero(std::string name, float timing)
{
    int len = this->elem.size();
    sf::Vector2f pos_hero;
    sf::Vector2f rev_hero;

    if (this->movement.getElapsedTime().asSeconds() < timing)
        return;
    this->movement.restart();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        for (int i = 0; i != len; i++) {
            if (this->elem[i].name == name) {
                if (this->moveHeroOnMap(3) == -1)
                    return;
                pos_hero = this->elem[i].sprite->getPosition();
                this->elem[i].old_pos = pos_hero;
                pos_hero.x -= 50;
                rev_hero.y = -1.f;
                rev_hero.x = 1.f;
                this->elem[i].sprite->setScale(rev_hero);
                this->elem[i].sprite->setRotation(180);
                this->elem[i].sprite->setPosition(pos_hero);
                return;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->window.close();
        this->game_over();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        for (int i = 0; i != len; i++) {
            if (this->elem[i].name == name) {
                if (this->moveHeroOnMap(1) == -1)
                    return;
                pos_hero = this->elem[i].sprite->getPosition();
                this->elem[i].old_pos = pos_hero;
                pos_hero.x += 50;
                rev_hero.y = 1.f;
                rev_hero.x = 1.f;
                this->elem[i].sprite->setScale(rev_hero);
                this->elem[i].sprite->setRotation(0);
                this->elem[i].sprite->setPosition(pos_hero);
                return;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        for (int i = 0; i != len; i++) {
            if (this->elem[i].name == name) {
                if (this->moveHeroOnMap(0) == -1)
                    return;
                pos_hero = this->elem[i].sprite->getPosition();
                this->elem[i].old_pos = pos_hero;
                pos_hero.y -= 50;
                rev_hero.y = 1.f;
                rev_hero.x = 1.f;
                this->elem[i].sprite->setScale(rev_hero);
                this->elem[i].sprite->setRotation(270);
                this->elem[i].sprite->setPosition(pos_hero);
                return;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        for (int i = 0; i != len; i++) {
            if (this->elem[i].name == name) {
                if (this->moveHeroOnMap(2) == -1)
                    return;
                pos_hero = this->elem[i].sprite->getPosition();
                this->elem[i].old_pos = pos_hero;
                pos_hero.y += 50;
                rev_hero.y = 1.f;
                rev_hero.x = 1.f;
                this->elem[i].sprite->setScale(rev_hero);
                this->elem[i].sprite->setRotation(90);
                this->elem[i].sprite->setPosition(pos_hero);
                return;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        this->window.close();
        std::string next_lib = this->chooselib();
        change_lib(next_lib);
        return;
    }

}

void SFML::collision_shape(std::string name)
{
    int len_sp = this->elem.size();
    int len_sh = this->smap.size();
    sf::Vector2f pos_hero;

    for (int i = 0; i != len_sp; i++) {
        if (this->elem[i].name == name) {
            pos_hero = this->elem[i].sprite->getPosition();
            for (int x = 0; x != len_sh; x++) {
                if (this->smap[x].rect_shape.getGlobalBounds().contains(pos_hero)) {
                    this->elem[i].sprite->setPosition(this->elem[i].old_pos);
                }
            }
        }
    }
}

void SFML::create_map2d(int x, int y)
{
    this->mapitem = (char **)malloc(sizeof(char *) * (y + 1));
    this->mapentity = (char **)malloc(sizeof(char *) * (y + 1));
    this->mapitem[y] = nullptr;
    this->mapentity[y] = nullptr;
    for (int i = 0; i != y; i++) {
        this->mapitem[i] = (char *)malloc(sizeof(char) * (x + 1));
        this->mapitem[i][x] = '\0';
        for (int a = 0; a != x; a++) {
            this->mapitem[i][a] = '0';
            this->addGround(a + 1, i + 1);
        }
        this->mapentity[i] = strdup(this->mapitem[i]);
    }
}

void SFML::addObstacle(int x, int y)
{
    int size = this->smap.size();
    int pos1 = (50 * x) - 50;
    int pos2 = (50 * y) - 50;

    if (this->mapitem == nullptr) {
        printf("Error placing Obstacle but map uninitialized.\n");
        exit(84);
    }
    if (this->mapitem[y - 1] == nullptr) {
        printf("Error placing Obstacle out of Map.\n");
        exit(84);
    }
    if (x -1 < 0) {
        printf("Error placing Obstacle out of Map.\n");
        exit(84);
    }
    if (this->mapitem[y - 1][x - 1] == '\0') {
        printf("Error placing Obstacle out of Map.\n");
        exit(84);
    }
    this->mapitem[y - 1][x - 1] = '1';
    this->smap.push_back(map());
    this->smap[size].rect_shape.setSize(sf::Vector2f(50, 50));
    this->smap[size].rect_shape.setPosition(pos1, pos2);
    this->smap[size].rect_shape.setFillColor(sf::Color::Blue);
}

void SFML::addGround(int x, int y)
{
    int size = this->smap.size();
    int pos1 = (50 * x) - 50;
    int pos2 = (50 * y) - 50;

    if (this->mapitem == nullptr) {
        printf("Error placing Ground but map uninitialized.\n");
        exit(84);
    }
    if (this->mapitem[y - 1] == nullptr) {
        printf("Error placing Ground out of Map.\n");
        exit(84);
    }
    if (x -1 < 0) {
        printf("Error placing Ground out of Map.\n");
        exit(84);
    }
    if (this->mapitem[y - 1][x - 1] == '\0') {
        printf("Error placing Ground out of Map.\n");
        exit(84);
    }
    this->mapitem[y - 1][x - 1] = '0';
    this->smap.push_back(map());
    this->smap[size].rect_shape.setSize(sf::Vector2f(50, 50));
    this->smap[size].rect_shape.setPosition(pos1, pos2);
    this->smap[size].rect_shape.setFillColor(sf::Color::White);
}
