#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include "data.h"
#include "Snake.h"
#include "Apple.h"

Config config = Config();
Snake snake = Snake( config );
Apple apple = Apple( config );

void start() {
	apple.Repos();
}

void draw( SDL_Renderer *render ) {
	// Update
	snake.Move();

	// Draw
	SDL_RenderClear( render );

	apple.Draw( render );
	snake.Draw( render );

	if ( snake.Check_Hit_or_Not( apple.position.x, apple.position.y ) == 1 ) {
		apple.Repos();
		snake.Grow();
	}

	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderPresent(render);
}

void input( SDL_Keycode keyCode ) {
	snake.Input( keyCode );
}

int main( int argc, char *argv[] ) {
	srand (time(NULL));

	SDL_Init( SDL_INIT_EVERYTHING );

	// Create Window
	SDL_Window *window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, config.WIDTH, config.HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
	if ( window == nullptr ) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Create a Render
	SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if ( render == nullptr ) {
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Create SDL event
	SDL_Event window_event;

	int counter = 0;
	int max_counter = 10;

	start();

	while ( true ) {
		// Check if QUIT EVENT is triggered
		if ( SDL_PollEvent( &window_event ) ) {
			if ( SDL_QUIT == window_event.type )
				break;
			else if (window_event.type == SDL_KEYDOWN)
				input( window_event.key.keysym.sym );
		}

		// call update method
		if ( counter > max_counter ) {
			draw( render );
			counter = 0;
		} else
			counter++;

		SDL_Delay( config.DELAY );
	}

	// Close window
	SDL_DestroyWindow( window );
	SDL_Quit();
	return EXIT_SUCCESS;
}