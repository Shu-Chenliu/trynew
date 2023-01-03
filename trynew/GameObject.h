#pragma once
#include"Game.h"
class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y, int w, int h);
	GameObject(const char* texturesheet, int x, int y, int w, int h, double ww, double hh);
	~GameObject();
	virtual void Update();
	virtual void Render();
	virtual bool touchground(); //�P�_�O�_���a
	virtual int getxpos() { //�^��x�y��
		return xpos;
	}
	virtual int getypos() { //�^��y�y��
		return ypos;
	}
	virtual void setxpos(int x) { //�]�wx�y��
		xpos = x;
	}
	virtual void setypos(int y) { //�]�wy�y��
		ypos = y;
	}
	virtual int getxVel() { //�^��x�t��
		return xVel;
	}
	virtual int getyVel() { //�^��y�t��
		return yVel;
	}
	//void move(const Uint8 *keystate);
	//void stop();

protected:
	int xpos; //x�y��
	int ypos; //y�y��
	int xVel; //x�t��
	int yVel; //y�t��
	SDL_Texture* objTexture;
	SDL_Rect srcR, destR;
};