#pragma once

#include "includes.h"

void welcome_text(
    sf::RenderWindow *window,
    const std::string message,
    const sf::Vector2<float> &startPos,
    const sf::Vector2<float> &endPos
);

void mainMenu(sf::RenderWindow *window);
