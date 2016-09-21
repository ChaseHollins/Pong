#pragma once
#include <iostream>
#include "Paddle.h"
#include "Circle.h"
#include <cmath>


int collisionPaddleBorder(const Paddle Player)
{
	if (Player.positionX + 50 < 795 && Player.positionX - 50 > 5)
		return 1;
	else if (Player.positionX + 50 >= 795)
		return 2;
	else if (Player.positionX - 50 <= 5)
		return 3;
}


void collisionBallBorder(Circle &Ball)
{
	if (Ball.positionX >= 790)
	{
		Ball.momentumX = fabsf(Ball.momentumX) * (-1);
		Ball.momentumY = Ball.momentumY;
	}

	if (Ball.positionX <= 10)
	{
		Ball.momentumX = fabsf(Ball.momentumX);
		Ball.momentumY = Ball.momentumY;
	}

	if (Ball.positionY >= 590)
	{
		Ball.momentumX = Ball.momentumX;
		Ball.momentumY = fabsf(Ball.momentumY) * (-1);
		Ball.score++;
		if (Ball.speed < 2000)
		{
			Ball.speed = Ball.speed + 20;
		}
	}

	if (Ball.positionY <= 10)
	{
		Ball.momentumX = Ball.momentumX;
		Ball.momentumY = fabsf(Ball.momentumY);
		Ball.lost = true;
	}
}


void collisionBallPaddle(Circle &Ball, const Paddle Player)
{
	float holder = atan2f(Ball.positionX - Player.positionX, Ball.positionY - Player.positionY);
	Ball.momentumX = (sin(holder));
	Ball.momentumY = (cos(holder));
}


void overlapBallPaddle(Circle &Ball, const Paddle Player)
{
	if (pow((Ball.positionX - Player.positionX), 2) + pow((Ball.positionY - Player.positionY), 2) <= 2700)
	{
		collisionBallPaddle(Ball, Player);
	}
}
