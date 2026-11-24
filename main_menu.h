#pragma once

#include "includes.h"
#include <algorithm>
#include <SFML/Graphics.hpp>

struct button {
    std::string *text;
    sf::RectangleShape *rect;
};

template<typename T>
void slide_object(sf::RenderWindow* window, sf::Vector2f startPos, sf::Vector2f endPos, T& object);
void animate_buttons(sf::RenderWindow *window, sf::Vector2f startPos, sf::Vector2f endPos, const std::string &name);
void animate_welcome_text(sf::RenderWindow *window, const std::string message, const float &startY, const float &endY);
void mainMenu(sf::RenderWindow *window);


#pragma endregion

