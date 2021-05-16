#pragma once
#include<iostream>
#include<iomanip>
#include <vector>
#include<Windows.h>
#include<typeinfo>
#include<conio.h> //getch

using namespace std;


enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

enum KeyboardKey
{
	Up = 72, Down = 80, Right = 77, Left = 75, Enter = 13, Space = 32
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


void printFrame(int height = 25, int width = 80, int posX = 10, int posY = 5) //Рисовка рамки по заданым параметрам
{
	for (int y = posY; y < posY + height; y++)
	{
		for (int x = posX; x < posX + width; x++)
		{
			gotoxy(x, y);
			bool angle = (x == posX && y == posY) || (x == posX && y == posY + height - 1) || 
				(y == posY && x == posX + width - 1) || (y == posY + height - 1 && x == posX + width - 1);
			if (angle)
				cout << "#";
			else if (y == posY || y == posY + height - 1)
				cout << "-";
			else if (x == posX || x == posX + width - 1)
				cout << "|";
		}
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

//Функция посимвольно печаетает с возможностью форматирования по центру, изменениям цвета и задержкой(анимацией)
void printRaw(string raw, int x, int _y, int centerFormatting = 0, int textСolor = 7, int backgroundСolor = 0, int sleep = 0, int sizeHeight = 100)
{
	int y = 0, countChar = -1, symbolNow = 0;
	if (!(textСolor == 7 && backgroundСolor == 0)) SetColor(textСolor, backgroundСolor);

	for (int i = 0; i < raw.size(); i++) {

		cout << raw[i];
		if (sleep)
			Sleep(sleep);
		if (raw[i] == '\n') {
			if (centerFormatting)
			{
				while (symbolNow < raw.size())
				{
					countChar++;
					symbolNow++;
					if (raw[symbolNow] == '\n')
					{
						centerFormatting = countChar;
						countChar = -1;
						break;
					}
				}
			}
			y++;
			gotoxy(x, _y + y, centerFormatting, sizeHeight);
			countChar++;
		}
	}
	SetColor();
}

int menuShop(int (*printCell)(), int (*printCell2)() = NULL, int (*printCell3)() = NULL, int pos = 0, int textСolor = LightCyan, int textСolorNOW = Blue)
{
	SetColor(textСolor, Black);
	printFrame(16, 30, 3, 3);
	printFrame(16, 30, 35, 3);
	printFrame(16, 30, 67, 3);
	printCell();
	if (printCell2) printCell2();
	if (printCell3) printCell3();
	char c = 0;

	int xOs = 3;
	while (c != Enter) {
		for (int i = 0; i < 2; i++)
		{
			SetColor(textСolor, Black);

			printFrame(16, 30, xOs, 3);

			SetColor(textСolorNOW, Black);
			     //Если первая ячейка      //Если вторая 
			//xOs = (pos == 0 || pos == 3 || pos == 1 || pos == 4) ? ((pos == 0 || pos == 3) ? 3 : 35) : 67; //Тернарные имба

			if (pos == 0 || pos == 3 || pos == 1 || pos == 4) {
				if (pos == 0 || pos == 3) xOs = 3;
				else xOs = 35;
			}
			else xOs = 67;

			printFrame(16, 30, xOs, 3);

		}

		c = _getch();

		switch (c)
		{
		case Left:
			if (pos == 0)
				pos = 2;
			else if (pos == 3)
				pos = 5;
			else
				pos--;
			break;
		case Right:
			if (pos == 2)
				pos = 0;
			else if (pos == 5)
				pos = 3;
			else
				pos++;
			break;
		case Up:
			if (pos > 2) return pos = 0;
			break;
		case Down:
			if (pos < 3) return pos = 3;
			break;
		case Enter:
			return pos;

		}
	}
	return pos;
}







