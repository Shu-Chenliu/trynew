#include "TargetScore.h"
#include "GameObject.h"
#include "TextureManager.h"
#include"Game.h"
#include<iostream>
using namespace std;
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

TargetScreen::TargetScreen(SDL_Renderer* _renderer, string st1,const char* color) : Screen(_renderer)
{
    cout << "targetScreen constructor()!" << endl;
    const char* texture1 = st1.c_str();
    objTexture1 = TextureManager::loadFont(texture1, color);
    const char* texture2 = "target score :";
    objTexture2 = TextureManager::loadFont(texture2, color);
    srcR1.x = 0;
    srcR1.y = 0;
    srcR1.w = 40;
    srcR1.h = 50;
    destR1.x = 150;
    destR1.y = 100;
    destR1.w = 160;
    destR1.h = 200;
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 400;
    srcR2.h = 50;
    destR2.x = 150;
    destR2.y = 0;
    destR2.w = 400;
    destR2.h = 100;
}

TargetScreen::~TargetScreen()
{
    cout << "targetScreen deconstructor()!" << endl;
}

void TargetScreen::handleEvents(const Uint8* keystate, bool& start, bool& option,bool& target,bool& bg) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && t > 0) {
            t--;
        }
        if (keystate[SDL_SCANCODE_UP] && t < 25){
            t++;
        }
        if (keystate[SDL_SCANCODE_RETURN]) {
            option = false;
            start = true;
            target = false;
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
}

void TargetScreen::update() {
    screen->Update();
    //arrow->Update();
    string st;
    st = to_string(t);
    const char* texture = st.c_str();
    objTexture1 = TextureManager::loadFont(texture, "black");
}

void TargetScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    screen->Render();
    //arrow->Render();
    SDL_RenderCopy(Game::renderer, objTexture1, &srcR1, &destR1);
    SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderPresent(renderer);
}