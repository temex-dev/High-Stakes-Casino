#include "main_menu.h"
#include <bits/stdc++.h>

sf::Font font("../src/rooster.ttf");


void welcome_text(sf::RenderWindow *window, const std::string message, const sf::Vector2<float> &startPos, const sf::Vector2<float> &endPos) {
    sf::Text text(font);
    text.setString(message);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::Black);
    text.setPosition(startPos);
    static sf::Clock clock;
    const float t = std::clamp(clock.getElapsedTime().asSeconds(), 0.f, 1.f);
    const float eased = t * t * (3.f - 2.f * t); // smooth start and stop

    text.setPosition({
        startPos.x + (endPos.x - startPos.x) * eased,
        startPos.y + (endPos.y - startPos.y) * eased
    });


    // final position: text.setPosition({ (WINDOW_WIDTH - text.getLocalBounds().size.x) / 2, 0.F });
    window->draw(text);
}


void mainMenu(sf::RenderWindow *window) {
    welcome_text(window, "High Stakes Casino", sf::Vector2<float>(0.f, 0.f), sf::Vector2<float>(0.f, 400.f));
}
