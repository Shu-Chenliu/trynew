#pragma once
#include"SDL.h"
#include"SDL_image.h"
#include "SDL_mixer.h"
#include<iostream>
using namespace std;
class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);//��l��
	void handleevents();//������L��J�B���ù��e��
	void update();//��s�Ѽ�
	void render();//��s�e��
	void clean();//�M��
	bool running() {//�P�_�O�_���b�B��
		return isrunning;
	}
	bool startmode() {//�O�_�i�Jstartscreen
		return start;
	}
	void displaystartscreen();//�q�X�}�l�e��
	bool optionmode() {//�O�_�i�J�﨤�⭶��
		return option;
	}
	void displayoptionscreen();//�q�X�﨤�⭶��
	bool istarget() {//�O�_�i�J�վ���ƭ���
		return target;
	}
	bool isbackground() {//�O�_�i�J��background����
		return bg;
	}
	void music1();//����I������
	void music2();//����C������
	void displaytargetscreen();//�վ���ƭ���
	void displaybackground();//��background����
	void loadpicture();//load�ϥΪ̭n���Ϥ�
	int loadTarget();//load�ϥΪ̭n������
	int loadscore1();//��eplayer1������
	int loadscore2();//��eplayer2������
	void end();//�{��������������
	static SDL_Renderer* renderer;//�e��
private:
	bool start = true;//�O�_�i�Jstartscreen
	bool option = false;//�O�_�i�J�﨤�⭶��
	bool target = false;//�O�_�i�J�վ���ƭ���
	//int cnt = 0;//debug�ݦ��S��update
	int p1 = 0;//player1�﨤��ΡA�w�]���Ĥ@�i��
	int p2 = 0;//player2�﨤��ΡA�w�]���Ĥ@�i��
	bool bg = false;//�O�_�i�J��background����
	int whichbackground = 0;//��I���ΡA�w�]���Ĥ@�i��
	bool isrunning; //�P�_�O�_���b�B��
	SDL_Window* window;//�}�ҵ�����
	Mix_Music* bgm;//�Ψ�load�I�����֪�����
	Mix_Music* play_mus;//�Ψ�load�C���ɭ��֪�����
	Mix_Music* winsound;//�Ψ�load�ӧQ�ɭ��֪�����
	SDL_Texture* objTexture1 = nullptr;//load�����r��
	SDL_Rect srcR, destR;//��r�骺�����
	//SDL_Renderer* renderer;
};
