#include "includes.h"
#include "main_menu.h"

int main() {
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 0;


	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "High Stakes Casino", sf::Style::Close, sf::State::Windowed);


	std::vector<Button> buttons = mainMenu(&window);
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();

			if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
				const sf::Vector2f mousePos{
            	static_cast<float>(mouseButtonPressed->position.x),
            	static_cast<float>(mouseButtonPressed->position.y) };

				handleMousePressed(&window, buttons, mousePos);
			}
		}

		window.clear(sf::Color(0, 255, 0));
		static_cast<void>(mainMenu(&window));
		window.display();
	}

	return 0;
}
