﻿#pragma once

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


void playRozbiinik() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\Rozbiinik.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

void playLetMeDay() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\LetMeDay.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}


void playNope() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\nope.wav");
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
