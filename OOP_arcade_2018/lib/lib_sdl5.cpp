/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sdl5
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/sdl.hpp"
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>
#define MAP_X 21
#define MAP_Y 19

void sdl::dislayScore()
{
    return;
}

void sdl::destroyBonus(int x, int y)
{
    return;
}

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

void sdl::change_lib(std::string lib)
{
    int rect_pacman[] = {0, 0, 50, 50};
    //lib = "./lib_arcade_sfml.so";
    name = this->name;

    //dlclose(this->handle_graph);
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
    exit(0);
}

void sdl::move_ghost()
{
    int dir = rand() % 4;

    for (int y = 0; this->mapentity[y] != nullptr; y++) {
        for (int x = 0; this->mapentity[y][x] != '\0'; x++) {
            if (this->mapentity[y][x] == 'G') {
                if (dir == 0) {
                    if (y != 0) {
                        if (this->mapentity[y - 1][x] == 'P') {
                            this->loop = false;
                            return;
                        }
                        if (mapitem[y - 1][x] == ' ' || mapitem[y - 1][x] == 'B') {
                            this->mapentity[y][x] = ' ';
                            this->mapentity[y - 1][x] = 'G';
                            this->pos_ghost.x = (x * 50);
                            this->pos_ghost.y = ((y - 1) * 50);
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
                        this->loop = false;
                        return;
                    }
                    if (mapitem[y][x + 1] == ' ' || mapitem[y][x + 1] == 'B') {
                        this->mapentity[y][x] = ' ';
                        this->mapentity[y][x + 1] = 'G';
                        this->pos_ghost.x = ((x + 1) * 50);
                        this->pos_ghost.y = (y * 50);
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
                            this->loop = false;
                            return;
                        }
                        if (mapitem[y + 1][x] == ' ' || mapitem[y + 1][x] == 'B') {
                            this->mapentity[y][x] = ' ';
                            this->mapentity[y + 1][x] = 'G';
                            this->pos_ghost.x = (x * 50);
                            this->pos_ghost.y = ((y + 1) * 50);
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
                        this->loop = false;
                        return;
                    }
                    if (mapitem[y][x - 1] == ' ' || mapitem[y][x - 1] == 'B') {
                        this->mapentity[y][x] = ' ';
                        this->mapentity[y][x - 1] = 'G';
                        this->pos_ghost.x = ((x - 1) * 50);
                        this->pos_ghost.y = (y * 50);
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

void sdl::game_over()
{
    std::string high_score = "High Score is : " + std::to_string(this->getHighScore());
    std::string your_score = "Your score is : " + std::to_string(this->score);
    std::string total_score = your_score + " | " + high_score;
	bool loop = true;
	SDL_Event event;
	SDL_Color White = {255, 255, 255};
	SDL_Rect pos_text;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		exit(84);
	SDL_Surface *screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == nullptr)
		exit(84);
	if (TTF_Init() == -1)
		exit(84);
	TTF_Font *font = TTF_OpenFont("./font/arial.ttf", 65);
	SDL_Surface *text = TTF_RenderText_Blended(font, "Game Over", White);
	SDL_Surface *text_play = TTF_RenderText_Blended(font, total_score.c_str(), White);
	SDL_Surface *text_quit = TTF_RenderText_Blended(font, "Quit", White);

	while (loop) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				loop = false;
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.x >= 0 && event.button.x <= 136 && event.button.y >= 295 && event.button.y <= 370) {
					loop = false;
				}
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						loop = false;
						break;
				}
				break;
		}
		pos_text.x = 0;
		pos_text.y = 0;
		SDL_BlitSurface(text, nullptr, screen, &pos_text);
		pos_text.x = 0;
		pos_text.y = 150;
		SDL_BlitSurface(text_play, nullptr, screen, &pos_text);
		pos_text.x = 0;
		pos_text.y = 300;
		SDL_BlitSurface(text_quit, nullptr, screen, &pos_text);
		SDL_Flip(screen);
	}
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
    exit (0);
    return;
}

void sdl::addBonusRandom()
{
    int free_case = 0;
    int bonus_case = 0;
    int i = 0;

    for (int y = 0; this->mapentity[y] != nullptr; y++) {
        for (int x = 0; this->mapentity[y][x] != '\0'; x++) {
            if (this->mapentity[y][x] != 'G' && this->mapentity[y][x] != 'P' && this->mapitem[y][x] == ' ') {
                free_case++;
            }
        }
    }
    bonus_case = rand() % free_case + 1;
    for (int y = 0; this->mapentity[y] != nullptr; y++) {
        for (int x = 0; this->mapentity[y][x] != '\0'; x++) {
            if (this->mapentity[y][x] != 'G' && this->mapentity[y][x] != 'P' && this->mapitem[y][x] == ' ') {
                i++;
            }
            if (i == bonus_case) {
                if (this->mapentity[y][x] != 'G' && this->mapentity[y][x] != 'P' && this->mapitem[y][x] == ' ') {
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
    return;
}

void sdl::setScore(int score)
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

int sdl::getHighScore()
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

std::string sdl::getNameHighScore()
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

std::string sdl::chooselib()
{
    std::string ret;
    bool loop = true;
	SDL_Event event;
	SDL_Color White = {255, 255, 255};
	SDL_Rect pos_text;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		exit(84);
	SDL_Surface *screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == nullptr)
		exit(84);
	if (TTF_Init() == -1)
		exit(84);
	TTF_Font *font = TTF_OpenFont("./font/arial.ttf", 65);
	SDL_Surface *text = TTF_RenderText_Blended(font, "Choose the lib you want to play on", White);
	SDL_Surface *text_play = TTF_RenderText_Blended(font, "A = SFML", White);
	SDL_Surface *text_quit = TTF_RenderText_Blended(font, "B = ncurse", White);

	while (loop) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				loop = false;
                TTF_CloseFont(font);
                TTF_Quit();
                SDL_Quit();
                exit (0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_a:
                        ret = "./lib_arcade_sfml.so";
						loop = false;
						break;
                    case SDLK_b:
                        ret = "./lib_arcade_ncurses.so";
						loop = false;
						break;
				}
				break;
		}
		pos_text.x = 0;
		pos_text.y = 0;
		SDL_BlitSurface(text, nullptr, screen, &pos_text);
		pos_text.x = 0;
		pos_text.y = 150;
		SDL_BlitSurface(text_play, nullptr, screen, &pos_text);
		pos_text.x = 0;
		pos_text.y = 300;
		SDL_BlitSurface(text_quit, nullptr, screen, &pos_text);
		SDL_Flip(screen);
	}
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
    return (ret);
}