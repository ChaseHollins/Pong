#include "SplashState.h"
#include "sfwdraw.h"

void SplashState::init(int img, int a_font)
{
	image = img;
	font = a_font;
}

void SplashState::play()
{
	timer = 3.0f;
}

void SplashState::step()
{
	timer -= sfw::getDeltaTime();
}

void SplashState::draw()
{
	//sfw::drawString(font, "Wait to Pong!", 400, 300, 20, 20, 0, 0);
	sfw::drawTexture(image, 400, 250, 700, 600);
	sfw::drawLine(100,100,100 + 600*timer/3,100);
}

STATE SplashState::next()
{
	if (timer < 0)
		return ENTER_GAME;



	return SPLASH;
}
