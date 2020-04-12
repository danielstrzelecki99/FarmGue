#include "Minion.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <ctime>
#include "Gracz.h"

using namespace sf;
using namespace std;

void Minion::spawn()
{
	srand(time(NULL));
	int krawedz = (rand() % 4) + 1;
	if (krawedz == 1)
	{
		resp_x = 0;
		resp_y = (rand() % 880);
	}
	else if (krawedz == 2)
	{
		resp_x = 1122;
		resp_y = (rand() % 807);
	}
	else if (krawedz == 3)
	{
		resp_y = 0;
		resp_x = (rand() % 1200);
	}
	else if (krawedz == 4)
	{
		resp_y = 807;
		resp_x = (rand() % 1122);
	}
	sminion.setPosition(resp_x, resp_y);
}

Minion::Minion()
{
	minion.loadFromFile("XD2.png");
	sminion.setTexture(minion);
	sminion.setScale(0.2, 0.2);
	spawn();
}

void Minion::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->sminion, state);
}

void Minion::move(Gracz g)
{
	float dl;
	pozx = sminion.getPosition().x;
	pozy = sminion.getPosition().y;
	move_x = (g.px - sminion.getPosition().x);
	move_y = (g.py - sminion.getPosition().y);
	dl = sqrt((move_x)*(move_x)+(move_y)*(move_y));
	sminion.move(move_x / dl, move_y / dl);
}