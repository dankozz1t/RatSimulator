#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<typeinfo>
using namespace std;


enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
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

void printScreensaver() //Заставка 
{
	int t = 10;
	for (int x = 2; x != 20; x++)
	{
		{
			const int ROWS_COUNT = 6;
			string rows[ROWS_COUNT] = {
			" ___    _    _",
			"| _ \\  | |  | |",
			"||_) | | |_ | |",
			"| _ <  | _ \\| |",
			"||_) | ||_) | |",
			"|___/  |___/|_|"
			};
			for (int i = 0; i < ROWS_COUNT; i++)
			{
				gotoxy(x, 6 + i);
				cout << rows[i] << endl;

			}
			if (x != 19)
			{
				for (size_t i = 6; i < 12; i++)
				{
					gotoxy(x, i);
					cout << " ";
				}
			}
			Sleep(t);
		}
		const int ROWS_COUNT = 6;
		string rows[ROWS_COUNT] = {
		" _    _   ____    _    _   ____   _____",
		"| |  | | |  _ \\  | |  | | /  __| |  _  \\ ",
		"| |_ / | | |_) | | |_ | | | /    | |_) |  ",
		"|  _  /  |  __/  | _ \\| | | |    |  _  | ",
		"| | \\ \\  | |     ||_) | | | \\__  | | | |  ",
		"|_|  |_| |_|     |___/|_| \\____| |_| |_|  "
		};
		for (int i = 0; i < ROWS_COUNT; i++)
		{
			gotoxy(41, 6 + i);
			cout << rows[i] << endl;
		}

	}
};

void printTypes()
{
	SetColor(Magenta, Black);
	printFrame(8, 74, 13, 12);
	SetColor(LightMagenta, Black);
	const int ROWS_CONT = 6;
	string rows[ROWS_CONT] = {
	" Тип крысы: | Здоровье: | Сытость: | Покормить: | Зотоло:  | Сложность: ",
	"________________________________________________________________________",
	"   Хаски    |    200    |   200    |     5      |   10     |   ЛЕГКАЯ   ",
	"   Дамбо    |    100    |   100    |     2      |    5     | НОРМАЛЬНАЯ ",
	"   Сфинкс   |    50     |   50     |     0      |    0     |   ХАРДКОР  ",
	"  Общажная  |    999    |   999    |    999     |   999    |    ЧИТЕР   "
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(0, 12 + i + 1, size(rows[i]));
		cout << rows[i] << endl;
	}

	SetColor(Green, Black);
	gotoxy(30, 20);
	system("pause");
}

void printRules()
{
	system("cls");
	SetColor(Magenta, Black);
	printFrame(28, 98, 1, 1);
	string rows[] = {
	"Правила:",
	" ",
	" Ваша задача прожить максимальное количество времени. ",
	"Играя в мини-игры, вы можете получить разные плюшки. ",
	" ",
	"Режимы:",
	"Существует 5 режимов или же окрасов главной крысы.",
	"Разница их в максимальном запасе здоровья и сытости, так же в базовом капитале золота. ",
	" ",
	"Очки рейтинга:",
	"Получаете за мини-игры, +25 или -25. Идут в общую таблицу рекордов.",
	" ",
	" Золото:",
	"Дается при выигрыше в мине-игре. Нужно для прокачки крысы, аксессуаров",
	" ",
	"Здоровье:",
	"Отнимается при проигрыше в мини-игры, пополнять его можно купив аптечку.",
	" ",
	"Сытость:",
	"Отнимается за заход в мини-игру, можно покормить крысу 0/2/4/999 раз в зависимости от режима."
	};
	int sizeRowsArray = sizeof(rows) / sizeof(string);
	for (int i = 0; i < sizeRowsArray; i++)
	{
		switch (i) //Погуглить как сделать адекватно эту хуйню
		{
		case 0:
			SetColor(Red, Black);
			break;
		case 5:
			SetColor(LightBlue, Black);
			break;
		case 9:
			SetColor(LightCyan, Black);
			break;
		case 12:
			SetColor(Yellow, Black);
			break;
		case 15:
			SetColor(LightRed, Black);
			break;
		case 18:
			SetColor(Brown, Black);
			break;
		default:
			SetColor(White, Black);
		}

		gotoxy(-1, 1 + i + 1, size(rows[i]));
		cout << rows[i] << endl;
	}

	SetColor(Green, Black);
	gotoxy(0, 27, 44);
	system("pause");
}

void tableCowAndBulls(int x, int y)
{
	const int ROWS_CONT = 6;
	string rowsT[ROWS_CONT] = {
	"  Режимы: | N-цифр: | Попыток: | Рейтинг: | Зотоло: ",
	"____________________________________________________",
	"  Легкий  |    3    |    15    |    10    |    2    ",
	"  Обычный |    4    |    15    |    25    |    3    ",
	"  Сложный |    5    |    25    |    30    |    5    ",
	"  Хардкор |    6    |    30    |    50    |    7    "
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(x, y + i + 1, size(rowsT[i]));
		cout << rowsT[i] << endl;
	}

}




