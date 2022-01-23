#pragma once
#include "Components.h"
#include "SDL.h"
#ifndef SPRITECOMPONENTS_H_
#define SPRITECOMPONENTS_H_
class  SpriteComponents : public Component {
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponents() = default;
	SpriteComponents(const char* path) {

		setTex(path);

	}

	void setTex(const char* path) {

		texture = TextureManager::loadTexture(path);

	}

	void init() override {

		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;

	}

	void update() override {

		destRect.x = position->x();
		destRect.y = position->y();

	}

	void draw() override {

		TextureManager::draw(texture, srcRect, destRect);

	}
};

#endif // !SPRITECOMPONENTS_H_