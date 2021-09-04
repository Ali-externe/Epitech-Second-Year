/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sdl2
*/

#include <iostream>
#include "../include/interface.hpp"
#include "../include/sdl.hpp"
#include <stdio.h>

void sdl::close_window()
{
    return;
}

void sdl::draw_sprite()
{
    return;
}

void sdl::draw_shape()
{
    return;
}

void sdl::set_animation(std::string name, float time, int inc, int reset)
{
    return;
}

char **assemble_maps(char **first, char**second, char **res)
{
  for (int i = 0; res[i] != nullptr; i++) {
    for (int x = 0; res[i][x] != '\0'; x++) {
      if (second[i][x] == 'P' || second [i][x] == 'G')
        res[i][x] = second[i][x];
      else if (first[i][x] == 'B')
        res[i][x] = 'B';
      else if (first[i][x] == 'o')
        res[i][x] = 'o';
      else if (first[i][x] == ' ')
        res[i][x] = ' ';
    }
  }
  return (res);
}

void sdl::clear_window()
{
    SDL_Rect pos_shape;
    SDL_Color White = {255, 255, 255};
    SDL_Rect pos_text;
    std::string score_str = this->name + " : " + std::to_string(this->score);
    SDL_Surface *shape = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);

    pos_text.x = 1300;
	pos_text.y = 0;
    this->text_score = TTF_RenderText_Blended(this->font, score_str.c_str(), White);
    SDL_FillRect(this->screen, nullptr, SDL_MapRGB(this->screen->format, 0, 0, 0));
    this->final_map = assemble_maps(this->mapitem, this->mapentity, this->final_map);
    for (int i = 0, h = 0; this->final_map[i] != nullptr; i++, h += 50) {
        for (int j = 0, g = 0; this->final_map[i][j] != '\0'; j++, g += 50) {
            pos_shape.y = h;
            pos_shape.x = g;
            if (this->final_map[i][j] == 'o') {
                SDL_FillRect(shape, NULL, SDL_MapRGB(this->screen->format, 0, 0, 255)); 
            }
            else if (this->final_map[i][j] == ' ') {
                SDL_FillRect(shape, NULL, SDL_MapRGB(this->screen->format, 255, 255, 255)); 
            }
            SDL_BlitSurface(shape, NULL, this->screen, &pos_shape);
        }
    }
    SDL_BlitSurface(this->bonus, nullptr, this->screen, &this->pos_bonus);
    SDL_BlitSurface(this->ghost, nullptr, this->screen, &this->pos_ghost);
    SDL_BlitSurface(this->hero, nullptr, this->screen, &this->pos_hero);
    SDL_BlitSurface(this->text_score, nullptr, this->screen, &pos_text);
    SDL_Flip(this->screen);
}