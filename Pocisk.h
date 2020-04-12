#pragma once
#include <SFML/Graphics.hpp>
#include "Gracz.h"

using namespace sf;
using namespace std;

class Pocisk :public Drawable
{
private:
	CircleShape pocisk;
	float move_x, move_y, dl;
public:
	float resp_x, resp_y, px, py;
	float pozx, pozy;
	void draw(RenderTarget& target, RenderStates state) const override;
	Pocisk();
	Pocisk(float x, float y);
	void movep(RenderWindow& okno);
	void spawn(Gracz g);
	void update();
	
};

//jebac disa
//syna diabła
