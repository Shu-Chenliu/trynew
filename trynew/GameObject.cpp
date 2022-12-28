#include "GameObject.h"
#include"TextureManager.h"
#include<iostream>
using namespace std;
GameObject::GameObject(const char* texturesheet, int x, int y,int w,int h) {
	//renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	srcR.h = h;
	srcR.w = w;
	srcR.x = 0;
	srcR.y = 0;
	destR.x = xpos;
	destR.y = ypos;
	destR.w = srcR.w;
	destR.h = srcR.h;
    xVel = 0;
    yVel = 0;
}
GameObject::~GameObject() {

}
void GameObject::Update() {
	xpos+=xVel;
	ypos+=yVel;
	destR.x = xpos;
	destR.y = ypos;
}
void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}
