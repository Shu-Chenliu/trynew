#pragma once
#include"GameObject.h"
#include"Player.h"
class Ball:public GameObject{
private:
	int a=1;
	char win;
	int radius;
public:
	Ball(const char* texturesheet, int x, int y,int w,int h);
	~Ball();
	void Update();
	void Render();
	bool touchground();
	bool checkCollision(Player* p1, Player* p2, const Uint8* keystate);
	int getxpos() {
		return xpos;
	}
	int getypos() {
		return ypos;
	}
	int getradius() {
		return radius;
	}
	void reset();
	char getwin();
	Mix_Chunk* scoresound = NULL;
};

