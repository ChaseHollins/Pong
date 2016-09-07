#pragma once
#include <iostream>
#include "Paddle.h"
#include "Circle.h"


int collisionPaddleBorder(const Paddle Player)
{
	if (Player.positionX + 75 < 795 && Player.positionX - 75 > 5)
		return 1;
	else if (Player.positionX + 75 >= 795)
		return 2;
	else if (Player.positionX - 75 <= 5)
		return 3;
}


void collisionBallBorder(Circle &Ball)
{
	if (Ball.positionX >= 790 || Ball.positionX <= 10)
	{
		Ball.momentumX = Ball.momentumX*(-1);
		Ball.momentumY = Ball.momentumY;
	}

	if (Ball.positionY >= 590 || Ball.positionY <= 10)
	{
		Ball.momentumX = Ball.momentumX;
		Ball.momentumY = Ball.momentumY * (-1);
	}
}


void collisionBallPaddle(Circle &Ball, const Paddle Player)
{
	float multiplier = fabsf(Player.positionX - Ball.positionX);
	multiplier = multiplier / 30.0;

	Ball.momentumX = Ball.momentumX * multiplier;
	Ball.momentumY = Ball.momentumY * (-1);
}


void overlapBallPaddle(Circle &Ball, const Paddle Player)
{
	bool xOverlap = false;
	bool yOverlap = false;
	if (Ball.positionY + 35 >= Player.positionY && Ball.positionY - 5 <= Player.positionY)
		yOverlap = true;
	if (Ball.positionX - 5 < Player.positionX + 75 && Ball.positionX + 5 > Player.positionX - 75)
		xOverlap = true;

	if (xOverlap == true && yOverlap == true)
	{
		collisionBallPaddle(Ball, Player);
		Ball.positionY = 110;
	}
}
