﻿#define _CRT_SECURE_NO_WARNINGS //Игнорировать небезопастность функций 
#include<iostream>
#include<string.h> //работа с строками
#include<fstream> //работа с файлами
#include<Windows.h> //SetConsoleTitleA, sleep, +++
#include"Func.h"
#include"RatSimulator.h"
#include"Menu.h"
#include"Timer.h"
#include"CowAndBull.h"
//#include<iomanip> //setw
//#include<typeinfo>
using namespace std;
  
int main()
 {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitleA("RatSimulator"); 
	system("mode con cols=100 lines=30");
	ShowConsoleCursor(false);


	//char spaceGet = _getch();

	//int sda = spaceGet;

	//cout << sda << endl;
	//system("pause");

	RatSimulator start;
	start.menu();
	SetColor(Black, Black);
}