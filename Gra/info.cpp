#include "info.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

info::info()
{
	tinfo.loadFromFile("images/info.png");
	sinfo.setTexture(tinfo);
}

void info::render_info()
{
	RenderWindow oinfo(VideoMode(800, 500), "Informacje");
	oinfo.setFramerateLimit(60);
	while (oinfo.isOpen())
	{
		Event event;
		while (oinfo.pollEvent(event))
		{
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				oinfo.close();
			}
		}
		oinfo.draw(sinfo);
		oinfo.display();
	}
}
