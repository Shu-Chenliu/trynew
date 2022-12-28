#pragma once
#include"GameObject.h"
class Player:public GameObject{
public:
	Player(const char* texturesheet, int x, int y, int w, int h,char a);
	~Player();
	void Update();
	void Render();
	void move(const Uint8* keystate);
	void stop(const Uint8* keystate);
private:
	char position;
};

