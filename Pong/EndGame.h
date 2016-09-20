#pragma once
#include "sfwdraw.h"

void EndUpdate()
{
	unsigned loadTextureMap(const char* path, unsigned rows = 1, unsigned cols = 1);
	while (sfw::stepContext())
	{
		void drawTexture(unsigned loadTextureMap, float x, float y, float width = 1, float height = 1, float angle = 0, bool centered = true, unsigned index = 0, unsigned int tint = WHITE);
	}
}

