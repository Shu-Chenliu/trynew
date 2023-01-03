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
    arrow = new GameObject("assets/arrow.png", 150, 180, 517, 483, 0.1, 0.1);
    screen = new GameObject("assets/backgroundop.png", 0, 0, 800, 640);
}

BackgroundScreen::~BackgroundScreen()
{
    cout << "BackgroundScreen deconstructor()!" << endl;
}

void BackgroundScreen::handleEvents(const Uint8* keystate, bool& start, bool& option, bool& target, bool& bg, int& whichbackground) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 180) {
            arrow->setypos(arrow->getypos() + 180);
        }
        else if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 360) {
            arrow->setypos(arrow->getypos() + 180);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 360)
        {
            arrow->setypos(arrow->getypos() - 180);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 540)
        {
            arrow->setypos(arrow->getypos() - 180);
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 180) {//0-0
            start = true;
            option = false;
            target = false;
            bg = false;
            whichbackground = 0;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 360) {//0-1
            start = true;
            option = false;
            target = false;
            bg = false;
            whichbackground = 1;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 540) {//0-2
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
    screen->Render();
    arrow->Render();
    SDL_RenderPresent(renderer);
}