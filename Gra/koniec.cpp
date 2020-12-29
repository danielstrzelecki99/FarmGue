#include "koniec.h"
#include <SFML/Graphics.hpp>
#include "Punkty.h"
#include <iostream>

using namespace sf;
using namespace std;

koniec::koniec()
{
	tkoniec.loadFromFile("images/koniec.png");
	skoniec.setTexture(tkoniec);
}

void koniec::render(RenderWindow &okno, Punkty napis, int &pkt, int &timem, int &times, bool &end, bool gratrwa, bool &lose)
{
	RenderWindow zakonczenie(VideoMode(800, 600), "Game Over");
	zakonczenie.setFramerateLimit(60);
	while (zakonczenie.isOpen())
	{
		Event event;
		while (zakonczenie.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				zakonczenie.close();
				okno.close();
				end = true;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			{
				zakonczenie.close();
				okno.close();
				end = true;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && gratrwa == false)
			{
				lose = true;
				zakonczenie.close();
			}
		}
		napis.update(pkt);
		napis.przegrana(pkt, timem, times);
		napis.vkoniec();
		zakonczenie.draw(skoniec);
		zakonczenie.draw(napis);
		zakonczenie.display();
	}
}
