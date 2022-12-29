#pragma once
#include "Screen.h"
#include"Game.h"
class TargetScreen : public Screen
{
public:
    explicit TargetScreen(SDL_Renderer* _renderer, string st1, const char* color);
    ~TargetScreen();
    virtual void handleEvents(const Uint8* keystate, bool& start, bool& option,bool& target);
    virtual void update() override;
    virtual void render() override;
private:
    SDL_Texture* objTexture1;
    SDL_Rect srcR1, destR1;
    int t = 3;
};