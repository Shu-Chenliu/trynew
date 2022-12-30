#include"Background.h"
#include "GameObject.h"
#include "TextureManager.h"
#include"Game.h"
#include<iostream>
#include<string>
using namespace std;
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

BackgroundScreen::BackgroundScreen(SDL_Renderer* _renderer, string st, string st2, const char* color) : Screen(_renderer)
{
    cout << "opScreen constructor()!" << endl;
    //const char* texture1 = st.c_str();
    //objTexture = TextureManager::loadFont("player1",color);
    //const char* texture2 = st2.c_str();
    //objTexture2 = TextureManager::loadFont("player2",color);
    arrow = new GameObject("assets/arrow.png", 0, 0, 517, 483, 0.1, 0.1);
    //arrow2 = new GameObject("assets/arrow.png", 400, 0, 517, 483, 0.1, 0.1);
    srcR.x = 0;
    srcR.y = 0;
    srcR.w = 400;
    srcR.h = 100;
    destR.x = 80;
    destR.y = -20;
    destR.w = 300;
    destR.h = 100;
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 400;
    srcR2.h = 100;
    destR2.x = 80;
    destR2.y = 90;
    destR2.w = 300;
    destR2.h = 100;
}

BackgroundScreen::~BackgroundScreen()
{
    cout << "BackgroundScreen deconstructor()!" << endl;
}

void BackgroundScreen::handleEvents(const Uint8* keystate, bool& start, bool& option, bool& target,bool& bg,int& whichbackground) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 120) {
            arrow->setypos(arrow->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 0) {
            arrow->setypos(arrow->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 240)
        {
            arrow->setypos(arrow->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 120)
        {
            arrow->setypos(arrow->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 0) {//0-0
            start = true;
            option = false;
            target = false;
            bg = false;
            whichbackground = 0;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 120) {//0-1
            start = true;
            option = false;
            target = false;
            bg = false;
            whichbackground = 1;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 240) {//0-2
            start = true;
            option = false;
            target = false;
            bg = false;
            whichbackground = 2;
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
}

void BackgroundScreen::update() {
    screen->Update();
    arrow->Update();
    //arrow2->Update();
}

void BackgroundScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    screen->Render();
    arrow->Render();
    //arrow2->Render();
    //SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
    //SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderPresent(renderer);
}