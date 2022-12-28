#include"Game.h"
Game* game = nullptr;
int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("2dengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->runnung()) {
		frameStart = SDL_GetTicks();//�^�ǵ{������ɶ�
		game->handleevents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);//���H���o�󶶺Z
		}
	}
	game->clean();
	return 0;
}