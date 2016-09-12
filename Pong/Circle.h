#pragma once
struct Circle
{
	float positionX = 400;
	float positionY = 300;
	float speed = 1000;
	float momentumX = -3;
	float momentumY = 5;
	int score = 0;

	float stringPosX[10] = { 400 };
	float stringPosY[10] = { 300 };
};
