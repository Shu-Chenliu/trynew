#include "Welcome.h"
#include "GameObject.h"
#include "TextureManager.h"
#include"Game.h"
#include<iostream>
using namespace std;
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

StartScreen::StartScreen(SDL_Renderer* _renderer,string st1,string st2,string st3, const char* color) : Screen(_renderer)
{
    std::cout << "StartScreen constructor()!" << std::endl;
    const char* texture1 = st1.c_str();
    objTexture1 = TextureManager::loadFont(texture1, color);
    const char* texture2 = st2.c_str();
    objTexture2 = TextureManager::loadFont(texture2, color);
    const char* texture3 = st3.c_str();
    objTexture3 = TextureManager::loadFont(texture3, color);
    srcR1.x = 0;
    srcR1.y = 0;
    srcR1.w = 400;
    srcR1.h = 100;
    destR1.x = 150;
    destR1.y = 100;
    destR1.w = 300;
    destR1.h = 100;
    srcR2.x = 0;
    srcR2.y = 0;
    srcR2.w = 400;
    srcR2.h = 100;
    destR2.x = 150;
    destR2.y = 160;
    destR2.w = 300;
    destR2.h = 100;
    srcR3.x = 0;
    srcR3.y = 0;
    srcR3.w = 400;
    srcR3.h = 100;
    destR3.x = 150;
    destR3.y = 220;
    destR3.w = 300;
    destR3.h = 100;
}

StartScreen::~StartScreen()
{
    std::cout << "StartScreen deconstructor()!" << std::endl;
}

void StartScreen::handleEvents(const Uint8* keystate,bool &start,bool &option,bool& target){
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 60) {
            arrow->setypos(arrow->getypos() + 60);
        }
        if (keystate[SDL_SCANCODE_DOWN] && arrow->getypos() == 0) {
            arrow->setypos(arrow->getypos() + 60);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 60){
            arrow->setypos(arrow->getypos() - 60);
        }
        if (keystate[SDL_SCANCODE_UP] && arrow->getypos() == 120){
            arrow->setypos(arrow->getypos() - 60);
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 0) {
            target = true;
            start = false;
            option = false;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 60) {
            option = true;
            start = false;
            target = false;
        }
        if (keystate[SDL_SCANCODE_RETURN] && arrow->getypos() == 120) {
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

void StartScreen::update(){
    screen->Update();
    arrow->Update();
}

void StartScreen::render()
{
    SDL_RenderClear(renderer);
    // this is where we put things to render
    screen->Render();
    arrow->Render();
    SDL_RenderCopy(Game::renderer, objTexture1, &srcR1, &destR1);
    SDL_RenderCopy(Game::renderer, objTexture2, &srcR2, &destR2);
    SDL_RenderCopy(Game::renderer, objTexture3, &srcR3, &destR3);
    SDL_RenderPresent(renderer);
}