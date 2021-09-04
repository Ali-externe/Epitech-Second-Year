/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** interface
*/

#ifndef INTERFACE_HPP_
    #define INTERFACE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class arcade {
	public:
        arcade(){};
		~arcade(){};
		virtual void start(std::string name, void *handle_graph, arcade *(*create)(), arcade* norne) = 0;
        virtual int create_sprite(std::string, std::string name, int *rect) = 0;
        virtual int window_loop() = 0;
        virtual void window_display() = 0;
        virtual void close_window() = 0;
        virtual void draw_sprite() = 0;
        virtual void draw_shape() = 0;
        virtual void set_animation(std::string name, float time, int inc, int reset) = 0;
        virtual void clear_window() = 0;
        virtual void create_map(int size_rect1, int size_rect2, int pos1, int pos2) = 0;
        virtual void move_hero(std::string name, float timing) = 0;
        virtual void collision_shape(std::string name) = 0;
        virtual void create_map2d(int x, int y) = 0;
        virtual void addObstacle(int x, int y) = 0;
        virtual void addGround(int x, int y) = 0;
        virtual void placeHero(int x, int y, std::string name) = 0;
        virtual int moveHeroOnMap(int direction) = 0;
        virtual void addBonus(int x, int y) = 0;
        virtual void placeGhost(int x, int y) = 0;
        virtual void dislayScore() = 0;
        virtual void destroyBonus(int x, int y) = 0;
        virtual int loadMenu() = 0;
        virtual void change_lib(std::string lib) = 0;
        virtual void move_ghost() = 0;
        virtual void game_over() = 0;
        virtual void addBonusRandom() = 0;
        virtual void setScore(int score) = 0;
        virtual int getHighScore() = 0;
        virtual std::string getNameHighScore() = 0;
        virtual std::string chooselib() = 0;
        int score = 0;
        void* handle_graph;
        arcade* (*create)();
        arcade *borne;
        std::string name = "Player";
	protected:
	private:
};

#endif /* !INTERFACE_HPP_ */
