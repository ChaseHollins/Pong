#include "EndState.h"
#include "sfwdraw.h"
//#include "GameState.h"

void EndState::init(int img, int a_font)
{
	imageEnd = img;
	font = a_font;
}

void EndState::play()
{
	timer = 5.0f;
}

void EndState::step()
{
	timer -= sfw::getDeltaTime();
}

void EndState::draw(char score[])
{
	//sfw::drawTexture(imageEnd, 400, 300, 800, 600);
	
	sfw::drawString(font, score, 230, 300, 40, 40, 0, 0);
	sfw::drawString(font, "Resetting Game...", 272, 150, 15, 15, 0, 0);
	sfw::drawLine(100, 100, 100 + 600 * timer / 5, 100);
}

STATE EndState::next()
{
	if (timer < 0)
		return ENTER_SPLASH;


	return END;
}
