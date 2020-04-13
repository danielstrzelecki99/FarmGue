#pragma once
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Sounds
{
	public:
		SoundBuffer background, hit, atack, welcome;
		Sound sbackground, shit, satack, swelcome;
		Sounds();
};

