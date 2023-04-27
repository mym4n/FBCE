#include <iostream>
#include <SDL2/SDL.h>
#include "../include/common.h"

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window * window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_RESIZABLE);
	SDL_Renderer * rend = SDL_CreateRenderer(window, 0, 0);
	
	// window loop
	bool makework = true;
	float tick;
	SDL_Event ev;
	int deltatime = 0;
	int fpscap = 1000/144;
	Vec2 origin = Vec2(200, 200);
	Vec2 origin2 = Vec2(200, 250);
	Vec2 penis = Vec2();
	while (makework) {
		// timing code
		deltatime = SDL_GetTicks();

		// clear the screen
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
		SDL_RenderClear(rend);
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
				case SDL_QUIT:
					makework = false;
					break;
			}
		}

		// logic
		if (tick > 180) { tick = -180; }
		penis = Vec2.Rotate(origin2, origin, tick);
		SDL_RenderDrawPoint(rend, origin.x, origin.y);
		SDL_RenderDrawPoint(rend, penis.x, penis.y);

		SDL_RenderPresent(rend);
		tick++;
		deltatime = SDL_GetTicks() - deltatime;
		if (fpscap > deltatime) {
			SDL_Delay(fpscap - deltatime);
		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(rend);
	SDL_Quit();
	return 0;
}
