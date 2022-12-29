#pragma once
#include"Game.h"
#include<SDL_ttf.h>
#include<string>
using namespace std;
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
	static SDL_Texture* loadFont(const string& text,const char* color);
};