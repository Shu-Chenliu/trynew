#pragma once
#include"GameObject.h"
#include"Player.h"
class Ball:public GameObject{
private:
	int a=1;//�[�t��
	char win;//����Ĺ�a
	int radius;//�y�b�|
	Mix_Chunk* scoresound = NULL;
	Mix_Chunk* spikesound = NULL;
public:
	Ball(const char* texturesheet, int x, int y,int w,int h);
	~Ball();
	void Update();
	void Render();
	bool touchground();//�P�_�O�_���a
	bool checkCollision(Player* p1, Player* p2, const Uint8* keystate);//�P�_���L�I��
	int getxpos() {
		return xpos;
	}
	int getypos() {
		return ypos;
	}
	int getradius() {
		return radius;
	}
	void reset(); //���s�o�y
	char getwin(); //����Ĺ�a
};

