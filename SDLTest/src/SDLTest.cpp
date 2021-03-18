//============================================================================
// Name        : SDLTest.cpp
// Author      : Sergio AndradeSergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

using namespace std;
using namespace fpg;

int main() {
	srand(time(NULL)); // this seeds the rand function for better randoms

	Screen screen;

	if (!screen.init()) {
		cout << "Failed to start SDL" << endl;
	}

	Swarm swarm;
	const Particle* const pParticles = swarm.getParticles();
	int elapsed;
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	const int halfWidth = Screen::SCREEN_WIDTH / 2;
	const int halfHeight = Screen::SCREEN_HEIGHT / 2;
	while (true) {
		elapsed = SDL_GetTicks(); // method to get the time elapsed since program execution
		// Draw particles

		swarm.update(elapsed); // adding the elapsed time we can calculate a proportional update speed

		red = (1 + sin(elapsed * 0.0005 )) * 128;
		green = (1 + sin(elapsed * 0.0001 )) * 128;
		blue = (1 + sin(elapsed * 0.0009 )) * 128;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * halfWidth;
			int y = particle.m_y * halfWidth + halfHeight;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		// Update particles

		// Check for messages/events

		// Draw screen
		screen.update();

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();
	return 0;
}
