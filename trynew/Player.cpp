#include "Player.h"
#include"GameObject.h"
Player::Player(const char* texturesheet, int x, int y, int w, int h, char a) :GameObject(texturesheet, x, y, w, h) {
    destR.w = srcR.w * 0.15;
    destR.h = srcR.h * 0.15;
    position = a;
}
Player::~Player() {
    cout << "player deconstructor()" << endl;
    Mix_FreeChunk(jumpsound);
    jumpsound = NULL;
    cout << "free  jumpsound" << endl;
    Mix_FreeChunk(dashsound);
    dashsound = NULL;
}
void Player::Update() {
    yVel += 1;
    xpos += xVel;
    ypos += yVel;
    if (ypos >= 490) {//¦b¦aªO
        yVel = 0;
        ypos = 490;
    }
    if (position == 'l') {
        if (xpos >= 280 && xVel > 0) {
            xpos = 280;
        }
        if (xpos <= 0 && xVel < 0) {
            xpos = 0;
        }
    }
    if (position == 'r') {
        if (xpos <= 413 && xVel < 0) {
            xpos = 413;
        }
        if (xpos >= 682 && xVel > 0) {
            xpos = 682;
        }
    }
    destR.x = xpos;
    destR.y = ypos;
}
void Player::Render() {
    GameObject::Render();
}
void Player::move(const Uint8* keystate) {
    jumpsound = Mix_LoadWAV("assets/jumpsound.ogg");
    if (jumpsound == NULL)
    {
        printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
    dashsound = Mix_LoadWAV("assets/dashsound.ogg");
    if (dashsound == NULL)
    {
        printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }

    if (position == 'l') {
        if (keystate[SDL_SCANCODE_A] && xpos <= 284 && xpos >= 4) {
            if (keystate[SDL_SCANCODE_LSHIFT]) {
                xVel = -10;
                Mix_PlayChannel(-1, dashsound, 0);
            }
            else xVel = -4;
        }
        if (keystate[SDL_SCANCODE_D] && xpos <= 280) {
            if (keystate[SDL_SCANCODE_LSHIFT]) {
                xVel = 10;
                Mix_PlayChannel(-1, dashsound, 0);
            }
            else xVel = 4;
        }
        if (keystate[SDL_SCANCODE_W] && ypos >= 490) {
            yVel = -26;
            Mix_PlayChannel(-1, jumpsound, 0);
        }
    }
    if (position == 'r') {
        if (keystate[SDL_SCANCODE_LEFT] && xpos >= 417) {// left
            if (keystate[SDL_SCANCODE_RSHIFT]) {
                xVel = -10;
                Mix_PlayChannel(-1, dashsound, 0);
            }
            else xVel = -4;
        }
        if (keystate[SDL_SCANCODE_RIGHT] && xpos >= 413 && xpos <= 682) {
            if (keystate[SDL_SCANCODE_RSHIFT]) {
                xVel = 10;
                Mix_PlayChannel(-1, dashsound, 0);
            }
            else xVel = 4;
        }
        if (keystate[SDL_SCANCODE_UP] && ypos >= 490) { // jump and from ground only
            yVel = -26;
            Mix_PlayChannel(-1, jumpsound, 0);
        }
    }
}
void Player::stop(const Uint8* keystate) {
    xVel = 0;
}