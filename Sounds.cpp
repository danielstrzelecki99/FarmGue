#include "Sounds.h"
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;

Sounds::Sounds()
{
	background.loadFromFile("background.wav");
	sbackground.setBuffer(background);
	hit.loadFromFile("hit.wav");
	shit.setBuffer(hit);
	atack.loadFromFile("SB.wav");
	satack.setBuffer(atack);
	welcome.loadFromFile("welcome.wav");
	swelcome.setBuffer(welcome);
}