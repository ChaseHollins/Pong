#pragma once
#include "stateconst.h"

class EndState
{
	int imageEnd;
	float timer;
	int font;

public:
	void  init(int img, int a_font);
	void  play();
	void  step();
	void  draw(char score[]);
	STATE next();
};
