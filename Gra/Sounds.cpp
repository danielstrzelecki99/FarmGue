#include "Sounds.h"
#include "SFML/Audio.hpp"

using namespace std;
using namespace sf;

Sounds::Sounds()
{
	hit.loadFromFile("sounds/hit.wav");
	shit.setBuffer(hit);
	atack.loadFromFile("sounds/SB.wav");
	satack.setBuffer(atack);
	welcome.loadFromFile("sounds/welcome.wav");
	swelcome.setBuffer(welcome);
}