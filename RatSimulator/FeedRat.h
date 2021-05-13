#pragma once
#include"Func.h"
//#include"Timer.h"
void printPacman()
{
	const int ROWS_CONT = 15;
	string rowsT[ROWS_CONT] = {
	"       ####      ",
	"     ##    ##     ",
	"    #        #    ",
	"   #          #   ",
	"  #     @      #  ",
	"  #          ##   ",
	" #        ###     ",
	" #       #        ",
	" #        ###     ",
	"  #          ##   ",
	"  #            #  ",
	"   #          #   ",
	"    #        #    ",
	"     ##    ##     ",
	"       ####       "

	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(3,  7+ i);
		cout << rowsT[i] << endl;
	}
}


void FeedRat(Account* account, int acc)//Добавить меню правил, анимацию еды в пот пакмана , бонусы
{
	system("cls");

	Timer t;
	int tElap = t.elapsed();
	int k = 0;

	while (tElap < 10)
	{
		system("cls");
		SetColor(tElap, Black);
		printFrame(8, 25, 37, 13);

		printPacman();


		SetColor(Red, Black);
		gotoxy(0, 15, 9);
		cout << "Время: " << tElap << endl;

		gotoxy(0, 18, 21);
		cout << "Нажатий пробелов: " << k << endl;
		int probel = _getch();

		if (probel == 32)
			k++;

		tElap = t.elapsed();
	}

	SetColor(Green, Black);
	gotoxy(30, 27);
	system("pause");
}