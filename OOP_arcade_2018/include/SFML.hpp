/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** SFML
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "interface.hpp"

typedef struct spriteList {
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Clock clock;
    sf::IntRect rect;
	std::string name;
    sf::Vector2f old_pos;
} spriteList;

typedef struct map {
    sf::RectangleShape rect_shape;
} map;

class SFML : public arcade {
    public:
        SFML(){};
		~SFML(){};
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
        sf::RenderWindow window;
        sf::Event event;
        std::vector<spriteList> elem;
        std::vector<map> smap;
        sf::Clock movement;
        char **mapitem = nullptr;
        char **mapentity = nullptr;
    protected:
    private:
};

#endif /* !SFML_HPP_ */
