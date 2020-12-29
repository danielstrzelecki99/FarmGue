#include <SFML/Graphics.hpp>
#include <cmath>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "Minion.h"
#include "Gracz.h"
#include "Pocisk.h"
#include "Punkty.h"
#include "Sounds.h"
#include "koniec.h"
#include "info.h"

using namespace sf;
using namespace std;

int main()
{
	info i;
	i.render_info();
	while (true)
	{

		RenderWindow okno(VideoMode(1200, 880), "FarmGue");
		okno.setFramerateLimit(60);
		Texture tekstura;
		tekstura.loadFromFile("images/mapa.png");
		Sprite obrazek;
		obrazek.setTexture(tekstura);

		Minion m;
		Gracz g;
		Pocisk p;
		Sounds music, h, a, w;
		Punkty napis, gczas, pause, pause2;
		koniec k;

		vector<Pocisk>pociski;
		vector<Minion>miniony;

		bool gratrwa = true;
		bool komunikat = false;
		bool Blokada = false;
		bool Pause = false;
		bool lose = false;
		bool end = false;
		int pkt = 0;
		int timem = 0;
		int times = 0;
		int x = 0;

		w.swelcome.play();

		while (okno.isOpen())
		{
			if (lose == true)
			{
				break;
			}
			Event event;
			while (okno.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					okno.close();
					end = true;
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				{
					okno.close();
					end = true;
				}
				if (event.type == sf::Event::Resized)
					okno.setSize(sf::Vector2u(1200, 880));
				if (Blokada == false && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Blokada = true;
					p.spawn(g);
					p.movep(okno);
					pociski.insert(pociski.begin(), p);
					a.satack.play();
				}
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::P)
				{
					if (Pause == false) Pause = true;
					else Pause = false;
				}
			
			}
			if (Pause == true)
			{
				pause2.vpause2();
				okno.draw(pause2);
				okno.display();
				continue;
			}
			x++;
			if (gratrwa == false)
			{
				if (komunikat == false)
				{
					k.render(okno, napis, pkt, timem, times, end, gratrwa, lose);
					komunikat = true;
				}
				continue;
			}
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				g.py -= 6;
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				g.py += 6;
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				g.px -= 6;
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				g.px += 6;
			}
			okno.clear();

			if (x == 30 || x == 60 || x == 90 || x == 120)
			{
				Blokada = false;
			}

			if (x == 120 || x == 60)
			{
				m.spawn();
				miniony.push_back(m);
				m.acc();
				x = 0;
				times++;
			}

			okno.draw(obrazek);
			g.move();
			okno.draw(g);

			for (size_t i = 0; i < miniony.size(); i++)
			{
				miniony[i].move(g);
				okno.draw(miniony[i]);
				if (sqrt((((miniony[i].pozx + 39) - (g.pozx + 82.5))*((miniony[i].pozx + 39) - (g.pozx + 82.5))) + (((miniony[i].pozy + 35.5) - (g.pozy + 87.5))*((miniony[i].pozy + 35.5) - (g.pozy + 87.5)))) < 100)
				{
					gratrwa = false;
				}
				//okno.close();
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
					if (sqrt((((miniony[i].pozx + 39) - (pociski[j].pozx))*((miniony[i].pozx + 39) - (pociski[j].pozx))) + (((miniony[i].pozy + 35.5) - (pociski[j].pozy))*((miniony[i].pozy + 35.5) - (pociski[j].pozy)))) < 50)
					{
						h.shit.play();
						pociski.erase(pociski.begin() + j);
						miniony.erase(miniony.begin() + i);
						pkt += 10;
					}
					if (pociski.size() < 0) break;
				}
			}
			napis.update(pkt);
			gczas.czas(timem, times);
			pause.vpause();
			okno.draw(gczas);
			okno.draw(napis);
			okno.draw(pause);
			okno.display();
			cout << pociski.size() << "   " << miniony.size() << endl;
			
		}
		if (end == true) break;
	}
		return 0;
	}

