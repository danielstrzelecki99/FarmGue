#include "Punkty.h"
#include <SFML/Graphics.hpp>

using namespace std;

Punkty::Punkty()
{
	czc.loadFromFile("font.ttf") ;
	napis.setCharacterSize(46);
	napis.setPosition(920, 10);
	napis.setFillColor(Color::Black);
	napis.setFont(czc);
}

void Punkty::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(napis, state);
}

void Punkty::update(int pkt)
{
	napis.setString("Punkty: " + to_string(pkt));
}

void Punkty::przegrana(int pkt)
{
	napis.setCharacterSize(70);
	napis.setFillColor(Color::White);
	napis.setPosition(450, 260);
	napis.setString("PRZEGRANA\n Punkty: " + to_string(pkt));
}
