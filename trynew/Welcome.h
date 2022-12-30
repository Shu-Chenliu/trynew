#pragma once
#include "Screen.h"
#include"Game.h"
class StartScreen : public Screen
{
public:
    explicit StartScreen(SDL_Renderer* _renderer, string st1,string st2,string st3, const char* color);
    ~StartScreen();
    virtual void handleEvents(const Uint8* keystate,bool &start,bool& option,bool& target,bool& bg);
    virtual void update() override;
    virtual void render() override;
private:
    SDL_Texture* objTexture1;
    SDL_Texture* objTexture2;
    SDL_Texture* objTexture3;
    SDL_Rect srcR1, destR1;
    SDL_Rect srcR2, destR2;
    SDL_Rect srcR3, destR3;
    SDL_Rect srcR4, destR4;
};