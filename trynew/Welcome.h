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
};