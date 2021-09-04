/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** getMapCoor
*/

#include "../irrlicht-1.8.4/include/irrlicht.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

#include "../include/event.hpp"
#include "../include/map.hpp"
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int getZon3D(int destx)
{
    //printf("%d\n", destx);
    switch (destx) {
        case 0:
            return (325);
            break;
        case 1:
            return (275);
            break;
        case 2:
            return (225);
            break;
        case 3:
            return (175);
            break;
        case 4:
            return (125);
            break;
        case 5:
            return (75);
            break;
        case 6:
            return (25);
            break;
        case 7:
            return (-25);
            break;
        case 8:
            return (-75);
            break;
        case 9:
            return (-125);
            break;
        case 10:
            return (-175);
            break;
        case 11:
            return (-225);
            break;
        case 12:
            return (-275);
            break;
        case 13:
            return (-325);
            break;
        case 14:
            return (-375);
            break;
        case 15:
            return (-425);
            break;
    }
}

int getXon3D(int desty)
{
    switch (desty) {
        case 0:
            return (-525);
            break;
        case 1:
            return (-475);
            break;
        case 2:
            return (-425);
            break;
        case 3:
            return (-375);
            break;
        case 4:
            return (-325);
            break;
        case 5:
            return (-275);
            break;
        case 6:
            return (-225);
            break;
        case 7:
            return (-175);
            break;
        case 8:
            return (-125);
            break;
        case 9:
            return (-75);
            break;
        case 10:
            return (-25);
            break;
        case 11:
            return (25);
            break;
        case 12:
            return (75);
            break;
        case 13:
            return (125);
            break;
        case 14:
            return (175);
            break;
        case 15:
            return (225);
            break;
        case 16:
            return (275);
            break;
        case 17:
            return (325);
            break;
        case 18:
            return (375);
            break;
        case 19:
            return (425);
            break;
        case 20:
            return (475);
            break;
        case 21:
            return (525);
            break;
    }
}

int toCaseX(int destx)
{
    int tocasex = 0;

    if (destx > 0)
        tocasex = ((destx / 50) + 11);
    else
        tocasex = ((destx / 50) + 11) - 1;
    return (tocasex);
}

int toCaseZ(int desty)
{
    int tocasey = 0;

    if (desty > 0)
        tocasey = ((-desty / 50) + 7) - 1;
    else
        tocasey = ((-desty / 50) + 7);
    return (tocasey);
}
