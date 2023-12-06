#ifndef SNAKE_H_
#define SNAKE_H_

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "data.h"

class Snake {
	private:
	Config config;
	std::vector<Vector2> party;
	Vector2 move, size;

	public:
	Snake( Config );
	void Grow();
	void Input( SDL_Keycode );
	int Check_Hit( int, int, int, int );
	bool Check_Hit_Pos( int, int );
	void Move();
	void Draw(SDL_Renderer *);
	Vector2 Get_Head();
};

#endif /* SNAKE_H_ */