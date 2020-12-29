#pragma once
#include <SFML/Graphics.hpp>
#include "Punkty.h"

using namespace sf;
using namespace std;

class koniec
{
	public:
		Sprite skoniec;
		Texture tkoniec;
		koniec();
		void render(RenderWindow &okno, Punkty napis, int &pkt, int &timem, int &times, bool &end, bool gratrwa, bool &lose);
};

