#include "Player.h"
#include"GameObject.h"
Player::Player(const char* texturesheet, int x, int y, int w, int h,char a) :GameObject(texturesheet, x, y, w, h) {
    destR.w = srcR.w * 0.5;
    destR.h = srcR.h * 0.5;
    position = a;
}
void Player::Update() {
    yVel += 1;
    xpos += xVel;
    ypos += yVel;
    if (ypos >= 430) {
        yVel = 0;
        ypos = 430;
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
        if (xpos <= 400 && xVel < 0) {
            xpos = 400;
        }
        if (xpos >= 680 && xVel > 0) {
            xpos = 680;
        }
    }
    destR.x = xpos;
    destR.y = ypos;
}
void Player::Render() {
    GameObject::Render();
}
void Player::move(const Uint8 *keystate) {
    /*if (arr[SDLK_LEFT] && xpos > 404) {
        xVel = -4;
    }
    if (arr[SDLK_a] && xpos <= 400 && xpos > 4) {
        xVel = -4;
    }
    if (arr[SDLK_RIGHT] && xpos > 400 && xpos < 796) {
        xVel = 4;
    }
    if (arr[SDLK_d] && xpos < 396 && xpos>=0) {
        xVel = 4;
    }*/
    if (position == 'l') {
        if (keystate[SDL_SCANCODE_LSHIFT] && !isDashing && xpos <= 400 && xpos >= 4) {
            xVel = -4;
        }
        if (keystate[SDL_SCANCODE_RSHIFT] && !isDashing && xpos <= 396) {
            xVel = 4;
        }
    }
    if (position == 'r') {
        if (keystate[SDL_SCANCODE_LEFT] && !isDashing && xpos >= 404) {// left
            xVel = -4;
        }
        if (keystate[SDL_SCANCODE_RIGHT] && !isDashing && xpos >= 400 && xpos <= 796){
            xVel = 4;
        }
    }
    if (keystate[SDL_SCANCODE_LALT] && ypos >= 422) {
        yVel = -26;
    }
    if (keystate[SDL_SCANCODE_UP] && ypos >= 422){ // jump and from ground only
        //Mix_PlayChannel(-1, jumpSound, 0);
        yVel = -26;
    }
    /*if ((keystate[SDL_SCANCODE_LEFT] && keystate[SDL_SCANCODE_SPACE])) // left dash
        if ((flag == 'L' && xpos > 0 && ypos + height == GAME_HEIGHT) || (flag == 'R' && xpos > GAME_WIDTH / 2 && ypos + height == GAME_HEIGHT))
        {
            SDL_DestroyTexture(objTexture);
            objTexture = TextureManager::loadTexture("images/left_dash_pikachu.png");
            Mix_PlayChannel(-1, dashSound, 0);
            xVel = -1; // dummy value for handling dashing
            yVel = DASH_YVEL;

            isDashing = true;
        }
    if ((keystate[SDL_SCANCODE_RIGHT] && keystate[SDL_SCANCODE_SPACE])) // right dash
        if ((flag == 'L' && xpos > 0 && ypos + height == GAME_HEIGHT) || (flag == 'R' && xpos > GAME_WIDTH / 2 && ypos + height == GAME_HEIGHT))
        {
            SDL_DestroyTexture(objTexture);
            objTexture = TextureManager::loadTexture("images/right_dash_pikachu.png");
            Mix_PlayChannel(-1, dashSound, 0);
            xVel = 1; // dummy value for handling dashing
            yVel = DASH_YVEL;
            isDashing = true;
        }

    if ((keystate[SDL_SCANCODE_LEFT] && keystate[SDL_SCANCODE_LSHIFT]) || didSpike) // left spike
        if ((flag == 'L' && xpos > 0) || (flag == 'R' && xpos > 400))
        {
            GameObject* flame = new GameObject("images/flame.png", 100, 100, getXpos() - 20, getYpos() - 20);
            delete flame;
        }
    if ((keystate[SDL_SCANCODE_RIGHT] && keystate[SDL_SCANCODE_LSHIFT]) || didSpike) // right spike
        if ((flag == 'L' && xpos > 0) || (flag == 'R' && xpos > 400))
        {
            GameObject* flame = new GameObject("images/flame.png", 100, 100, getXpos() - 20, getYpos() - 20);
            delete flame;
        }*/
}
void Player::stop(const Uint8* keystate) {
    xVel = 0;
    //if (ypos+436 > 640) {
        //ypos = 204;
        //yVel = 0;
    //}
}