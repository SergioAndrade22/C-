/*
 * Screen.h
 *
 *  Created on: 16 mar. 2021
 *      Author: sandrade
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <iostream>

using namespace std;

namespace fpg {

class Screen {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_pixelBuffer;

public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

public:
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvents();
	void clear();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();
	void update();
	void close();
};

} /* namespace fpg */

#endif /* SCREEN_H_ */
