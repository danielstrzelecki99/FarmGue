#include "Pocisk.h"
#include "Gracz.h"
#include <vector>


Pocisk::Pocisk()
{
	pocisk.setRadius(10);
	pocisk.setOrigin(10, 10);
	pocisk.setFillColor(Color::Yellow);
}

void Pocisk::spawn(Gracz g)
{
	resp_x= g.px+82.5;
	resp_y= g.py+50.5;
	pocisk.setPosition(resp_x, resp_y);
}

void Pocisk::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(pocisk, state);
}

void Pocisk::movep(RenderWindow& okno)
{
	move_x = Mouse::getPosition(okno).x - resp_x;
	move_y = Mouse::getPosition(okno).y - resp_y;
	dl = sqrt((move_x)*(move_x)+(move_y)*(move_y));
}

void Pocisk::update()
{
	px = move_x / dl * 10;
	py = move_y / dl * 10;
	pozx = pocisk.getPosition().x;
	pozy = pocisk.getPosition().y;
	pocisk.move(px, py);
	
}