#include "game.h"

Game *game = nullptr;
int width = 600;
int height = 600;
int main(int argc, char * argv[])
{
	game = new Game();
	game->init("windowtitle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
	while (game->running()){
		game->handleEnents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}

