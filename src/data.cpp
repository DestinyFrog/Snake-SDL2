#include "data.h"

Config::Config(){
	this->DELAY = 10;
	this->UNIT = 24;

	this->PER_ROW = 16;
	this->PER_COL = this->PER_ROW;

	this->WIDTH = PER_ROW * UNIT;
	this->HEIGHT = PER_COL * UNIT;
}