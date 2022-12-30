#pragma once
#include"Game.h"
class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y,int w,int h);
	GameObject(const char* texturesheet, int x, int y, int w, int h, double ww, double hh);
	~GameObject();
	virtual void Update();
	virtual void Render();
	virtual bool touchground();
	virtual void reset();
	virtual char getwin();
	virtual int getxpos() {
		return xpos;
	}
	virtual int getypos() {
		return ypos;
	}
	virtual void setxpos(int x) {
		xpos = x;
	}
	virtual void setypos(int y) {
		ypos = y;
	}
	virtual int getxVel() {
		return xVel;
	}
	virtual int getyVel() {
		return yVel;
	}
	//void move(const Uint8 *keystate);
	//void stop();
protected:
	int xpos;
	int ypos;
	bool isDashing = false;
	int xVel;
	int yVel;
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
	//SDL_Renderer* renderer;
};