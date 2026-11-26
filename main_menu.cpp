#include "main_menu.h"
#include "includes.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

sf::Font font_welcome("../src/rooster.ttf");
sf::Font font_btn("../src/quip.otf");

template<typename T>
void slide_object(sf::RenderWindow* window, sf::Vector2f startPos, sf::Vector2f endPos, T& object) {
    static sf::Clock clock;
    const float t = std::clamp(clock.getElapsedTime().asSeconds(), 0.f, 1.f);
    const float eased = t * t * (3.f - 2.f * t);

    float xPos = startPos.x + (endPos.x - startPos.x) * eased;
    float yPos = startPos.y + (endPos.y - startPos.y) * eased;

    object.setPosition({ xPos, yPos });
}

void animate_welcome_text(sf::RenderWindow *window, const std::string message, const float &startY, const float &endY) {
    sf::Text text(font_welcome);
    text.setString(message);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::Black);

    const float textWidth = text.getLocalBounds().size.x;
    const float centerX = (WINDOW_WIDTH - textWidth) / 2.f;

    slide_object(window, { centerX, startY }, { centerX, endY }, text);

    window->draw(text);
}

void animate_buttons(sf::RenderWindow *window, sf::Vector2f startPos, sf::Vector2f endPos, const std::string &name) {
    sf::RectangleShape btn({ 100.f, 50.f });
    btn.setFillColor(sf::Color::Red);
    btn.setOutlineColor(sf::Color::Black);
    btn.setOutlineThickness(2.f);
    btn.setPosition(startPos);

    sf::Text text(font_btn);
    text.setString(name);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Black);

    const sf::FloatRect textBounds = text.getLocalBounds();
    const sf::Vector2f textOffset{
        (btn.getSize().x - textBounds.size.x) / 2.f - textBounds.position.x,
        (btn.getSize().y - textBounds.size.y) / 2.f - textBounds.position.y
    };

    slide_object(window, startPos + textOffset, endPos + textOffset, text);
    slide_object(window, {startPos.x, startPos.y}, {endPos.x, endPos.y}, btn);

    window->draw(btn);
    window->draw(text);
}

std::vector<Button> mainMenu(sf::RenderWindow *window) {
    std::vector<Button> buttons;
    animate_welcome_text(window, "High Stakes Casino", -100.f, 10.f);

    Button btn1{ "test", {450.f, WINDOW_HEIGHT + 100.f }, { 450.f, WINDOW_HEIGHT - 100.f } };
    buttons.push_back(btn1);

    animate_buttons(window, btn1.startPos, btn1.endPos, btn1.text);

    return buttons;
}
