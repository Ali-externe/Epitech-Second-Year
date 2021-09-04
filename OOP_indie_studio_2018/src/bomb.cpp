/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** bomb
*/

#include "../include/bomb.hpp"
#include "../include/map.hpp"

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
    
}

bool isBomb(int destx, int desty, std::vector<std::string> map)
{
    int tocasex = toCaseX(destx);
    int tocasey = toCaseZ(desty);

    if (map[tocasey][tocasex] == 'B' || map[tocasey][tocasex] == 'x' || map[tocasey][tocasex] == 'O')
        return (true);
    return (false);
}