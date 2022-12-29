#include "Game.h"//1
#include<iostream>
#include"TextureManager.h"//2
#include"GameObject.h"//3
//#include"Map.h"//4
#include"Ball.h"
#include"Player.h"
#include"Score.h"
#include"Welcome.h"
#include"OptionScreen.h"
#include"TargetScore.h"
using namespace std;
//SDL_Texture* playertex;
//SDL_Rect srcR, destR;
GameObject* background;
Player* player;
Player* enemy;
GameObject* ball;
Score* score1;
Score* score2;
StartScreen* screen;
OptionScreen* op;
TargetScreen* tg;
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
		player = new Player("assets/player.png", 0, 422,242,436,'l');
		enemy = new Player("assets/enemy.png", 560, 422,242,436,'r');
		ball = new Ball("assets/ball.png", 0, 0,454,396);
		background = new GameObject("assets/background.png", 0, 0,800,640);
		//map = new Map();
		score1 = new Score("0", 10,10,50, 50,"black");
		score2 = new Score("0", 725, 10, 50, 50,"red");
		screen = new StartScreen(renderer,"target score","option","start","black");
		op = new OptionScreen(renderer, "volleyball","return", "black");
		tg = new TargetScreen(renderer,"3","black");
	}
	else {
		isrunning = false;
	}
}
void Game::displaystartscreen() {
	screen->handleEvents(keystate,start,option,target);
	screen->update();
	screen->render();
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
	if (ball->touchground()) {
		ball->reset();
		if (ball->getwin() == 'l') {
			score1->Update();
		}
		else {
			score2->Update();
		}
	}
}
void Game::render() {
	SDL_RenderClear(renderer);
	//map->DrawMap();
	background->Render();
	//SDL_RenderCopy(renderer, playertex, NULL, &destR);
	player->Render();
	enemy->Render();
	ball->Render();
	score1->Render();
	score2->Render();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "game cleaned" << endl;
}
void Game::displayoptionscreen() {
	op->handleEvents(keystate, start,option,target);
	op->update();
	op->render();
}
void Game::displaytargetscreen() {
	tg->handleEvents(keystate, start, option,target);
	tg->update();
	tg->render();
}