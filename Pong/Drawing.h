#pragma once
#include "sfwdraw.h"
//#include <iostream>
#include "Paddle.h"
#include "Circle.h"


void drawBall(const Circle Ball)
{
	//sfw::drawLine(Ball.positionX, Ball.positionY, Ball.positionX2, Ball.positionY2);
	//sfw::drawLine(Ball.positionX2, Ball.positionY2, Ball.positionX3, Ball.positionY3);
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

