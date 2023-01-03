#pragma once
#include"Game.h"
#include"TextureManager.h"
#include<string>
using namespace std;
class Score {
public:
	Score(string st, int x, int y, int w, int h, const char* color);
	~Score();
	void Update(); //穝把计
	void Render(); //穝礶
	int score() { //肚讽玡だ计
		return s;
	}
private:
	const char* c;//魁肅︹
	int s; //魁だ计
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};

