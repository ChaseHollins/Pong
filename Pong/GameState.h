#pragma once
#include "sfwdraw.h"
#include "Interactions.h"
#include "Drawing.h"
#include "Update.h"
#include "Paddle.h"
#include "Circle.h"

struct GameState
{
	Circle Ball;
	Paddle Player;
};

GameState createGameState()
{
	GameState retval;


	return retval;
};

void UpdateGameState(GameState & gs)
{
	updatePaddle(gs.Player);
	collisionBallBorder(gs.Ball);
	overlapBallPaddle(gs.Ball, gs.Player);
	updateBall(gs.Ball);
	score(gs.Ball);
}

void DrawGameState(GameState & gs)
{
	drawBorders();
	drawLine(gs.Player);
	drawBall(gs.Ball);
}
