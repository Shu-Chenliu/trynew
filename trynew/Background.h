#pragma once
#include "Screen.h"
#include"Game.h"
class BackgroundScreen : public Screen
{
public:
    explicit BackgroundScreen(SDL_Renderer* _renderer, string st, string st2, const char* color);
    ~BackgroundScreen();
    virtual void handleEvents(const Uint8* keystate, bool& start, bool& option, bool& target,bool& bg,int& whichbackground);
    virtual void update() override;
    virtual void render() override;
private:
    SDL_Texture* objTexture;
    SDL_Texture* objTexture2;
    SDL_Texture* objTexture3;
    SDL_Texture* objTexture4;
    //GameObject* arrow2 = nullptr;
    SDL_Rect srcR, destR;
    SDL_Rect srcR2, destR2;
};