#include "Apple.h"

Apple::Apple( Config config ) {
	this->config = config;

	this->position.x = 0;
	this->position.y = 0;

	this->size.x = config.UNIT;
	this->size.y = config.UNIT;
}

void Apple::Repos() {
	this->position.x = rand() % this->config.PER_ROW;
	this->position.y = rand() % this->config.PER_COL;
}

void Apple::Draw(SDL_Renderer *render) {
	SDL_Rect rect;
	rect.x = this->position.x * this->size.x;
	rect.y = this->position.y * this->size.y;
	rect.w = this->size.x;
	rect.h = this->size.y;

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderFillRect(render, &rect);
}