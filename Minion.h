#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Gracz.h"

using namespace sf;
using namespace std;

class Minion :public Drawable
{
private:
	bool alive;
	int speed = 1;
	float resp_x;
	float resp_y;


public:
	float move_x;
	float move_y;
	float pozx, pozy;
	Minion();
	void draw(RenderTarget& target, RenderStates state) const override;
	void spawn();
	Sprite sminion;
	Texture minion;
	void move(Gracz g);

};