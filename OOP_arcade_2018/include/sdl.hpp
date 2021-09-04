/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "interface.hpp"
#include <iostream>
#include <time.h>
#include<SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

class sdl : public arcade {
    public:
        sdl(){};
        ~sdl(){};
        void start(std::string name, void* handle_graph, arcade *(*create)(), arcade* norne);
        int create_sprite(std::string, std::string name, int *rect);
        int window_loop();
        void window_display();
        void close_window();
        void draw_sprite();
        void draw_shape();
        void set_animation(std::string name, float time, int inc, int reset);
        void clear_window();
        void create_map(int size_rect1, int size_rect2, int pos1, int pos2);
        void move_hero(std::string name, float timing);
        void collision_shape(std::string name);
        void create_map2d(int x, int y);
        void addObstacle(int x, int y);
        void addGround(int x, int y);
        void placeHero(int x, int y, std::string name);
        int moveHeroOnMap(int direction);
        void addBonus(int x, int y);
        void placeGhost(int x, int y);
        void dislayScore();
        void destroyBonus(int x, int y);
        int loadMenu();
        void change_lib(std::string lib);
        void move_ghost();
        void game_over();
        void addBonusRandom();
        void setScore(int score);
        int getHighScore();
        std::string getNameHighScore();
        std::string chooselib();
        char **mapitem = nullptr;
        char **mapentity = nullptr;
        char **final_map = nullptr;
        SDL_Surface *screen;
        SDL_Surface *hero;
        SDL_Surface *bonus;
        SDL_Surface *ghost;
        TTF_Font *font;
        SDL_Surface *text_score;
        SDL_Event event;
        SDL_Rect pos_hero;
        SDL_Rect pos_bonus;
        SDL_Rect pos_ghost;
        bool loop;
        clock_t clock;
        float elapsed = 0;
    protected:
    private:
};

#endif /* !SDL_HPP_ */
