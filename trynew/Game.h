#pragma once
#include"SDL.h"
#include"SDL_image.h"
#include "SDL_mixer.h"
#include<iostream>
using namespace std;
class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleevents();
	void update();
	void render();
	void clean();
	bool running() {
		return isrunning;
	}
	bool startmode() {
		return start;
	}
	void displaystartscreen();
	bool optionmode() {
		return option;
	}
	void displayoptionscreen();
	bool istarget() {
		return target;
	}
	bool isbackground() {
		return bg;
	}
	void music1();
	void music2();
	void displaytargetscreen();
	void displaybackground();
	void loadpicture();
	int loadTarget();
	int loadscore1();
	int loadscore2();
	void end();
	static SDL_Renderer* renderer;
private:
	bool start = true;
	bool option = false;
	bool target = false;
	int cnt = 0;
	int p1 = 0;
	int p2 = 0;
	bool bg = false;
	int whichbackground = 0;
	bool isrunning;
	SDL_Window* window;
	Mix_Music* bgm;
	Mix_Music* play_mus;
	SDL_Texture* objTexture1 = nullptr;
	SDL_Rect srcR, destR;
	//SDL_Renderer* renderer;
};
