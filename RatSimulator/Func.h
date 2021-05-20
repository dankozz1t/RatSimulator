#pragma once
#include<iostream>
#include<iomanip>
#include <vector>
#include<Windows.h>
#include<typeinfo>
#include<conio.h> //getch
#include"Music.h"
#include <map> //printRawF


using namespace std;


enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

enum KeyboardKey
{
	Up = 72, Down = 80, Right = 77, Left = 75, Enter = 13, Space = 32, Esc = 27
};

map<char, int> hexIntMap = { {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
			{'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15} };
map<int, char> intHexMap = { {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
			{10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'} };


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

//Функция посимвольно печаетает с возможностью форматирования по центру, изменениям цвета и задержкой(анимацией)
void printRaw(string raw, int x, int _y, int centerFormatting = 0, int textСolor = 7, int backgroundСolor = 0, int sleep = 0, int sizeHeight = 100)
{
	mciSend(L"open \"Resources/Klava.mp3\" type mpegvideo alias music");
	int y = 0, countChar = -1, symbolNow = 0;
	if (!(textСolor == 7 && backgroundСolor == 0)) SetColor(textСolor, backgroundСolor);

	for (int i = 0; i < raw.size(); i++)
	{
		cout << raw[i];
		if (sleep)
		{
			mciSend(L"play music repeat");
			Sleep(sleep);
		}
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
	mciSend(L"close music");
	SetColor();
}

int formattedLength(string s) {
	int size = 0;
	for (int i = 0; i < s.size(); i++) {
		bool ifFG = false, ifBG = false;

		if (s[i] == '%') {
			if (hexIntMap.count(s[i + 1])) {

				ifFG = true;
			}

			if (hexIntMap.count(s[i + 2])) {
				ifBG = true;
			}
			i += ifFG + ifBG;
			continue;
		}

		size++;
	}
	return size;
}
void printRawF(string raw, int x, int _y, bool centered = false) { //Чудо Дмитрия (%Цвет)
	if (centered) {
		vector<string> strings; // Массив отдельных строк из raw
		string currentString = ""; // Буфер для отделения
		for (int i = 0; raw[i] != '\0'; i++) {
			if (raw[i] == '\n') {
				strings.push_back(currentString); // Если начинается новая строчка, текущую записываем в массив
				currentString = "";
			}
			else currentString.push_back(raw[i]); // Если нет, продолжаем запись в буфер
		}

		for (int i = 0; i < strings.size(); i++) {
			gotoxy(x - (formattedLength(strings[i]) / 2), _y + i); // Переходим в x - полстроки, то есть выравниваем центрально
			for (int j = 0; j < strings[i].size(); j++) { // Посимвольная обработка строчки из массива, идентично fcout
				bool ifFG = false, ifBG = false;
				int fg = 7, bg = 0;
				if (strings[i][j] == '%') { // обрабатываем изменения цвета
					if (hexIntMap.count(strings[i][j + 1])) {
						fg = hexIntMap[strings[i][j + 1]];
						ifFG = true;
					}

					if (hexIntMap.count(strings[i][j + 2])) {
						bg = hexIntMap[strings[i][j + 2]];
						ifBG = true;
					}
					j += ifFG + ifBG; // Пропускаем и не печатает изменения цвета

					SetColor(fg, bg);
				}
				else cout << strings[i][j]; // Если это обычный символ, выводим
			}
			SetColor();
		}
	}
	else {
		int y = 0;
		for (int i = 0; i < raw.size(); i++) {
			bool ifFG = false, ifBG = false;
			int fg = 7, bg = 0;
			if (raw[i] == '%') {
				if (hexIntMap.count(toupper(raw[i + 1]))) {
					fg = hexIntMap[toupper(raw[i + 1])];
					ifFG = true;
				}

				if (hexIntMap.count(toupper(raw[i + 2]))) {
					bg = hexIntMap[toupper(raw[i + 2])];
					ifBG = true;
				}
				SetColor(fg, bg);
				i += ifFG + ifBG;
			}
			else {
				cout << raw[i];
				if (raw[i] == '\n') {
					y++;
					gotoxy(x, _y + y);
				}
			}
		}
		SetColor();
	}
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

			if (pos == 0 || pos == 3 || pos == 1 || pos == 4) //Если Первая или вторая ячейка
			{
				if (pos == 0 || pos == 3) xOs = 3; //Первая ячейка
				else xOs = 35; //Вторая ячейка
			}
			else xOs = 67; //Третья

			printFrame(16, 30, xOs, 3);

		}

		c = _getch();

		switch (c)
		{
		case Left:
			playMenu();
			if (pos == 0)
				pos = 2;
			else if (pos == 3)
				pos = 5;
			else
				pos--;
			break;
		case Right:
			playMenu();
			if (pos == 2)
				pos = 0;
			else if (pos == 5)
				pos = 3;
			else
				pos++;
			break;
		case Up://Если есть вторая страница, отрывать первую
			if (pos > 2)
			{
				playLeaf();
				return pos = 0;
			}
			else playError();
			break;
		case Down:
			if (printCell3) //Если существует третий прилавок, открыть вторую страницу
			{
				playLeaf();
				if (pos < 3) return pos = 3;
			}
			else playError();
			break;
		case Enter:
			playMenuYes();
			return pos;
		}
	}
	return pos;
}








