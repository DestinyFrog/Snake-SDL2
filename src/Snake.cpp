#include "Snake.h"

Snake::Snake( Config config ) {
	this->Dying = false;
	this->config = config;

	this->size.x = config.UNIT;
	this->size.y = config.UNIT;

	this->move.x = 1;
	this->move.y = 0;

	Vector2 head;
	head.x = 0;
	head.y = 0;

	this->party.push_back( head );
}

Vector2 Snake::Get_Head(){
	Vector2 head;
	head.x = this->party[0].x;
	head.y = this->party[0].y;
	return head;
}

void Snake::Grow() {
	Vector2 part;
	part.x = -1;
	part.y = -1;
	this->party.push_back( part );
}

bool Snake::Check_Hit_or_Not( int tx, int ty ) {
	return
		( this->party[0].x == tx ) &&
		( this->party[0].y == ty )
	;
}

int Snake::Check_Hit( int tx, int ty, int sx, int sy ) {
	if ( this->party[0].x * this->config.UNIT < tx )
		return 1;

	if ( (this->party[0].x * this->config.UNIT) + this->size.x >= sx )
		return 2;

	if ( this->party[0].y * this->config.UNIT < ty )
		return 3;

	if ( (this->party[0].y * this->config.UNIT) + this->size.y >= sy )
		return 4;

	return 0;
}

void Snake::Input( SDL_Keycode keyCode ) {
	switch(keyCode) {
	case SDLK_LEFT:
		this->move.x = -1;
		this->move.y = 0;
		break;
	case SDLK_RIGHT:
		this->move.x = 1;
		this->move.y = 0;
		break;
	case SDLK_UP:
		this->move.x = 0;
		this->move.y = -1;
		break;
	case SDLK_DOWN:
		this->move.x = 0;
		this->move.y = 1;
		break;
	}
}

void Snake::Move() {
	if ( this->Dying == true ) {
		if (this->party.size() <= 1) {
			this->Dying = false;
		} else {
			this->party.pop_back();
		}
	}

	// move body
	for ( int i = this->party.size() - 1; i > 0; i-- ){
		this->party[i].x = this->party[i - 1].x;
		this->party[i].y = this->party[i - 1].y;
	}

	// move head
	this->party[0].x += this->move.x;
	this->party[0].y += this->move.y;

	// check wall collision
	switch ( this->Check_Hit( 0, 0, this->config.WIDTH + this->config.UNIT, this->config.HEIGHT  + this->config.UNIT ) ){
		case 1:
			this->party[0].x = this->config.PER_ROW;
			break;
		
		case 2:
			this->party[0].x = 0;
			break;

		case 3:
			this->party[0].y = this->config.PER_COL;
			break;

		case 4:
			this->party[0].y = 0;
			break;
	}

	for ( int i = 1; i < this->party.size(); i++ ){
		if ( this->party[0].x == this->party[i].x && this->party[0].y == this->party[i].y ) {
			this->Dying = true;
			break;
		}
	}
}

void Snake::Draw( SDL_Renderer *render ) {
	SDL_Rect rect;

	int color_part = 255 / this->party.size();

	for ( int i = 0; i < this->party.size(); i++ ){
		Vector2 part = this->party[i];

		rect.x = part.x * this->size.x;
		rect.y = part.y * this->size.y;
		rect.w = this->size.x;
		rect.h = this->size.y;

		SDL_SetRenderDrawColor(render, 255 - ( color_part * i ), 0, 255, 255);
		SDL_RenderFillRect(render, &rect);
	}
}

int Snake::Points() {
	return this->party.size();
}