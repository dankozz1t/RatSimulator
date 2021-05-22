#pragma once
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>
#include<stdlib.h>
#include <filesystem>
#include"Func.h"

using namespace std;
using std::filesystem::current_path;
const wstring dir = current_path().wstring();

void mciSend(wstring ws) // Сокращение //mciSendStringW(L"open \"Resources/DeloDone.mp3\" type mpegvideo alias music", NULL, 0, 0);
{
	mciSendStringW(ws.c_str(), NULL, 0, 0);
}

void playBiteSound() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\bite.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
} 

void playPoliceSiren() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\policeSiren.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playCoins() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\dota2Coins.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playLetMeDay() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\LetMeDay.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}


void playError() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\error.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playMenu() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\menu.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playMenuYes() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\menuYes.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playButtonClickSound() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\menuButtonClick.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playButtonSwitchSound() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\menuButtonSwitch.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}


void playNegativeSound() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\negative.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playPositiveSound() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\positive.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playWelcomeShop() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\Welcome.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playGameOver() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\gameOver.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playWin() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\Win.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playImHungry() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\ImHungry.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playLeaf() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\leaf.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playPurchase() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\Purchase.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}


void playGetOut() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\GetOut.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playCasino() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\casino.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}