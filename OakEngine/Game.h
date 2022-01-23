#pragma once
#include <sdl.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;
#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }

	static SDL_Renderer* renderer;

private:
	bool isRunning;
	SDL_Window* window;
	int count = 0;
};

#endif GAME_H_