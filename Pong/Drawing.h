#pragma once
#include "sfwdraw.h"
#include "Paddle.h"
#include "Circle.h"

unsigned int colour[9] = { 0xff0000ff,0xff1a1aff,0xff3333ff,0xff4d4dff,0xff6666ff,0xff8080ff,0xff9999ff,0xffb3b3ff,0xffccccff };


void drawBall(const Circle Ball)
{
	sfw::drawLine(Ball.positionX, Ball.positionY, Ball.stringPosX[1], Ball.stringPosY[1], RED);

	for (int i = 9; i > 0; --i)
	{
		sfw::drawLine(Ball.stringPosX[i], Ball.stringPosY[i], Ball.stringPosX[i - 1], Ball.stringPosY[i - 1], (colour[i-1]));
	}
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

