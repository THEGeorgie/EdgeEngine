#pragma once
#include "Game.h"
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_
class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* fileName);
	static void draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};


#endif _TEXTUREMANAGER_H_