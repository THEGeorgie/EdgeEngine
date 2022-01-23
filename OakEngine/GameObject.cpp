#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* textureSheet, int x, int y) {

	objectTexture = TextureManager::loadTexture(textureSheet);

	xpos = x;
	ypos = y;

}

void GameObject::update() {

	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 3;
	destRect.w = srcRect.w * 3;


}

void GameObject::render() {

	SDL_RenderCopy(Game::renderer,objectTexture, &srcRect, &destRect);

}