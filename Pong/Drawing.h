#pragma once
#include "sfwdraw.h"
//#include <iostream>
#include "Paddle.h"
#include "Circle.h"


void drawBall(const Circle Ball)
{
	sfw::drawCircle(Ball.positionX, Ball.positionY, 5);
}


void drawLine(const Paddle Player)
{
	sfw::drawCircle(Player.positionX , Player.positionY, 50);
}

void drawBorders()
{
	sfw::drawLine(5, 5, 795, 5);
	sfw::drawLine(5, 595, 795, 595);
	sfw::drawLine(5, 5, 5, 595);
	sfw::drawLine(795, 5, 795, 595);
}

