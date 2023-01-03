#pragma once
#include"Game.h"
#include"TextureManager.h"
#include<string>
using namespace std;
class Score {
public:
	Score(string st, int x, int y, int w, int h, const char* color);
	~Score();
	void Update(); //更新參數
	void Render(); //更新畫面
	int score() { //回傳當前分數
		return s;
	}
private:
	const char* c;//紀錄顏色
	int s; //紀錄分數
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};

