#pragma once
#include"Game.h"
#include"TextureManager.h"
#include<string>
using namespace std;
class Score {
public:
	Score(string st, int x, int y, int w, int h, const char* color);
	~Score();
	void Update(); //��s�Ѽ�
	void Render(); //��s�e��
	int score() { //�^�Ƿ�e����
		return s;
	}
private:
	const char* c;//�����C��
	int s; //��������
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};

