#include "sfwdraw.h"
#include "GameState.h"
#include "stateconst.h"
#include "SplashState.h"
#include "EndState.h"

int main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	sfw::setBackgroundColor(BLACK);
	int splashImg = sfw::loadTextureMap("./Art/StartScreen.png", 1, 1);
	int endImg = sfw::loadTextureMap("./Art/GameOver.jpg", 1, 1);
	int font = sfw::loadTextureMap("./Art/font.png", 16, 16);

	SplashState splash;
	GameState gs = createGameState();
	EndState end;

	char scoreWord[12];

	splash.init(splashImg, font);
	end.init(endImg, font);


	STATE current = ENTER_SPLASH;
	while (sfw::stepContext())
	{
		switch (current)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			current = splash.next();
			break;

		case ENTER_GAME:
			gs = createGameState();
		case GAME:
			UpdateGameState(gs);
			DrawGameState(gs);

			if (gs.Ball.lost == true)
				current = ENTER_END;
			else
				current = GAME;

			break;

		case ENTER_END:
			end.play();
		case END:
			end.step();
			sprintf_s(scoreWord, "Score: %d", gs.Ball.score);
			end.draw(scoreWord);
			current = end.next();
			break;
		}
	}
	

	sfw::termContext();
	//system("pause");
	
}
