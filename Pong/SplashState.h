#pragma once

#include "stateconst.h"

class SplashState
{
	int image;
	float timer;
	int font;

public:
	void  init(int img, int a_font); // on creation
	void  play(); // on activation
	void  step(); // update
	void  draw(); // draw
	STATE next(); // Where are we going?
};