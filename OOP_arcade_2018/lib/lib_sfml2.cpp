/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** lib_sfml2
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/interface.hpp"
#include "../include/SFML.hpp"

void SFML::draw_sprite()
{
    int len = this->elem.size();

    for (int i = 0; i != len; i++)
        window.draw(*this->elem[i].sprite);
}

void SFML::draw_shape()
{
    int len = this->smap.size();

    for (int i = 0; i != len; i++)
        window.draw(this->smap[i].rect_shape);
}

void SFML::set_animation(std::string name, float time, int inc, int reset)
{
    int len = this->elem.size();

    for (int i = 0; i != len; i++) {
        if (this->elem[i].name == name) {
            if (this->elem[i].clock.getElapsedTime().asSeconds() > time) {
                if (this->elem[i].rect.left >= reset)
                    this->elem[i].rect.left = 0;
                else
                    this->elem[i].rect.left += inc;
                this->elem[i].clock.restart();
                this->elem[i].sprite->setTextureRect(this->elem[i].rect);

            }
            return;
        }
    }
}

void SFML::clear_window()
{
    this->window.clear();
}

void SFML::create_map(int size_rect1, int size_rect2, int pos1, int pos2)
{
    int size = this->smap.size();

    this->smap.push_back(map());
    this->smap[size].rect_shape.setSize(sf::Vector2f(size_rect1, size_rect2));
    this->smap[size].rect_shape.setPosition(pos1, pos2);
    this->smap[size].rect_shape.setFillColor(sf::Color::Blue);
}