#pragma once
#include "Game.h"
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
class GameObject {

public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xpos;
	int ypos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;


};
#endif GAMEOBJECT_H_