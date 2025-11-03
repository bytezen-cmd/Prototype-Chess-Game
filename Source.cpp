#include "Header.h"

int main()
{
	sf::CircleShape circle(100.0f);
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Chess", sf::Style::Default, sf::State::Windowed);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		window.clear();
		window.draw(circle);
		window.display();
	}

	return 0;
}