/*
 * Screen.cpp
 *
 *  Created on: 16 mar. 2021
 *      Author: sandrade
 */

#include "Screen.h"

namespace fpg {

	Screen::Screen(): m_window(NULL),
					  m_renderer(NULL),
					  m_texture(NULL),
					  m_pixelBuffer(NULL) {	}

	Screen::~Screen() {
		// TODO Auto-generated destructor stub
	}

	bool Screen::init() {
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		m_window = SDL_CreateWindow("Particle fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL) {
			this->close();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		if (m_renderer == NULL) {
			this->close();
			return false;
		}

		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (m_texture == NULL) {
			this->close();
			return false;
		}

		try {
			m_pixelBuffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT]; // pixel for each pixel
		} catch (bad_alloc &exception) {
			this->close();
			return false;
		}

		// we use this to reset the buffer memory
		memset(m_pixelBuffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

		for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
			m_pixelBuffer[i] = 0x000000FF;
		}


		update();

		return true;
	}

	bool Screen::processEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				return false;
			}
		}
		return true;
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT) return;

		Uint32 color = 0;

		color += red;
		color <<= 8;

		color += green;
		color <<= 8;

		color += blue;
		color <<= 8;

		color += 0xFF;

		m_pixelBuffer[(y * SCREEN_WIDTH) + x] = color;
	}

	void Screen::boxBlur() {
		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				Uint32 redTotal = 0;
				Uint32 greenTotal = 0;
				Uint32 blueTotal = 0;

				for(int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {
						int currX = x + col;
						int currY = y + row;

						if (currX >= 0 && currX < SCREEN_WIDTH && currY >= 0 && currY < SCREEN_HEIGHT) {
							Uint32 color = m_pixelBuffer[currY * SCREEN_WIDTH + currX];

							Uint8 red = color >> 24;
							Uint8 green = color >> 16;
							Uint8 blue = color >> 8;

							redTotal += red;
							greenTotal += green;
							blueTotal += blue;

						}
					}
				}

				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal /9;
				Uint8 blue = blueTotal / 9;

				setPixel(x, y, red, green, blue);
			}
		}
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_pixelBuffer, SCREEN_WIDTH*sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::close() {
		if (m_texture != NULL) {
			SDL_DestroyTexture(m_texture);
		}

		if (m_renderer != NULL) {
			SDL_DestroyRenderer(m_renderer);
		}

		if (m_window != NULL) {
			SDL_DestroyWindow(m_window);
		}

		delete [] m_pixelBuffer;

		SDL_Quit();
	}

} /* namespace fpg */
