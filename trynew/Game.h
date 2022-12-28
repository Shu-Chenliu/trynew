#pragma once
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
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
	static SDL_Renderer* renderer;
private:
	int target;
	int cnt = 0;
	bool isrunning;
	SDL_Window* window;
	//SDL_Renderer* renderer;
};
