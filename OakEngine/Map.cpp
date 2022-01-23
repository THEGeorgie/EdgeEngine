#include "Map.h"
#include "TextureManager.h"

int level1[20][25] = {
	{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,1,1,1,1,2,1,1,1,0,0,0,0,0,0,0,0,0,},
	{0,0,1,1,1,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,1,1,1,1,2,1,1,1,1,1,0,0,0,0,0,0,0,},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,},
	{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
};

Map::Map() {

	dirt = TextureManager::loadTexture("assets/dirt.png");
	grass = TextureManager::loadTexture("assets/grass.png");
	water = TextureManager::loadTexture("assets/water.png");

	loadMap(level1);

	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;

}

void Map::loadMap(int arr[20][25]) {

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {

			map[row][column] = arr[row][column];

		}
	}

}

void Map::drawMap() {
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {

			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type) {
			case 0:
				TextureManager::draw(water, src, dest);
				break;
			case 1:
				TextureManager::draw(grass, src, dest);
				break;
			case 2:
				TextureManager::draw(dirt, src, dest);
				break;
			default:
				break;

			}

		}
	}

}