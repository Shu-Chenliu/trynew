#include "Game.h"
#include<iostream>
#include"TextureManager.h"
#include"GameObject.h"
#include"Ball.h"
#include"Player.h"
#include"Score.h"
#include"Welcome.h"
#include"OptionScreen.h"
#include"TargetScore.h"
#include"Background.h"
using namespace std;
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
SDL_Renderer* Game::renderer = nullptr;
const Uint8* keystate = SDL_GetKeyboardState(NULL);
Game::Game() {
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = 400;
	srcR.h = 200;
	destR.x = 100;
	destR.y = 100;
	destR.w = 400;
	destR.h = 200;
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
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);//預設背景顏色
			cout << "renderer created" << endl;
		}
		isrunning = true;
		
		ball = new Ball("assets/ball-remove.png", 600, 0,474,474);
		
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
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
	else
	{
		cout << "music-on" << endl;
		bgm = Mix_LoadMUS("assets/start_music.ogg");
		play_mus = Mix_LoadMUS("assets/play_music.ogg");
		winsound = Mix_LoadMUS("assets/winsound.ogg");
		Mix_VolumeMusic(70);
	}
}
void Game::music1() {
	Mix_PlayMusic(bgm, -1);
}
void Game::music2() {
	Mix_PlayMusic(play_mus, -1);
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
		SDL_Delay(100);//讓場之間有間隔
		if (ball->getwin() == 'l') {
			score1->Update();
		}
		else {
			score2->Update();
		}
	}
}
void Game::render() {
	//cout << "render" << endl;
	SDL_RenderClear(renderer);
	background->Render();
	player->Render();
	enemy->Render();
	ball->Render();
	score1->Render();
	score2->Render();
	SDL_RenderCopy(renderer, objTexture1, &srcR, &destR);
	SDL_RenderPresent(renderer);
	if (isrunning == false) {
		SDL_Delay(4000);//暫停贏家畫面
	}
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_FreeMusic(bgm);
	bgm = NULL;
	Mix_FreeMusic(play_mus);
	play_mus = NULL;
	Mix_FreeMusic(winsound);
	winsound = NULL;
	SDL_Quit();
	Mix_Quit();
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
		background = new GameObject("assets/background1.png", 0, 0, 800, 640);
		break;
	case 1:
		background = new GameObject("assets/background2.png", 0, 0, 800, 640);
		break;
	case 2:
		background = new GameObject("assets/background3.png", 0, 0, 800, 640);
		break;
	default:
		break;
	}
	
}
int Game::loadTarget() {
	return tg->getTarget();
}
int Game::loadscore1() {
	return score1->score();
}
int Game::loadscore2() {
	return score2->score();
}
void Game::end() {
	//cout << "end" << endl;
	if (loadTarget() == loadscore1()) {
		objTexture1 = TextureManager::loadFont("player1 wins!!", "black");
		Mix_PlayMusic(winsound, 0);
		cout << "player1" << endl;
	}
	else if (loadTarget() == loadscore2()) {
		objTexture1 = TextureManager::loadFont("player2 wins!!", "black");
		Mix_PlayMusic(winsound, 0);
		cout << "player2" << endl;
	}
	isrunning = false;
	return;
}