#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Punkty :public Drawable
{
public:
	sf::String napis;
	void draw(RenderTarget& target, RenderStates state) const override;
	void update(int pkt);
};

