#include "SDL.h"

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEnents();
	bool inline running(){ return isRunning; };
	void update();
	void render();
	void clean();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};