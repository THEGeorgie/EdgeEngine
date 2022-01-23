#pragma once
#include "Components.h"
#ifndef POSTIONCOMPONENTS_H_
#define POSTIONCOMPONENTS_H_
class PositionComponent : public Component {

private:
	int xpos;
	int ypos;

public:

	PositionComponent() {

		xpos = 0;
		ypos = 0;

	}

	PositionComponent(int x, int y) {

		xpos = x;
		ypos = y;

	}

	int x() {
		return xpos;
	}

	int y() {
		return ypos;
	}

	void init() override {

		xpos = 0;
		ypos = 0;

	}

	void update() override {

		xpos++;
		ypos++;

	}

	void setPos(int x, int y) {

		xpos = x;
		ypos = y;

	}
};
#endif // !POSTIONCOMPONENTS_H_