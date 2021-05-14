#pragma once
#include"Func.h"


void printPacman()
{
	const int ROWS_CONT = 16;
	string rowsT[ROWS_CONT] = {
	"       #######   ",
	"     ##       ##     ",
	"    #           #    ",
	"   #             #   ",
	"  #       @       #",
	"  #             ## ",
	" #           ### ",
	" #          # ",
	" #          # ",
	" #           ### ",
	"  #             ## ",
	"  #               #",
	"   #             #   ",
	"    #           #    ",
	"     ##       ##     ",
	"       #######       "

	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(0, 4 + i);
		cout << rowsT[i] << endl;
	}
}

void printFood(int x)
{
	const int ROWS_CONT = 7;
	string rowsT[ROWS_CONT] = {
	"      ",
	"   #####       #####       #####       #####       #####       #####       #####   ",
	"  #     #     #     #     #     #     #     #     #     #     #     #     #     #    ",
	" #       #   #       #   #       #   #       #   #       #   #       #   #       # ",
	"  #     #     #     #     #     #     #     #     #     #     #     #     #     #  ",
	"   #####       #####       #####       #####       #####       #####       ##### ",
	"     "
	};

	for (int i = 0; i < ROWS_CONT; i++)
	{
		
		gotoxy(100-x, 8 + i);
		cout << rowsT[i] << endl;
		
	}
}

int RulesToFeed(Account* account, int acc)
{

	const int ROWS_CONT = 12;
	string rows[ROWS_CONT] = {
	"Проголодались?? Тогда вам сюда!",
	" ",
	"Вы попали в режим пополнения сытости",
	"Сейчас вы больше хомяк, нежели крыса",
	"Ваша задача сьесть максимальное количество еды",
	"У вас есть всего лишь 10 секунд что бы набить пузо",
	"Каждый нажатый ПРОБЕЛ равняется одной сытости",
	" ",
	"Вам нужно нажимать пробел пока не закончится время",
	"",
	"При попытке жульничать вас остановит крысиный патруль",
	"Будьте честны, ведь он заберет всё ваше золото и обнулит рейтинг!"
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		if (i == 0 || i == 8)
			SetColor(Red, Black);
		else
			SetColor();
		gotoxy(0, 4 + i + 1, size(rows[i]));
		cout << rows[i] << endl;
	}


	SetColor(Red, Black);
	gotoxy(0, 19, 27);
	cout << "Попыток покормить крысу: " << account[acc].rat.FeedingAttempts << endl;

	int option = 0;
	Menu m;
	vector<string> mainMenu = { "      Покормить", "        Назад" };
	return option = m.select_vertical(mainMenu, 38, 23) + 1;
}

void FeedRat(Account* account, int acc)//Добавить меню правил, анимацию еды в пот пакмана , бонусы
{
	system("cls");

	if (account[acc].rat.FeedingAttempts > 0)
	{

		if (RulesToFeed(account, acc) == 1)
		{

			Timer t;
			int timeNow = t.elapsed();
			int spaceCount = 0;
			int spaceGet = 0;
			int x;
			while (timeNow < 10)
			{
				system("cls");
				SetColor(timeNow, Black);

	
				printFood(spaceCount);
				printPacman();


				SetColor(Red, Black);
				gotoxy(0, 18, 18);
				cout << "Прошло: " << timeNow << " секунд" << endl;
				gotoxy(0, 20, 15);
				cout << "Хапнул еды: " << spaceCount << endl;

				spaceGet = _getch();
				Sleep(50);

				if (spaceGet == 32)
					spaceCount++;

				timeNow = t.elapsed();
			}

			system("cls");
			SetColor(Red, Black);
			gotoxy(0, 15, 17);
			cout << "Прошло 10 секунд" << endl;

			if (spaceCount < 80)
			{
				Sleep(3000);
				system("cls");


				gotoxy(0, 15, 17);
				cout << "Вы сьели " << spaceCount << " еды";

				gotoxy(0, 16, size(account[acc].rat.name) + 17);
				cout << "Ну что, " << account[acc].rat.name << ", наелся?";
				account[acc].rat.FeedingAttempts--;
				account[acc].rat.satiety += spaceCount;
			}
			else //ну давай-давай, нападай
			{
				Sleep(3000);
				system("cls");

				printPolic();
				SetColor();

				char str[]{ "- Так-так, что тут у нас? СКОЛЬКО еды??" };
				gotoxy(0, 11, 14);
				printByLetter(str);

				char str1[]{ "- На вид такая приличная крыса!, а на деле ВОРОВКА!!!" };
				gotoxy(0, 12, 14);
				printByLetter(str1);

				char str2[]{ "- ВЗЯТЬ ЕЁ!" };
				gotoxy(0, 13, 14);
				printByLetter(str2);


				SetColor(Green, Black);
				gotoxy(30, 27);
				system("pause");

				system("cls");

				SetColor(Red, Black);
				gotoxy(30, 27);
				char str4[]{ "Вы долго пытались оправдаться, но все улики против вас" };
				gotoxy(0, 14, 55);
				printByLetter(str4);


				SetColor(LightRed, Black);
				char str5[]{ "- вы потратили всё золото что бы откупиться" };
				gotoxy(0, 15, 44);
				printByLetter(str5);


				char str6[]{ "- вы потеряли всю репутацию(рейтинг)" };
				gotoxy(0, 16, 37);
				printByLetter(str6);
				account[acc].rat.gold = 0;
				if (account[acc].rat.rating > 0)
					account[acc].rat.rating = 0;

			}

			SetColor(Green, Black);
			gotoxy(30, 27);
			system("pause");
		}
		else
			return;
	}
	else
	{
		system("cls");
		SetColor(Red, Black);
		gotoxy(0, 15, 43);
		cout << "У вас не осталось попыток покормить крысу!" << endl;

		SetColor(Green, Black);
		gotoxy(30, 27);
		system("pause");
	}
}