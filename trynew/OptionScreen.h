#pragma once
#include "Screen.h"
#include"Game.h"
class OptionScreen : public Screen
{
public:
    explicit OptionScreen(SDL_Renderer* _renderer,string st,string st2,const char* color);
    ~OptionScreen();
    virtual void handleEvents(const Uint8* keystate, bool& start,bool& option,bool& target);
    virtual void update() override;
    virtual void render() override;
private:
    SDL_Texture* objTexture;
    SDL_Texture* objTexture2;
    SDL_Rect srcR, destR;
    SDL_Rect srcR2, destR2;
};