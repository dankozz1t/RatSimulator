#pragma once
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>

#include<stdlib.h>
#include <filesystem>
#include"Func.h"


using namespace std;
using std::filesystem::current_path;
const wstring dir = current_path().wstring();


void playBiteSound() {

	wstring _dir = dir;
	_dir.append(L"\\Resources\\bite.wav");
	PlaySound(_dir.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}