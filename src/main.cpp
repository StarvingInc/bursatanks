#include "render.h"

int main(int argc, char* argv[])
{
	Config config; 

	sf::RenderWindow window(config.getvideomode(), "window");

	Game game;

	sf::Clock clock();
	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		if(clock.getElapsedTime().asMilliseconds() > config.getTurnDuration())
		{
			clock.restart();
			game.nextturn();
			render(RenderWindow &window, Game &game);
		}
	}
}
