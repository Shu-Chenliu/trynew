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
	win = 'l';
    radius = 50;
}
void Ball::Update() {
	yVel += a;
	ypos += yVel;
	xpos += xVel;
	destR.x = xpos;
	destR.y = ypos;
    if (xpos <= 352) {
        win = 'l';
    }
    else {
        win = 'r';
    }
}
bool Ball::touchground() {
	if (ypos > 540) {
		if (xpos <= 352) {
			win = 'r';
		}
		else {
			win = 'l';
		}
		return true;
	}
	return false;
}
bool Ball::checkCollision(Player* p1, Player* p2, const Uint8* keystate)
{
    int ballX = getxpos()+50;
    int ballY = getypos()+50;
    int p1X = p1->getxpos()+60;
    int p1Y = p1->getypos()+92;
    int p2X = p2->getxpos()+60;
    int p2Y = p2->getypos()+92;

    float p1RealDistance = sqrt(pow(ballX - p1X, 2) + pow(ballY - p1Y, 2));
    float p1TouchedDistance = getradius() + 100;
    float p2RealDistance = sqrt(pow(ballX - p2X, 2) + pow(ballY - p2Y, 2));
    float p2TouchedDistance = getradius() + 100;

    //if the ball touches the player..
    if (p1RealDistance <= p1TouchedDistance)
    {
        if (ballX < p1X)
        {
            xVel = (p1X - ballX) / 9;
            xVel = -xVel;
        }
        else if (ballX > p1X)
        {
            xVel = (ballX - p1X) / 9;
        }
        yVel = -27;
        return true;
    }

    if (p2RealDistance <= p2TouchedDistance)
    {
        if (ballX < p2X)
        {
            xVel = (p2X - ballX) / 9;
            xVel = -xVel;
        }
        else if (ballX > p2X)
        {
            xVel = (ballX - p2X) / 9;
        }
        yVel = -27;
        return true;
    }
    /*
    // for spike..
    if (p1RealDistance <= p1TouchedDistance + SPIKE_RADIUS)
    {
        if ((keystate[SDL_SCANCODE_LSHIFT] && keystate[SDL_SCANCODE_RIGHT]) || p1->getSpikeState() == 1)
        {
            setFlamePos(ballX, ballY, p1X, p1Y, p2X, p2Y, 'L');
            flameOn = true;
            flameStartTime = SDL_GetTicks();
            flame->update();

            setTrailing();

            xVel = RIGHT_SPIKE_XVEL;
            yVel = SPIKE_YVEL;
            return true;
        }
        if ((keystate[SDL_SCANCODE_LSHIFT] && keystate[SDL_SCANCODE_DOWN]) || p1->getSpikeState() == 2)
        {
            setFlamePos(ballX, ballY, p1X, p1Y, p2X, p2Y, 'L');
            flameOn = true;
            flameStartTime = SDL_GetTicks();
            flame->update();

            setTrailing();

            xVel = DOWN_SPIKE_XVEL;
            yVel = DOWN_SPIKE_YVEL;
            return true;
        }
        if (keystate[SDL_SCANCODE_LSHIFT] || p1->getSpikeState() == 3)
        {
            setFlamePos(ballX, ballY, p1X, p1Y, p2X, p2Y, 'L');
            flameOn = true;
            flameStartTime = SDL_GetTicks();
            flame->update();

            setTrailing();

            xVel = BASIC_SPIKE_XVEL;
            yVel = BASIC_SPIKE_YVEL;
            return true;
        }
    }

    if (p2RealDistance <= p2TouchedDistance + SPIKE_RADIUS)
    {
        if ((keystate[SDL_SCANCODE_LSHIFT] && keystate[SDL_SCANCODE_LEFT]) || p2->getSpikeState() == 1)
        {
            SDL_Delay(100);
            setFlamePos(ballX, ballY, p1X, p1Y, p2X, p2Y, 'R');
            flameOn = true;
            flameStartTime = SDL_GetTicks();
            flame->update();

            setTrailing();

            xVel = LEFT_SPIKE_XVEL;
            yVel = SPIKE_YVEL;
            return true;
        }
        if ((keystate[SDL_SCANCODE_LSHIFT] && keystate[SDL_SCANCODE_DOWN]) || p2->getSpikeState() == 2)
        {
            setFlamePos(ballX, ballY, p1X, p1Y, p2X, p2Y, 'R');
            flameOn = true;
            flameStartTime = SDL_GetTicks();
            flame->update();

            setTrailing();

            xVel = DOWN_SPIKE_XVEL;
            yVel = DOWN_SPIKE_YVEL;
            return true;
        }
        if (keystate[SDL_SCANCODE_LSHIFT] || p2->getSpikeState() == 3)
        {
            setFlamePos(ballX, ballY, p1X, p1Y, p2X, p2Y, 'R');
            flameOn = true;
            flameStartTime = SDL_GetTicks();
            flame->update();

            setTrailing();

            xVel = BASIC_SPIKE_XVEL;
            yVel = BASIC_SPIKE_YVEL;
            return true;
        }

        return true;
    }*/

    // if the ball touches the top of the pole
    
    // if the ball touches the left side of the pole
    if (ypos +47.5 >= 235) {
        if (xpos >= 352 && xVel>0) {
            xVel = -xVel;
            return true;
        }
        if (xpos <= 413 && xVel < 0) {
            xVel = -xVel;
            return true;
        }
    }
    else if (ypos < 235 && yVel<0) {
        if (xpos >= 352 && xpos >= 413) {
            yVel = -yVel;
            return true;
        }
    }
    // if the ball touches the right side of the pole
    
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