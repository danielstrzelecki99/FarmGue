#include <SFML/Graphics.hpp>
#include <cmath>
#include "Minion.h"
#include <Windows.h>
#include <vector>
#include "Gracz.h"
#include "Pocisk.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	vector<Minion>miniony;
	int x = 0;
	Minion m;
	Gracz g;
	Pocisk p;
	vector<Pocisk>pociski;
	RenderWindow okno(VideoMode(1200, 880), "FarmGue");
	okno.setFramerateLimit(60);
	Texture tekstura;
	tekstura.loadFromFile("XD.png");
	Sprite obrazek;
	obrazek.setTexture(tekstura);
	bool Blokada = false;


	while (okno.isOpen())
	{
		x++;
		Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
				okno.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				okno.close();
			if (Blokada == false && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Blokada = true;
				p.spawn(g);
				p.movep(okno);
				pociski.insert(pociski.begin(), p);
			}
			//else if (Blokada == true && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
			//{
				//Blokada = false;
			//}
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			g.py -= 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			g.py += 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			g.px -= 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			g.px += 5;
		}
		okno.clear();

		if (x % 60 == 0) Blokada = false;

		
		if (x == 120)
		{
			m.spawn();
			miniony.push_back(m);
			x = 0;
		}

		okno.draw(obrazek);
		g.move();
		okno.draw(g);
		for (size_t i = 0; i < miniony.size(); i++)
		{
			miniony[i].move(g);
			okno.draw(miniony[i]);
		}
		for (size_t i = 0; i < pociski.size(); i++)
		{
			pociski[i].update();
			okno.draw(pociski[i]);
			if (pociski[i].pozx < 0)
				pociski.erase(pociski.begin() + i);
			else if (pociski[i].pozx > 1200)
				pociski.erase(pociski.begin() + i);
			else if (pociski[i].pozy < 0)
				pociski.erase(pociski.begin() + i);
			else if (pociski[i].pozy > 880)
				pociski.erase(pociski.begin() + i);
		}
		for (size_t i = 0; i < miniony.size(); i++)
		{
			for (size_t j = 0; j < pociski.size(); j++)
			{
				if (sqrt((((miniony[i].pozx+39) - (pociski[j].pozx))*((miniony[i].pozx+39) - (pociski[j].pozx))) + (((miniony[i].pozy+35.5) - (pociski[j].pozy))*((miniony[i].pozy+35.5) - (pociski[j].pozy)))) < 50)
				{
					pociski.erase(pociski.begin() + j);
					miniony.erase(miniony.begin() + i);
				}
				if (pociski.size() < 0) break;
			}
		}
		

		okno.display();
		cout << pociski.size() << "   " << miniony.size() << endl;
	}
	return 0;
}
