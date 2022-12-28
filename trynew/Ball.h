#pragma once
#include"GameObject.h"
class Ball:public GameObject{
private:
	int a=1;
public:
	Ball(const char* texturesheet, int x, int y,int w,int h);
	~Ball();
	void Update();
	void Render();
};

