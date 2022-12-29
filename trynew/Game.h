#pragma once
#include"SDL.h"
#include"SDL_image.h"
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
	bool runnung() {
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
	void displaytargetscreen();
	static SDL_Renderer* renderer;
private:
	bool start = true;
	bool option = false;
	bool target = false;
	int cnt = 0;
	bool isrunning;
	SDL_Window* window;
	//SDL_Renderer* renderer;
};
