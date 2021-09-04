/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sdl4
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/sdl.hpp"
#include <stdio.h>

void sdl::addGround(int x, int y)
{
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
    this->mapitem[y - 1][x - 1] = ' ';
    return;
}

void sdl::placeHero(int x, int y, std::string name)
{
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
    this->pos_hero.x = (x * 50) - 50;
    this->pos_hero.y = (y * 50) - 50;
    return;
}

int sdl::moveHeroOnMap(int direction)
{

}

void sdl::addBonus(int x, int y)
{
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
    this->mapitem[y - 1][x - 1] = 'B';
    this->pos_bonus.x = (x * 50) - 50;
    this->pos_bonus.y = (y * 50) - 50;
    return;
}

void sdl::placeGhost(int x, int y)
{
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
    this->mapentity[y - 1][x - 1] = 'G';
    this->pos_ghost.x = (x * 50) - 50;
    this->pos_ghost.y = (y * 50) - 50;
    return;
}