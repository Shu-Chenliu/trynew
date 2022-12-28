#pragma once
#include"Game.h"
#include"TextureManager.h"
#include<string>
using namespace std;
class Score{
public:
	Score(string st, int x, int y, int w, int h);
	~Score();
	void Update();
	void Render();
private:
	int s;
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};

