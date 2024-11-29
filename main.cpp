#include "Engine.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <iostream>

int main() {
	srand(time(0));

	Engine engine;

	engine.populateMap();
	engine.drawMap();

	return 0;

}
