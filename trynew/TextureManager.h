#pragma once
#include"Game.h"
#include<SDL_ttf.h>
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
	static SDL_Texture* loadFont(const std::string& text);
};