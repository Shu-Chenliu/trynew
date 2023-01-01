#include "Player.h"
#include"GameObject.h"
Player::Player(const char* texturesheet, int x, int y, int w, int h,char a) :GameObject(texturesheet, x, y, w, h) {
    destR.w = srcR.w * 0.15;
    destR.h = srcR.h * 0.15;
    position = a;
}
Player::~Player() {
    cout << "player deconstructor()" << endl;
    Mix_FreeChunk(jumpsound);
    jumpsound = NULL;
    cout << "free  jumpsound" << endl;
}
void Player::Update() {
    yVel += 1;
    xpos += xVel;
    ypos += yVel;
    if (ypos >= 490) {
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
void Player::move(const Uint8 *keystate) {
    if (position == 'l') {
        if (keystate[SDL_SCANCODE_A] && !isDashing && xpos <= 284 && xpos >= 4) {
            xVel = -4;
        }
        if (keystate[SDL_SCANCODE_D] && !isDashing && xpos <= 280) {
            xVel = 4;
        }
        if (keystate[SDL_SCANCODE_W] && ypos >= 490) {
            jumpsound = Mix_LoadWAV("assets/jumpsound.ogg");
            if (jumpsound == NULL)
            {
                printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
            }
            yVel = -26;
            Mix_PlayChannel(-1, jumpsound, 0);
        }
    }
    if (position == 'r') {
        if (keystate[SDL_SCANCODE_LEFT] && !isDashing && xpos >= 417) {// left
            xVel = -4;
        }
        if (keystate[SDL_SCANCODE_RIGHT] && !isDashing && xpos >= 413 && xpos <= 682){
            xVel = 4;
        }
        if (keystate[SDL_SCANCODE_UP] && ypos >= 490) { // jump and from ground only
            //Mix_PlayChannel(-1, jumpSound, 0);
            jumpsound = Mix_LoadWAV("assets/jumpsound.ogg");
            if (jumpsound == NULL)
            {
                printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
            }
            yVel = -26;
            Mix_PlayChannel(-1, jumpsound, 0);
            yVel = -26;
        }
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