#include "sfwdraw.h"
#include "Interactions.h"
#include "Drawing.h"
#include "Update.h"


int main()
{
	Circle Ball;
	Paddle Player;
	sfw::initContext(800, 600, "NSFW Draw");
	sfw::setBackgroundColor(BLACK);


	while (sfw::stepContext())
	{
		int i = 0;

		drawBorders();
		updatePaddle(Player);
		drawLine(Player);
		collisionBallBorder(Ball);
		overlapBallPaddle(Ball, Player);
		updateBall(Ball);
		drawBall(Ball);
		
		i++;
		if (i >= 5 && Ball.speed < 3000)
		{
			i = 0;
			Ball.speed++;
		}
	}

	sfw::termContext();
}
