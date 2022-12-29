#include "Score.h"
#include<string>
using namespace std;
Score::Score(string st, int x, int y, int w, int h,const char* color) {
	s = stoi(st);
	const char* texture = st.c_str();
	objTexture = TextureManager::loadFont(texture,color);
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = w;
	srcR.h = h;
	destR.x = x;
	destR.y = y;
	destR.w = w;
	destR.h = h;
	c = color;
}
void Score::Update() {
	s++;
	string st;
	st = to_string(s);
	const char* texture = st.c_str();
	objTexture = TextureManager::loadFont(texture,c);
}
void Score::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}