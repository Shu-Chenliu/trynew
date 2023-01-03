#include "Welcome.h"
#include "GameObject.h"
#include "TextureManager.h"
#include"Game.h"
#include<iostream>
using namespace std;
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

StartScreen::StartScreen(SDL_Renderer* _renderer, string st1, string st2, string st3, const char* color) : Screen(_renderer)
{
    cout << "StartScreen constructor()!" << endl;

    arrow = new GameObject("assets/arrow.png", 5, 280, 517, 483, 0.1, 0.1);
    screen = new GameObject("assets/start.png", 0, 0, 800, 640);
}

StartScreen::~StartScreen()
{
    cout << "StartScreen deconstructor()!" << endl;
}

void StartScreen::handleEvents(const Uint8* keystate, bool& start, bool& option, bool& target, bool& bg) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 280) {
            //cout << "D280 pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() + 90);
        }
        else if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 370) {
            //cout << "D370 pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() + 87);
        }
        else if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 457) {
            //cout << "D455 pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() + 90);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 547) {
            //cout << "540U pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() - 90);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 457) {
            //cout << "455U pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() - 87);
        }
        else if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 370) {
            //cout << "370U pos:" << arrow->getypos() << endl;
            arrow->setypos(arrow->getypos() - 90);
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 280) {
            //cout << "1pos:" << arrow->getypos() << endl;
            target = true;
            start = false;
            option = false;
            bg = false;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 370) {
            //cout << "2pos:" << arrow->getypos() << endl;
            option = true;
            start = false;
            target = false;
            bg = false;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 457) {
            //cout << "3pos:" << arrow->getypos() << endl;
            start = false;
            option = false;
            target = false;
            bg = true;
        }
        else if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 547) {
            //cout << "4pos:" << arrow->getypos() << endl;
            start = false;
            option = false;
            target = false;
            bg = false;
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
}

void StartScreen::update() {
    screen->Update();
    arrow->Update();
}

void StartScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    screen->Render();
    arrow->Render();
    SDL_RenderPresent(renderer);
}