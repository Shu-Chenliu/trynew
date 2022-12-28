#include"TextureManager.h"
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
SDL_Texture* TextureManager::loadFont(const std::string& text)
{
    const char* str = text.c_str();
    if (!TTF_WasInit())
        TTF_Init();
    if (!Sans)
        Sans = TTF_OpenFont("assets/OdibeeSansRegular.ttf", 24);
    if (!Sans)
        std::cout << "fonts error: " << TTF_GetError() << std::endl;
    SDL_Color Red = { 220, 20, 60 };

    SDL_Surface* tempSurface = TTF_RenderText_Solid(Sans, str, Red);
    if (tempSurface == NULL)
        std::cout << "fonts not loaded: " << SDL_GetError() << std::endl;

    SDL_Texture* message = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return message;
};