#ifndef DATA_H_
#define DATA_H_

struct Vector2 {
	int x, y;
};

struct color {
	int r,g,b;
};

class Config {
	public:
	Config();

	int
		DELAY,
		UNIT,
		PER_ROW,
		PER_COL,
		WIDTH,
		HEIGHT;
};

#endif /* DATA_H_ */