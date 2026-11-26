#include "includes.h"
#include "main_menu.h"

int main() {
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 0;


	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "High Stakes Casino", sf::Style::Close, sf::State::Windowed);

	window.clear(sf::Color(0, 255, 0));
	std::vector<Button> buttons = mainMenu(&window);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();

			if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
				const sf::Vector2f mousePos{
            	static_cast<float>(mouseButtonPressed->position.x),
            	static_cast<float>(mouseButtonPressed->position.y) };

				for (const auto& btn : buttons) {
					if (btn.rect.getGlobalBounds().contains(mousePos)) {
						switch(btn.ID) {
							case 0:
								window.close();
								break;
						default:
							break;
						}
					}
				}
			}
		}
		window.display();
	}

	return 0;
}
