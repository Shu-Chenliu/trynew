#include <cmath>
#include "Ball.h"
#include"Player.h"
#include"TextureManager.h"
#include<iostream>
using namespace std;
Ball::Ball(const char* texturesheet, int x, int y,int w,int h) :GameObject(texturesheet, x, y,w,h) {
	srcR.h = 474;
	srcR.w = 474;
	destR.w = srcR.w * 0.2;
	destR.h = srcR.h * 0.2;
	win = 'r';
    radius = 47;
}
Ball::~Ball() {
    cout << "Ball deconstructor()" << endl;
    Mix_FreeChunk(scoresound);
    scoresound = NULL;
    Mix_FreeChunk(spikesound);
    spikesound = NULL;
    cout << "free sound" << endl;
}
void Ball::Update() {
	yVel += a;
	ypos += yVel;
	xpos += xVel;
	destR.x = xpos;
	destR.y = ypos;
}
bool Ball::touchground() {
    scoresound = Mix_LoadWAV("assets/scoresound.ogg");
    if (scoresound == NULL)
    {
        printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }
	if (ypos > 540) {
		if (xpos <= 352) {
			win = 'r';
		}
		else {
			win = 'l';
		}
        Mix_PlayChannel(-1, scoresound, 0);
		return true;
	}
	return false;
}
bool Ball::checkCollision(Player* p1, Player* p2, const Uint8* keystate)
{
    int ballX = getxpos()+47;
    int ballY = getypos()+47;
    int p1X = p1->getxpos()+67;
    int p1Y = p1->getypos()+67;
    int p2X = p2->getxpos()+67;
    int p2Y = p2->getypos()+67;
    spikesound = Mix_LoadWAV("assets/spikesound1.ogg");
    float p1RealDistance = sqrt(pow(ballX - p1X, 2) + pow(ballY - p1Y, 2));
    float p1TouchedDistance = getradius() + 67;
    float p2RealDistance = sqrt(pow(ballX - p2X, 2) + pow(ballY - p2Y, 2));
    float p2TouchedDistance = getradius() + 67;

    //if the ball touches the player..
    if (p1RealDistance <= p1TouchedDistance) {
        if (ballX < p1X)
        {
            xVel = (p1X - ballX) / 9;
            xVel = -xVel;
            yVel = -27;
        }
        else if (ballX > p1X)
        {
            if (p1Y < 490 && keystate[SDL_SCANCODE_D]) {
                xVel = (p1X - ballX)/5;
                yVel = 5;
                Mix_PlayChannel(-1, spikesound, 0);
            }
            else {
                xVel = (ballX - p1X) / 9;
                yVel = -27;
            }
            
        }
        
        return true;
    }

    if (p2RealDistance <= p2TouchedDistance)
    {
        if (ballX < p2X)
        {
            if (p2Y < 490 && keystate[SDL_SCANCODE_LEFT]) {
                xVel = (ballX - p2X)/5;
                yVel = 5;
                Mix_PlayChannel(-1, spikesound, 0);
            }
            else {
                xVel = (p2X - ballX) / 9;
                xVel = -xVel;
                yVel = -27;
            }
            
        }
        else if (ballX > p2X)
        {
            xVel = (ballX - p2X) / 9;
            yVel = -27;
        }
        
        return true;
    }
    if (xpos <= 400 && xpos >= 300 && ypos >= 245 && yVel > 0 && xVel > 0) {
        yVel = -yVel;
        return true;
    }
    if (xpos <= 400 && xpos >= 300 && ypos >= 245 && yVel > 0 && xVel < 0) {
        yVel = -yVel;
        return true;
    }
    if (xpos <= 350 && xpos >= 280 && xVel > 0 && ypos >= 270) {
        xVel = -xVel;
        return true;
    }
    if (xpos >= 365 && xpos <= 425 && xVel < 0 && ypos >= 270) {
        xVel = -xVel;
        return true;
    }
    
    if (xpos >= 706 && xVel > 0) {
        xVel = -xVel;
        return true;
    }
    if (xpos < 0 && xVel < 0) {
        xVel = -xVel;
        return true;
    }
    return false;
};

void Ball::reset() {
	if (win == 'l') {
		xpos = 200;
		ypos = 0;
		yVel = 0;
		xVel = 0;
	}
	else {
		xpos = 600;
		ypos = 0;
		yVel = 0;
		xVel = 0;
	}
}
void Ball::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}
char Ball::getwin() {
	return win;
}