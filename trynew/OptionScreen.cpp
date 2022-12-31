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
    cout << "opScreen constructor()!" << endl;
    //const char* texture1 = st.c_str();
    //objTexture = TextureManager::loadFont("player1",color);
    //const char* texture2 = st2.c_str();
    //objTexture2 = TextureManager::loadFont("player2",color);
    arrow = new GameObject("assets/arrow.png", 0, 0, 517, 483, 0.1, 0.1);
    arrow2=new GameObject("assets/arrow.png", 400, 0, 517, 483, 0.1, 0.1);
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

void OptionScreen::handleEvents(const Uint8* keystate, bool& start,bool &option,bool& target,bool& bg,int& p1,int& p2) {
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_W] && arrow->getypos() == 120) {
            arrow->setypos(arrow->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_W] && arrow->getypos() == 240) {
            arrow->setypos(arrow->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_S] && arrow->getypos() == 120) {
            arrow->setypos(arrow->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_S] && arrow->getypos() == 0) {
            arrow->setypos(arrow->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_DOWN] && arrow2->getypos() == 120) {
            arrow2->setypos(arrow2->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_DOWN] && arrow2->getypos() == 0) {
            arrow2->setypos(arrow2->getypos() + 120);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow2->getypos() == 120)
        {
            arrow2->setypos(arrow2->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow2->getypos() == 240)
        {
            arrow2->setypos(arrow2->getypos() - 120);
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos()==0 && arrow2->getypos() == 0) {//0-0
            //cout << "0,0" << endl;
            start = true;
            option = false;
            target = false;
            p1 = 0;
            p2 = 0;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 0 && arrow2->getypos() == 120) {//0-1
            start = true;
            option = false;
            target = false;
            p1 = 0;
            p2 = 1;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 0 && arrow2->getypos() == 240) {//0-2
            start = true;
            option = false;
            target = false;
            p1 = 0;
            p2 = 2;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 120 && arrow2->getypos() == 0) {//1-0
            start = true;
            option = false;
            target = false;
            p1 = 1;
            p2 = 0;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 120 && arrow2->getypos() == 120) {//1-1
            start = true;
            option = false;
            target = false;
            p1 = 1;
            p2 = 1;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 120 && arrow2->getypos() == 240) {//1-2
            start = true;
            option = false;
            target = false;
            p1 = 1;
            p2 = 2;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 240 && arrow2->getypos() ==0) {//2-0
            start = true;
            option = false;
            target = false;
            p1 = 2;
            p2 = 0;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 240 && arrow2->getypos() == 120) {//2-1
            start = true;
            option = false;
            target = false;
            p1 = 2;
            p2 = 1;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 240 && arrow2->getypos() == 240) {//2-2
            start = true;
            option = false;
            target = false;
            p1 = 2;
            p2 = 2;
        }
        /*if (keystate[SDL_SCANCODE_RETURN] && arrow2->getypos() == 0) {
            start = false;
            option = false;
            target = false;
        }*/
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
    // this is where we put things to render
    screen->Render();
    arrow->Render();
    arrow2->Render();
    //SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
    //SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderPresent(renderer);
}