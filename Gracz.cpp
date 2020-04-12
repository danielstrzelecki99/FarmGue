#include "Gracz.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <ctime>

using namespace sf;
using namespace std;

Gracz::Gracz()
{
	gracz.loadFromFile("XD3.png");
	sgracz.setTexture(gracz);
	sgracz.setScale(0.5, 0.5);
	sgracz.setPosition(gresp_x = 600, gresp_y = 440);
}

void Gracz::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->sgracz, state);
}

void Gracz::move()
{
	sgracz.setPosition(px, py);
	if (sgracz.getPosition().x < 0)
		px = 0;
	if (sgracz.getPosition().x > 1034.5)
		px = 1034.5;
	if (sgracz.getPosition().y < 0)
		py = 0;
	if (sgracz.getPosition().y > 705)
		py = 705;
}