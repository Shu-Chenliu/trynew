#include "Ball.h"
#include"TextureManager.h"
Ball::Ball(const char* texturesheet, int x, int y,int w,int h) :GameObject(texturesheet, x, y,w,h) {
	srcR.h = 396;
	srcR.w = 454;
	destR.w = srcR.w * 0.3;
	destR.h = srcR.h * 0.3;
}
void Ball::Update() {
	yVel += a;
	ypos += yVel;
	if (ypos > 499 && yVel>0) {
		yVel = -yVel;
	}
	destR.x = xpos;
	destR.y = ypos;
}
void Ball::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}