#include "includes.h"
#include "main_menu.h"

int main() {
	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "High Stakes Casino", sf::Style::Close, sf::State::Windowed);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear(sf::Color(0, 100, 0));
		mainMenu(&window);
		window.display();
	}

	return 0;
}
