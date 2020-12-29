#include "Punkty.h"
#include <SFML/Graphics.hpp>

using namespace std;

Punkty::Punkty()
{
	czc.loadFromFile("font.ttf");
	napis.setCharacterSize(46);
	napis.setPosition(920, 10);
	napis.setFillColor(Color::White);
	napis.setFont(czc);
	gczas.setCharacterSize(46);
	gczas.setPosition(10, 10);
	gczas.setFillColor(Color::White);
	gczas.setFont(czc);
	pause.setCharacterSize(46);
	pause.setPosition(850, 800);
	pause.setFillColor(Color::White);
	pause.setFont(czc);
	pause2.setCharacterSize(200);
	pause2.setPosition(380, 300);
	pause2.setFillColor(Color::White);
	pause2.setFont(czc);
	koniecc.setCharacterSize(46);
	koniecc.setPosition(10, 10);
	koniecc.setFillColor(Color::White);
	koniecc.setFont(czc);
}

void Punkty::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(napis, state);
	target.draw(gczas, state);
	target.draw(pause, state);
	target.draw(pause2, state);
	target.draw(koniecc, state);
}

void Punkty::update(int pkt)
{
	napis.setString("Punkty: " + to_string(pkt));
}

void Punkty::przegrana(int pkt, int timem, int times)
{
	napis.setCharacterSize(40);
	napis.setFillColor(Color::White);
	napis.setPosition(30, 490);
	if (times < 10)
	{
		napis.setString("Punkty: " + to_string(pkt) + "\n Czas gry: " + to_string(timem) + ":0" + to_string(times) + "        Spacja - zagraj ponownie");
	}
	else
	{
		napis.setString("Punkty: " + to_string(pkt) + "\n Czas gry: " + to_string(timem) + ":" + to_string(times) + "        Spacja - zagraj ponownie");
	}
}

void Punkty::czas(int& timem, int& times)
{
	if (times == 60)
	{
		times = 0;
		timem += 1;
	}
	if (times < 10)
	{
		gczas.setString("Czas gry: " + to_string(timem) + ":0" + to_string(times));
	}
	else
	{
		gczas.setString("Czas gry: " + to_string(timem) + ":" + to_string(times));
	}
}

void Punkty::vpause()
{
	pause.setString("[P] - wlacz pauze");
}

void Punkty::vpause2()
{
	pause2.setString("Pauza");
}

void Punkty::vkoniec()
{
	koniecc.setString("[Esc] - zakoncz gre");
}
