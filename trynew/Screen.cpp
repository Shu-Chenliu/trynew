#include"Screen.h"
using namespace std;
const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 640;
const int ARROW_WIDTH = 30;
const int ARROW_HEIGHT = 30;

Screen::Screen(SDL_Renderer* _renderer)
{
    cout << "(rendered)Screen constructor()!" << endl;

    renderer = _renderer;
    screen = new GameObject("assets/startbg.jpg", 0, 0, 800, 640);
    arrow = new GameObject("assets/arrow.png", 0, 0, 517, 483,0.1,0.1);
}

Screen::Screen()
{
    cout << "(default)Screen constructor()!" << std::endl;
}

Screen::~Screen()
{
    cout << "Screen deconstrouctor()" << std::endl;
    delete screen;
    delete arrow;
}