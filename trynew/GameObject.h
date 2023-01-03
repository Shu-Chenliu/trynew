#pragma once
#include"Game.h"
class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y, int w, int h);
	GameObject(const char* texturesheet, int x, int y, int w, int h, double ww, double hh);
	~GameObject();
	virtual void Update();
	virtual void Render();
	virtual bool touchground(); //判斷是否落地
	virtual int getxpos() { //回傳x座標
		return xpos;
	}
	virtual int getypos() { //回傳y座標
		return ypos;
	}
	virtual void setxpos(int x) { //設定x座標
		xpos = x;
	}
	virtual void setypos(int y) { //設定y座標
		ypos = y;
	}
	virtual int getxVel() { //回傳x速度
		return xVel;
	}
	virtual int getyVel() { //回傳y速度
		return yVel;
	}
	//void move(const Uint8 *keystate);
	//void stop();

protected:
	int xpos; //x座標
	int ypos; //y座標
	int xVel; //x速度
	int yVel; //y速度
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};