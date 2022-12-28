#pragma once
#include"Game.h"
class GameObject {
public:
	GameObject(const char* texturesheet, int x, int y,int w,int h);
	~GameObject();
	virtual void Update();
	virtual void Render();
	virtual bool touchground();
	virtual void reset();
	virtual char getwin();
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