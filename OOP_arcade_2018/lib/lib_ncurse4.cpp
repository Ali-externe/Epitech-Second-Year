/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_ncurse4
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/ncurse.hpp"
#include <curses.h>

void ncurse::addGround(int x, int y)
{
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
    this->mapitem[y - 1][x - 1] = ' ';
}

void ncurse::placeHero(int x, int y, std::string name)
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
}

int ncurse::moveHeroOnMap(int direction)
{

}

void ncurse::addBonus(int x, int y)
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
}

void ncurse::placeGhost(int x, int y)
{
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
    this->mapentity[y - 1][x - 1] = 'G';
}