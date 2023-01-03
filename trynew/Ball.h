#pragma once
#include"GameObject.h"
#include"Player.h"
class Ball:public GameObject{
private:
	int a=1;//加速度
	char win;//紀錄贏家
	int radius;//球半徑
	Mix_Chunk* scoresound = NULL;
	Mix_Chunk* spikesound = NULL;
public:
	Ball(const char* texturesheet, int x, int y,int w,int h);
	~Ball();
	void Update();
	void Render();
	bool touchground();//判斷是否落地
	bool checkCollision(Player* p1, Player* p2, const Uint8* keystate);//判斷有無碰撞
	int getxpos() {
		return xpos;
	}
	int getypos() {
		return ypos;
	}
	int getradius() {
		return radius;
	}
	void reset(); //重新發球
	char getwin(); //紀錄贏家
};

