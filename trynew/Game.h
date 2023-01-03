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
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);//初始化
	void handleevents();//控制鍵盤輸入、關螢幕畫面
	void update();//更新參數
	void render();//更新畫面
	void clean();//清除
	bool running() {//判斷是否有在運行
		return isrunning;
	}
	bool startmode() {//是否進入startscreen
		return start;
	}
	void displaystartscreen();//秀出開始畫面
	bool optionmode() {//是否進入選角色頁面
		return option;
	}
	void displayoptionscreen();//秀出選角色頁面
	bool istarget() {//是否進入調整分數頁面
		return target;
	}
	bool isbackground() {//是否進入選background頁面
		return bg;
	}
	void music1();//播放背景音樂
	void music2();//播放遊戲音樂
	void displaytargetscreen();//調整分數頁面
	void displaybackground();//選background頁面
	void loadpicture();//load使用者要的圖片
	int loadTarget();//load使用者要的分數
	int loadscore1();//當前player1的分數
	int loadscore2();//當前player2的分數
	void end();//程式結束關閉視窗
	static SDL_Renderer* renderer;//畫面
private:
	bool start = true;//是否進入startscreen
	bool option = false;//是否進入選角色頁面
	bool target = false;//是否進入調整分數頁面
	//int cnt = 0;//debug看有沒有update
	int p1 = 0;//player1選角色用，預設為第一張圖
	int p2 = 0;//player2選角色用，預設為第一張圖
	bool bg = false;//是否進入選background頁面
	int whichbackground = 0;//選背景用，預設為第一張圖
	bool isrunning; //判斷是否有在運行
	SDL_Window* window;//開啟視窗用
	Mix_Music* bgm;//用來load背景音樂的指標
	Mix_Music* play_mus;//用來load遊戲時音樂的指標
	Mix_Music* winsound;//用來load勝利時音樂的指標
	SDL_Texture* objTexture1 = nullptr;//load結束字體
	SDL_Rect srcR, destR;//放字體的長方形
	//SDL_Renderer* renderer;
};
