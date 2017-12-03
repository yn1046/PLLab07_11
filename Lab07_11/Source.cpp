#include <SDL.h>
#include <iostream>
#include <vector>

#define window_width 640
#define window_height 480
#define windowpos_top 30

#define fps 60


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *myWindow;
	SDL_Renderer* renderer;

	myWindow = SDL_CreateWindow("Sailing boat",
		SDL_WINDOWPOS_CENTERED, windowpos_top, //coordinates
		window_width, window_height, //size
		SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(myWindow, 0, SDL_RENDERER_SOFTWARE);

	if (myWindow == NULL) std::cout << "There was an error!" << std::endl;
	
	//IMPLEMENTATION PART


	
	Uint32 starting_tick;
	SDL_Event myEvent;
	bool running = true;
	int startX = -100;

	while (running) {
		starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&myEvent)) {
			if (myEvent.type == SDL_QUIT) {
				running = false;
				break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, startX, 180, startX, 240);
		SDL_RenderDrawLine(renderer, startX, 240, startX+40, 240);
		SDL_RenderDrawLine(renderer, startX+40, 240, startX, 180);
		SDL_RenderDrawLine(renderer, startX-100, 250, startX+100, 250);
		SDL_RenderDrawLine(renderer, startX-100, 250, startX-85, 270);
		SDL_RenderDrawLine(renderer, startX-85, 270, startX+85, 270);
		SDL_RenderDrawLine(renderer, startX+85, 270, startX+100, 250);
		SDL_RenderPresent(renderer);
		startX++;
		if (startX - 100 >= window_width) startX = -100;
		if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
			SDL_Delay(1000 / fps - (SDL_GetTicks() - starting_tick));
		}
	}

	SDL_DestroyWindow(myWindow);
	SDL_Quit();

	
	return 0;
}