#include "main_menu.h"
#include <algorithm>

sf::Font font("../src/rooster.ttf");


void welcome_text(sf::RenderWindow *window, const std::string message, const float &startY, const float &endY) {
    sf::Text text(font);
    text.setString(message);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::Black);

    const float textWidth = text.getLocalBounds().size.x;
    const float centerX = (WINDOW_WIDTH - textWidth) / 2.f;

    static sf::Clock clock;
    const float t = std::clamp(clock.getElapsedTime().asSeconds(), 0.f, 1.f);
    const float eased = t * t * (3.f - 2.f * t); // smooth start and stop

    text.setPosition({
        centerX,
        startY + (endY - startY) * eased
    });

    window->draw(text);
}


void mainMenu(sf::RenderWindow *window) {
    welcome_text(window, "High Stakes Casino", -100.f, 10.f);
}
