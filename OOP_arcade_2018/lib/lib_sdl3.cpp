#include <iostream>
#include "../include/interface.hpp"
#include "../include/sdl.hpp"
#include <stdio.h>

void sdl::create_map(int size_rect1, int size_rect2, int pos1, int pos2)
{
    return;
}

void sdl::move_hero(std::string name, float timing)
{
    SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                loop = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        loop = false;
                        break;
                    case SDLK_UP:
                        for (int i = 0; this->mapentity[i] != nullptr; i++) {
                            for(int x = 0; this->mapentity[i][x] != '\0'; x++) {
                                if (this->mapentity[i][x] == 'P') {
                                    if (i != 0) {
                                        if (this->mapentity[i - 1][x] == 'G') {
                                            this->loop = false;
                                            return;
                                        }
                                        if (mapitem[i - 1][x] == ' ') {
                                            this->mapentity[i][x] = ' ';
                                            this->mapentity[i - 1][x] = 'P';
                                            this->pos_hero.x = (x * 50);
                                            this->pos_hero.y = ((i - 1) * 50);
                                            this->move_ghost();
                                            return;
                                        }
                                        else if (mapitem[i - 1][x] == 'B') {
                                            this->mapentity[i][x] = ' ';
                                            this->mapentity[i - 1][x] = 'P';
                                            this->mapitem[i - 1][x] = ' ';
                                            this->pos_hero.x = (x * 50);
                                            this->pos_hero.y = ((i - 1) * 50);
                                            this->score += 100;
                                            this->move_ghost();
                                            this->addBonusRandom();
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
                            }
                        }
                        break;
                    case SDLK_RIGHT:
                        for (int i = 0; this->mapentity[i] != nullptr; i++) {
                            for(int x = 0; this->mapentity[i][x] != '\0'; x++) {
                                if (this->mapentity[i][x] == 'P') {
                                    if (this->mapentity[i][x + 1] == 'G') {
                                        this->loop = false;
                                        return;
                                    }
                                    if (mapitem[i][x + 1] == ' ') {
                                        this->mapentity[i][x] = ' ';
                                        this->mapentity[i][x + 1] = 'P';
                                        this->pos_hero.x = ((x + 1) * 50);
                                        this->pos_hero.y = (i * 50);
                                        this->move_ghost();
                                        return;
                                    }
                                    else if (mapitem[i][x + 1] == 'B') {
                                        this->mapentity[i][x] = ' ';
                                        this->mapentity[i][x + 1] = 'P';
                                        this->mapitem[i][x + 1] = ' ';
                                        this->pos_hero.x = ((x + 1) * 50);
                                        this->pos_hero.y = (i * 50);
                                        this->score += 100;
                                        this->move_ghost();
                                        this->addBonusRandom();
                                        return;
                                    }
                                    else {
                                        this->move_ghost();
                                        return;
                                    }
                                }
                            }
                        }
                        break;
                    case SDLK_DOWN:
                        for (int i = 0; this->mapentity[i] != nullptr; i++) {
                            for(int x = 0; this->mapentity[i][x] != '\0'; x++) {
                                if (this->mapentity[i][x] == 'P') {
                                    if (mapentity[i + 1] != nullptr) {
                                        if (this->mapentity[i + 1][x] == 'G') {
                                            this->loop = false;
                                            return;
                                        }
                                        if (mapitem[i + 1][x] == ' ') {
                                            this->mapentity[i][x] = ' ';
                                            this->mapentity[i + 1][x] = 'P';
                                            this->pos_hero.x = (x * 50);
                                            this->pos_hero.y = ((i + 1) * 50);
                                            this->move_ghost();
                                            return;
                                        }
                                        else if (mapitem[i + 1][x] == 'B') {
                                            this->mapentity[i][x] = ' ';
                                            this->mapentity[i + 1][x] = 'P';
                                            this->mapitem[i + 1][x] = ' ';
                                            this->pos_hero.x = (x * 50);
                                            this->pos_hero.y = ((i + 1) * 50);
                                            this->score += 100;
                                            this->move_ghost();
                                            this->addBonusRandom();
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
                            }
                        }
                        break;
                    case SDLK_LEFT:
                        for (int i = 0; this->mapentity[i] != nullptr; i++) {
                            for(int x = 0; this->mapentity[i][x] != '\0'; x++) {
                                if (this->mapentity[i][x] == 'P') {
                                    if (this->mapentity[i][x - 1] == 'G') {
                                        this->loop = false;
                                        return;
                                    }
                                    if (mapitem[i][x - 1] == ' ') {
                                        this->mapentity[i][x] = ' ';
                                        this->mapentity[i][x - 1] = 'P';
                                        this->pos_hero.x = ((x - 1) * 50);
                                        this->pos_hero.y = (i * 50);
                                        this->move_ghost();
                                        return;
                                    }
                                    else if (mapitem[i][x - 1] == 'B') {
                                        this->mapentity[i][x] = ' ';
                                        this->mapentity[i][x - 1] = 'P';
                                        this->mapitem[i][x - 1] = ' ';
                                        this->pos_hero.x = ((x - 1) * 50);
                                        this->pos_hero.y = (i * 50);
                                        this->score += 100;
                                        this->move_ghost();
                                        this->addBonusRandom();
                                        return;
                                    }
                                    else {
                                        this->move_ghost();
                                        return;
                                    }
                                }
                            }
                        }
                        break;
                    case SDLK_g:
                        TTF_CloseFont(this->font);
                        TTF_Quit();
                        SDL_Quit();
                        std::string next_lib = this->chooselib();
                        this->change_lib(next_lib);
                        break;
                }
                break;
        }
    return;
}

void sdl::collision_shape(std::string name)
{
    return;
}

void sdl::create_map2d(int x, int y)
{
    this->mapitem = (char **)malloc(sizeof(char *) * (y + 1));
    this->mapentity = (char **)malloc(sizeof(char *) * (y + 1));
    this->final_map = (char **)malloc(sizeof(char *) * (y + 1));
    this->mapitem[y] = nullptr;
    this->mapentity[y] = nullptr;
    this->final_map[y] = nullptr;
    for (int i = 0; i != y; i++) {
        this->mapitem[i] = (char *)malloc(sizeof(char) * (x + 1));
        this->mapitem[i][x] = '\0';
        for (int a = 0; a != x; a++) {
            this->mapitem[i][a] = ' ';
            this->addGround(a + 1, i + 1);
        }
        this->mapentity[i] = strdup(this->mapitem[i]);
        this->final_map[i] = strdup(this->mapitem[i]);
    }
    return;
}

void sdl::addObstacle(int x, int y)
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
    this->mapitem[y - 1][x - 1] = 'o';
    return;
}