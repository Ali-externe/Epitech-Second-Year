#include <iostream>
#include "../include/interface.hpp"
#include "../include/sdl.hpp"
#include <stdio.h>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

extern "C" sdl* create_object()
{
	return new sdl;
}

int sdl::loadMenu() 
{ 
	int ret_val = 0;
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
	SDL_Surface *text = TTF_RenderText_Blended(font, "Click on what you want to do", White);
	SDL_Surface *text_play = TTF_RenderText_Blended(font, "Play Pacman", White);
	SDL_Surface *text_quit = TTF_RenderText_Blended(font, "Quit", White);

	while (loop) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				loop = false;
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.x >= 0 && event.button.x <= 404 && event.button.y >= 143 && event.button.y <= 218) {
					loop = false;
					ret_val = 1;
				}
				if (event.button.x >= 0 && event.button.x <= 136 && event.button.y >= 295 && event.button.y <= 370) {
					loop = false;
					ret_val = 0;
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
	return (ret_val);
} 

void sdl::start(std::string name, void* handle_graph, arcade *(*create)(), arcade* borne)
{
	SDL_Color White = {255, 255, 255};

	this->loop = true;
	this->handle_graph = handle_graph;
	this->name = name;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		exit(84);
	this->screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == nullptr)
		exit(84);
	if (TTF_Init() == -1)
		exit(84);
	this->font = TTF_OpenFont("./font/arial.ttf", 65);
	this->text_score = TTF_RenderText_Blended(this->font, "Score : ", White);
	this->bonus = SDL_LoadBMP("./res/bonus.bmp");
	this->ghost = SDL_LoadBMP("./res/ghost.bmp");
}

int sdl::create_sprite(std::string, std::string name, int *rect)
{
	SDL_Rect pos_hero;

	this->pos_hero.x = 0;
	this->pos_hero.y = 0;
	this->hero = SDL_LoadBMP("./res/pacman1.bmp");
	return (0);
}

int sdl::window_loop()
{
	if (this->loop == true)
		return (1);
	else {
		TTF_CloseFont(this->font);
		TTF_Quit();
		SDL_Quit();
		this->game_over();
	}
	return (0);
}

void sdl::window_display()
{
  return;
}