#pragma once

#include "includes.h"
#include <algorithm>
#include <SFML/Graphics.hpp>

struct Button {
    inline static unsigned int nextID = 0;
    std::string text;
    sf::Vector2f startPos;
    sf::Vector2f endPos;
    sf::RectangleShape rect{sf::Vector2f{100.f, 50.f}};
    unsigned int ID;

    Button(const std::string& label, sf::Vector2f start, sf::Vector2f end)
        : text(label), startPos(start), endPos(end), ID(nextID++) {
        rect.setPosition(endPos);
    }
};

template<typename T>
void slide_object(sf::RenderWindow* window, sf::Vector2f startPos, sf::Vector2f endPos, T& object);
void animate_buttons(sf::RenderWindow *window, sf::Vector2f startPos, sf::Vector2f endPos, const std::string &name);
void animate_welcome_text(sf::RenderWindow *window, const std::string message, const float &startY, const float &endY);
[[nodiscard]] std::vector<Button> mainMenu(sf::RenderWindow *window);


#pragma endregion

