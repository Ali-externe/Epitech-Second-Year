/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/interface.hpp"
#include "../include/SFML.hpp"

extern "C" SFML* create_object()
{
  return new SFML;
}

void SFML::start(std::string name, void* handle_graph, arcade *(*create)(), arcade* norne)
{
    this->handle_graph = handle_graph;
    this->name = name;
    this->window.create(sf::VideoMode(1920, 1080), "Game");
}

int SFML::create_sprite(std::string path, std::string name, int *rect)
{
    int size = this->elem.size();

    this->elem.push_back(spriteList());
    this->elem[size].name = name;
    this->elem[size].texture = new sf::Texture;
    if (!this->elem[size].texture->loadFromFile(path))
        exit(EXIT_FAILURE);
    this->elem[size].sprite = new sf::Sprite;
    this->elem[size].sprite->setTexture(*this->elem[size].texture, false);
    this->elem[size].rect.left = rect[0];
    this->elem[size].rect.top = rect[1];
    this->elem[size].rect.width = rect[2];
    this->elem[size].rect.height = rect[3];
    this->elem[size].sprite->setTextureRect(this->elem[size].rect);
    this->elem[size].sprite->setOrigin(rect[2]/2, rect[3]/2);
    return (0);
}

int SFML::window_loop()
{
    if (this->window.isOpen())
        return (1);
    return (0);
}

void SFML::window_display()
{
    this->window.display();
}

void SFML::close_window()
{
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window.close();
    }
}
