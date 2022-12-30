#include"TextureManager.h"
#include<string>
using namespace std;
TTF_Font* Sans = nullptr;
SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tmpsurface = IMG_Load(texture);
	SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);
	return text;
}
void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, text, &src, &dest);
}
SDL_Texture* TextureManager::loadFont(const string& text,const char* color){
    const char* str = text.c_str();
    if (!TTF_WasInit()) {
        TTF_Init();
    }
    if (!Sans) {
        Sans = TTF_OpenFont("assets/TEMPSITC.TTF", 24);
    }
    if (!Sans) {
        cout << "fonts error: " << TTF_GetError() << endl;
    }
    SDL_Color c;
    if (color == "red") {
        c = { 220, 20, 60 };
    }
    else if (color == "black") {
        c = { 0,0,0 };
    }
    SDL_Surface* tempSurface = TTF_RenderText_Solid(Sans, str, c);
    if (tempSurface == NULL) {
        cout << "fonts not loaded: " << SDL_GetError() << endl;
    }
    SDL_Texture* message = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return message;
};