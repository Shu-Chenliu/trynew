#include"Game.h"
Game* game = nullptr;
int main(int argc, char* argv[]) {
	const int FPS = 60;//幀數
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("monster volleyball", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->startmode()){
		game->music1();
		game->displaystartscreen();
		while (game->optionmode()) {
			game->displayoptionscreen();
		}
		while (game->istarget()) {
			game->displaytargetscreen();
		}
		while (game->isbackground()) {
			game->displaybackground();
		}
	}
	game->loadpicture();
	game->music2();
	int target = game->loadTarget();
	while (game->running()) {
		frameStart = SDL_GetTicks();//回傳程式執行時間
		game->handleevents();
		game->update();
		if (target == game->loadscore1()) {
			game->end();
		}
		else if (target == game->loadscore2()) {
			game->end();
		}
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);//讓人走得更順暢
		}
	}
	game->clean();
	return 0;
}