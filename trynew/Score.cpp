#include "Score.h"
#include<string>
using namespace std;
Score::Score(string st, int x, int y, int w, int h) {
	s = stoi(st);
	const char* texture = st.c_str();
	objTexture = TextureManager::loadFont(texture);
	srcR.x = 0;
	srcR.y = 0;
	srcR.w = w;
	srcR.h = h;
	destR.x = x;
	destR.y = y;
	destR.w = w;
	destR.h = h;
}
void Score::Update() {
	s++;
	string st;
	st = to_string(s);
	const char* texture = st.c_str();
	objTexture = TextureManager::loadFont(texture);
}
void Score::Render() {
	SDL_RenderCopy(Game::renderer, objTexture, &srcR, &destR);
}