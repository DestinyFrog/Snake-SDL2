#ifndef APPLE_H_
#define APPLE_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>

#include "data.h"

class Apple {
	private:
	Config config;

	public:
	Vector2 position, size;
	Apple( Config );
	void Repos();
	void Draw(SDL_Renderer*);
};

#endif /* APPLE_H_ */