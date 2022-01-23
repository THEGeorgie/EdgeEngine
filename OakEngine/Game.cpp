#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {

	int flags = 0;
	if (fullScreen == true) {

		flags = SDL_WINDOW_FULLSCREEN;

	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		cout << "Subsystems initialised..." << endl;
		// Ustveri in preveri ce sta window in renderer ustvarjeni

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window > 0) {
			cout << "Window se je ustvaril" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer > 0) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer se je ustvaril" << endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/supremeMan.png", 0, 0);
	enemy = new GameObject("assets/enemy.png", 50, 50);
	map = new Map();

	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos(500, 500);
}

void Game::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {

	player->update();
	enemy->update();
	manager.update();
	cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << "," << endl;
}

void Game::render() {

	SDL_RenderClear(renderer);
	map->drawMap();
	player->render();
	enemy->render();
	//Tuki damo stvari za render
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned" << endl;
}