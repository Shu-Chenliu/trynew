#include <cmath>
#include "Ball.h"
#include"TextureManager.h"
#include<iostream>
using namespace std;
Ball::Ball(const char* texturesheet, int x, int y,int w,int h) :GameObject(texturesheet, x, y,w,h) {
	srcR.h = 396;
	srcR.w = 454;
	destR.w = srcR.w * 0.3;
	destR.h = srcR.h * 0.3;
	win = 'l';
}
void Ball::Update() {
	yVel += a;
	ypos += yVel;
	xpos += xVel;
	destR.x = xpos;
	destR.y = ypos;
}
bool Ball::touchground() {
	if (ypos > 520) {
		if (xpos <= 264) {
			win = 'r';
		}
		else {
			win = 'l';
		}
		return true;
	}
	return false;
}
void Ball::reset() {
	if (win == 'l') {
		xpos = 200;
		ypos = 0;
		yVel = 0;
		xVel = 0;
	}
	else {
		xpos = 600;
		ypos = 0;
		yVel = 0;
		xVel = 0;
	}
}
void Ball::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}
char Ball::getwin() {
	return win;
}