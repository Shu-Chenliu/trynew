#include "OptionScreen.h"
#include "GameObject.h"
#include "TextureManager.h"
#include"Game.h"
#include<iostream>
#include<string>
using namespace std;
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

OptionScreen::OptionScreen(SDL_Renderer* _renderer, string st, string st2, const char* color) : Screen(_renderer)
{
    cout << "opScreen constructor()!" << endl;
    arrow = new GameObject("assets/arrow.png", 15, 295, 517, 483, 0.1, 0.1);
    arrow2 = new GameObject("assets/arrow.png", 400, 295, 517, 483, 0.1, 0.1);
    screen = new GameObject("assets/option.png", 0, 0, 800, 640);
    srcR.x = 0;
    srcR.y = 0;
    srcR.w = 800;
    srcR.h = 640;
    destR.x = 0;
    destR.y = 0;
    destR.w = 800;
    destR.h = 640;
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 400;
    srcR2.h = 100;
    destR2.x = 80;
    destR2.y = 90;
    destR2.w = 300;
    destR2.h = 100;
}

OptionScreen::~OptionScreen()
{
    cout << "StartScreen deconstructor()!" << endl;
}

void OptionScreen::handleEvents(const Uint8* keystate, bool& start, bool& option, bool& target, bool& bg, int& p1, int& p2) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_W] && arrow->getypos() == 560) {
            arrow->setypos(arrow->getypos() - 132);
        }
        else if (keystate[SDL_SCANCODE_W] && arrow->getypos() == 428) {
            arrow->setypos(arrow->getypos() - 133);
        }
        else if (keystate[SDL_SCANCODE_S] && arrow->getypos() == 428) {
            arrow->setypos(arrow->getypos() + 132);
        }
        else if (keystate[SDL_SCANCODE_S] && arrow->getypos() == 295) {
            arrow->setypos(arrow->getypos() + 133);
        }
        else if (keystate[SDL_SCANCODE_DOWN] && arrow2->getypos() == 428) {
            arrow2->setypos(arrow2->getypos() + 132);
        }
        else if (keystate[SDL_SCANCODE_DOWN] && arrow2->getypos() == 295) {
            arrow2->setypos(arrow2->getypos() + 133);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow2->getypos() == 560)
        {
            arrow2->setypos(arrow2->getypos() - 132);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow2->getypos() == 428)
        {
            arrow2->setypos(arrow2->getypos() - 133);
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 295 && arrow2->getypos() == 295) {//0-0
            start = true;
            option = false;
            target = false;
            p1 = 0;
            p2 = 0;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 295 && arrow2->getypos() == 428) {//0-1
            start = true;
            option = false;
            target = false;
            p1 = 0;
            p2 = 1;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 295 && arrow2->getypos() == 560) {//0-2
            start = true;
            option = false;
            target = false;
            p1 = 0;
            p2 = 2;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 428 && arrow2->getypos() == 295) {//1-0
            start = true;
            option = false;
            target = false;
            p1 = 1;
            p2 = 0;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 428 && arrow2->getypos() == 428) {//1-1
            start = true;
            option = false;
            target = false;
            p1 = 1;
            p2 = 1;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 428 && arrow2->getypos() == 560) {//1-2
            start = true;
            option = false;
            target = false;
            p1 = 1;
            p2 = 2;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 560 && arrow2->getypos() == 295) {//2-0
            start = true;
            option = false;
            target = false;
            p1 = 2;
            p2 = 0;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 560 && arrow2->getypos() == 428) {//2-1
            start = true;
            option = false;
            target = false;
            p1 = 2;
            p2 = 1;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 560 && arrow2->getypos() == 560) {//2-2
            start = true;
            option = false;
            target = false;
            p1 = 2;
            p2 = 2;
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
    arrow2->Update();
}

void OptionScreen::render()
{
    SDL_RenderClear(renderer);
    screen->Render();
    arrow->Render();
    arrow2->Render();
    SDL_RenderPresent(renderer);
}