#include "Punkty.h"

using namespace std;

void Punkty::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(napis, state);
}

void Punkty::update(int pkt)
{
	napis = to_string(pkt);
}
