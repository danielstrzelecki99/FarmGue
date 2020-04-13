#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Punkty :public Drawable
{
public:
	Font czc;
	Punkty();
	Text napis;
	void draw(RenderTarget& target, RenderStates state) const override;
	void update(int pkt);
	void przegrana(int pkt);
};
