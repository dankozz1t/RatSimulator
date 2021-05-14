#pragma once
#include<iostream>
#include<iomanip>
#include <vector>
#include<Windows.h>
#include<typeinfo>

using namespace std;


enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};


void SetColor(int text = 7, int background = 0)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(int x, int y, int sizeLen = 0, int sizeHeight = 100) //При наличии размера строки выполняется форматирование по центру
{
	if (sizeLen)
		x = (x + sizeHeight - sizeLen) / 2;

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowConsoleCursor(bool showFlag) // false - Убийца курсора
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void printFrame(int height = 25, int width = 80, int posX = 10, int posY = 5) //Рисовка рамки по заданным размерам и позиции
{
	for (int y = 0; y < height; y++)
	{
		int t = 0;
		gotoxy(posX, posY);
		for (int x = 0; x < width; x++)
		{
			gotoxy(posX, posY);
			bool angle = (x == 0 && y == 0) || (x == 0 && y == height - 1) || (y == 0 && x == width - 1) || (y == height - 1 && x == width - 1);
			if (angle)
				cout << "#";
			else if (y == 0 || y == height - 1)
				cout << "-";
			else if (x == 0 || x == width - 1)
				cout << "|";
			else
				cout << " ";

			posX++; t++;
		}
		posX -= t;
		cout << endl;
		posY++;
	}
}

template<class T>
void addElem(T*& a, int& n, T elem, int pos = -1) {//добавление элемета указаную ячейку в массива. //Ссылка
	if (pos == -1)
		pos = n;
	if (n < pos)
		return;
	T* temp = new T[n + 1];
	for (size_t i = 0; i < pos; i++) {
		temp[i] = a[i];
	}
	temp[pos] = elem;
	for (size_t i = pos; i < n; i++)
	{
		temp[i + 1] = a[i];
	}
	/*delete[]a;*/  //Возникают баги в Быках и корова (Предыдущее число) 
	n++;
	a = temp;

}

int findMaxString(vector<string> a) { // Возвращает длину самой длинной строчки в массиве
	int max = a[0].length();
	for (int i = 1; i < a.size(); i++) {
		if (a[i].length() > max) max = a[i].length();
	}
	return max;
}

void printRaw(string raw, int x, int _y, int fg = 7, int bg = 0) { // Посимвольно копирует 
	int y = 0;
	if (!(fg == 7 && bg == 0)) SetColor(fg, bg);
	for (int i = 0; i < raw.size(); i++) {
		cout << raw[i];
		if (raw[i] == '\n') {
			y++;
			gotoxy(x, _y + y);
		}
	}
	SetColor();
}

void printByLetter(char str[])
{
	for (size_t i = 0; i < strlen(str); i++)
	{
		cout << str[i];
		Sleep(50);
	}
}






