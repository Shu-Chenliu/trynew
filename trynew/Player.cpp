#include "Player.h"
#include"GameObject.h"
Player::Player(const char* texturesheet, int x, int y, int w, int h) :GameObject(texturesheet, x, y, w, h) {
    destR.w = srcR.w * 0.5;
    destR.h = srcR.h * 0.5;
}
void Player::Update() {
    GameObject::Update();
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
    //if (keystate[SDL_SCANCODE_UP] && ypos == 640 - srcR.h) // jump and from ground only
    {
        //Mix_PlayChannel(-1, jumpSound, 0);
        //yVel = JUMP_YVEL;
    }
    if (keystate[SDL_SCANCODE_A] && !isDashing ){//&& xpos <= 400 && xpos >= 4) {
        xVel = -4;
    }
    if (keystate[SDL_SCANCODE_LEFT] && !isDashing)//&& xpos>=404) // left
        //if ((flag == 'L' && xpos > 5) || (flag == 'R' && xpos > GAME_WIDTH / 2))
    {
        xVel = -4;
    }
    if (keystate[SDL_SCANCODE_SPACE] && !isDashing){ //&& xpos <= 396) {
        xVel = 4;
    }
    if (keystate[SDL_SCANCODE_RIGHT] && !isDashing) //&& xpos>=400 && xpos<=796) // right
        //if ((flag == 'L' && xpos + width < GAME_WIDTH / 2) || (flag == 'R' && xpos + width < GAME_WIDTH - 5))
    {
        xVel = 4;
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
}