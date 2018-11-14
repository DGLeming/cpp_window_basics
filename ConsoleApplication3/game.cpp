#include "game.h"
#include <iostream>

SDL_Texture* cardTex;
SDL_Rect cardSrc, cardDest;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	Uint32 flags = 0;
	if (fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "Subsystems initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window){
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer){
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
	SDL_Surface* tmpSurface = IMG_Load("assets/card.png");
	cardTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

}

void Game::update()
{
	cardSrc.x = cardSrc.y = 0;
	cardDest.x = cardDest.y = 0;
	cardSrc.w = 32;
	cardSrc.h = 64;
	cardDest.w = 32;
	cardDest.h = 64;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//here add stuff to render
	SDL_RenderCopy(renderer, cardTex, &cardSrc, &cardDest);
	SDL_RenderPresent(renderer);
}

void Game::handleEnents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type){
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}