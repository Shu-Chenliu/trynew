#include"TextureManager.h"
SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	SDL_Surface* tmpsurface = IMG_Load(texture);
	SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);
	return text;
}
void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, text, &src, &dest);
}