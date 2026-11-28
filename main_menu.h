#pragma once

#include "includes.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <SFML/Graphics.hpp>

struct Button {
    inline static unsigned int nextID = 0;
    sf::Text text;
    sf::Vector2f startPos;
    sf::Vector2f endPos;
    sf::RectangleShape rect{sf::Vector2f{100.f, 50.f}};
    unsigned int ID;

    Button(sf::Text text, sf::Vector2f start, sf::Vector2f end)
        : text(text), startPos(start), endPos(end), ID(nextID++) {
        rect.setPosition(endPos);
    }
};

template<typename T>
void slide_object(sf::Vector2f startPos, sf::Vector2f endPos, T& object, sf::Clock& clock);
void animate_buttons(sf::RenderWindow *window, sf::Vector2f startPos, sf::Vector2f endPos, const std::string &name);
void animate_welcome_text(sf::RenderWindow *window, const std::string message, const float &startY, const float &endY);
[[nodiscard]] std::vector<Button> mainMenu(sf::RenderWindow *window);
void handleMousePressed(sf::RenderWindow *window, std::vector<Button> &buttons, const sf::Vector2f &mousePos);
std::vector<Button> mainMenu(sf::RenderWindow *window);
#pragma endregion

