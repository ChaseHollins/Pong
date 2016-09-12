#pragma once
#include "Paddle.h"
#include "Circle.h"
#include "Interactions.h"
#include "sfwdraw.h"
#include <iostream>
#include <ctime>

void stabilizeSpeed(Circle &Ball)
{
	if (fabsf(Ball.momentumX / Ball.momentumY) > 2)
		Ball.momentumX = 2.0 * Ball.momentumY;

	if (Ball.momentumY > 9)
	{
		int rnd;
		srand((unsigned)time(0));
		rnd = ((rand() % 21) - 10)/5;

		Ball.momentumX = rnd;
	}

	float total = fabsf(Ball.momentumX) + fabsf(Ball.momentumY);
	float difference = (Ball.speed/100) / total;

	Ball.momentumX = Ball.momentumX*difference;
	Ball.momentumY = Ball.momentumY*difference;

}


void updateBall(Circle & Ball)
{
	stabilizeSpeed(Ball);

	//Ball.positionX3 = Ball.positionX2;
	//Ball.positionY3 = Ball.positionY2;
	//Ball.positionX2 = Ball.positionX;
	//Ball.positionY2 = Ball.positionY;

	Ball.positionX += Ball.momentumX;
	Ball.positionY += Ball.momentumY;
}


void updatePaddle(Paddle &Player)
{
	switch (collisionPaddleBorder(Player))
	{
	case 1:
		if (sfw::getKey(KEY_LEFT))
			Player.positionX -= 8;
		if (sfw::getKey(KEY_RIGHT))
			Player.positionX += 8;
		break;
	case 2:
		Player.positionX = 745;
		if (sfw::getKey(KEY_LEFT))
			Player.positionX -= 8;
		break;
	case 3:
		Player.positionX = 55;
		if (sfw::getKey(KEY_RIGHT))
			Player.positionX += 8;
		break;
	}
}

void score(Circle &Ball)
{
	int i = 0;

	i++;
	if (i >= 5 && Ball.speed < 3000)
	{
		i = 0;
		Ball.speed++;
	}
}