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
#include"Background.h"
using namespace std;
//SDL_Texture* playertex;
//SDL_Rect srcR, destR;
GameObject* background;
Player* player;
Player* enemy;
Ball* ball;
Score* score1;
Score* score2;
StartScreen* screen;
OptionScreen* op;
TargetScreen* tg;
BackgroundScreen* b;
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
		
		ball = new Ball("assets/ball-remove.png", 200, 0,474,474);
		
		//map = new Map();
		score1 = new Score("0", 10,10,50, 50,"black");
		score2 = new Score("0", 725, 10, 50, 50,"red");
		screen = new StartScreen(renderer,"target score","option","start","black");
		op = new OptionScreen(renderer, "volleyball","return", "black");
		tg = new TargetScreen(renderer,"3","black");
		b=new BackgroundScreen(renderer, "volleyball", "return", "black");
	}
	else {
		isrunning = false;
	}
}
void Game::displaystartscreen() {
	screen->handleEvents(keystate,start,option,target,bg);
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
	ball->checkCollision(player, enemy, keystate);
	if (ball->touchground()) {
		ball->reset();
		SDL_Delay(100);
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
	op->handleEvents(keystate, start,option,target,bg,p1,p2);
	op->update();
	op->render();
}
void Game::displaytargetscreen() {
	tg->handleEvents(keystate, start, option,target,bg);
	tg->update();
	tg->render();
}
void Game::displaybackground() {
	b->handleEvents(keystate, start, option, target,bg,whichbackground);
	b->update();
	b->render();
}
void Game::loadpicture() {
	switch (p1) {
	case 0:
		player = new Player("assets/player1-1.png", 0, 540, 781, 997, 'l');
		break;
	case 1:
		player = new Player("assets/player1-2.png", 0, 540, 781, 997, 'l');
		break;
	case 2:
		player = new Player("assets/player1-3.png", 0, 540, 781, 997, 'l');
		break;
	default:
		break;
	}
	switch (p2) {
	case 0:
		enemy = new Player("assets/player2-1.png", 562, 540, 781, 997, 'r');
		break;
	case 1:
		enemy = new Player("assets/player2-2.png", 562, 540, 781, 997, 'r');
		break;
	case 2:
		enemy = new Player("assets/player2-3.png", 562, 540, 781, 997, 'r');
		break;
	default:
		break;
	}
	switch (whichbackground) {
	case 0:
		background = new GameObject("assets/background.png", 0, 0, 800, 640);
		break;
	case 1:
		background = new GameObject("assets/startbg.png", 0, 0, 800, 640);
		break;
	case 2:
		background = new GameObject("assets/startbg.png", 0, 0, 800, 640);
		break;
	default:
		break;
	}
	
}