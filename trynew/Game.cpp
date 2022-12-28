#include "Game.h"//1
#include<iostream>
#include"TextureManager.h"//2
#include"GameObject.h"//3
//#include"Map.h"//4
#include"Ball.h"
#include"Player.h"
using namespace std;
//SDL_Texture* playertex;
//SDL_Rect srcR, destR;
GameObject* background;
Player* player;
Player* enemy;
GameObject* ball;
//Map* map;
//bool key[322] = { false };
SDL_Renderer* Game::renderer = nullptr;
const Uint8* keystate = SDL_GetKeyboardState(NULL);
Game::Game() {

}
Game::~Game() {

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "subsystem initialized" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "window created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			cout << "renderer created" << endl;
		}
		isrunning = true;
		//SDL_Surface* surface = IMG_Load("assets/player.png");
		//playertex = SDL_CreateTextureFromSurface(renderer, surface);
		//SDL_FreeSurface(surface);
		// 
		//playertex = TextureManager::LoadTexture("assets/player.png", renderer);
		player = new Player("assets/player.png", 0, 420,242,436);
		enemy = new Player("assets/enemy.png", 558, 420,242,436);
		ball = new Ball("assets/ball.png", 0, 0,454,396);
		background = new GameObject("assets/background.png", 0, 0,800,640);
		//map = new Map();
	}
	else {
		isrunning = false;
	}
}
void Game::handleevents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isrunning = false;
		break;
	case SDL_KEYDOWN:
		player->move(keystate);
		enemy->move(keystate);
		break;
	case SDL_KEYUP:
		//key[event.key.keysym.sym] = false;
		player->stop(keystate);
		enemy->stop(keystate);
		break;
	default:
		break;
	}
}
void Game::update() {
	/*cnt++;
	destR.h = 64;
	destR.w = 64;
	destR.x = cnt;
	cout << cnt << endl;*/
	player->Update();
	enemy->Update();
	ball->Update();
}
void Game::render() {
	SDL_RenderClear(renderer);
	//map->DrawMap();
	background->Render();
	//SDL_RenderCopy(renderer, playertex, NULL, &destR);
	player->Render();
	enemy->Render();
	ball->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "game cleaned" << endl;
}