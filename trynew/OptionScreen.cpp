#include "OptionScreen.h"
#include "GameObject.h"
#include "TextureManager.h"
#include"Game.h"
#include<iostream>
#include<string>
using namespace std;
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

OptionScreen::OptionScreen(SDL_Renderer* _renderer,string st,string st2,const char* color) : Screen(_renderer)
{
    std::cout << "opScreen constructor()!" << std::endl;
    const char* texture1 = st.c_str();
    objTexture = TextureManager::loadFont(texture1, color);
    const char* texture2 = st2.c_str();
    objTexture2 = TextureManager::loadFont(texture2, color);
    srcR.x = 0;
    srcR.y = 0;
    srcR.w = 400;
    srcR.h = 100;
    destR.x = 150;
    destR.y = 100;
    destR.w = 300;
    destR.h = 100;
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 400;
    srcR2.h = 100;
    destR2.x = 150;
    destR2.y = 220;
    destR2.w = 300;
    destR2.h = 100;
}

OptionScreen::~OptionScreen()
{
    std::cout << "StartScreen deconstructor()!" << std::endl;
}

void OptionScreen::handleEvents(const Uint8* keystate, bool& start,bool &option,bool& target) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 0) {
            arrow->setypos(arrow->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 120)
        {
            arrow->setypos(arrow->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 120) {
            start = true;
            option = false;
            target = false;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 0) {
            start = false;
            option = false;
            target = false;
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
}

void OptionScreen::update() {
    screen->Update();
    arrow->Update();
}

void OptionScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    screen->Render();
    arrow->Render();
    SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
    SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderPresent(renderer);
}