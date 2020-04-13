#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;

class Gracz :public Drawable
{
private:
	float gresp_x;
	float gresp_y;
public:
	float pozx, pozy;
	Gracz();
	void draw(RenderTarget& target, RenderStates state) const override;
	Sprite sgracz;
	Texture gracz;
	void move();
	float px = 600;
	float py = 440;


};
