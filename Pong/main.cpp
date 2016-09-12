#include "sfwdraw.h"
#include "GameState.h"


int main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	sfw::setBackgroundColor(BLACK);
	
	GameState gs = createGameState();

	while (sfw::stepContext())
	{
		UpdateGameState(gs);
		DrawGameState(gs);
	}

	sfw::termContext();
}
