#pragma once
#include<iostream>
#include "Func.h"
#include<fstream>
#include"Menu.h"
#include"Timer.h"
#include"CowAndBull.h"

struct Date
{
	int d, m, y;

	void print()
	{
		if (d < 10)
			cout << 0;
		cout << d << ".";
		if (m < 10)
			cout << 0;
		cout << m << "." << y;
	}
};

struct Rat
{
	char name[10];
	int mode = 1; 
	int rating = 0;
	int satiety = 0;
	int gold = 0;
	int health = 100;
};

struct Account
{
	Rat rat;
	Date date;
	int time = 0;
	int countFeed = 0;
};


struct RatSimulator
{
	Account* account = nullptr;
	int sizeAcc = 0;

	void newPlay()
	{
		system("cls");
		ShowConsoleCursor(true);
		gotoxy(36, 10);
		SetColor(Green, Black);
		cout << "Введите ваше имя: ";
		Account acc;
		cin >> acc.rat.name;
		ShowConsoleCursor(false);
		int num = 0;
		do {
			system("cls");
			gotoxy(36, 10);
			SetColor(Green, Black);
			cout << "Выберите ваш тип крысы:" << endl;
			Menu breed;
			vector<string> menuBreed = { "        Хаски", "        Дамбо" , "        Сфинкс", "       Общажная", "       О типах" };

			num = breed.select_vertical(menuBreed, 36, 14) + 1;
			switch (num)
			{
			case 1:
				acc.rat.satiety = 200;
				acc.rat.gold = 10;
				acc.rat.health = 200;
				acc.countFeed = 5;

				break;
			case 2:
				acc.rat.satiety = 100;
				acc.rat.gold = 5;
				acc.rat.health = 100;
				acc.countFeed = 2;
				break;
			case 3:
				acc.rat.satiety = 50;
				acc.rat.gold = 0;
				acc.rat.health = 50;
				acc.countFeed = 0;
				break;
			case 4:
				acc.rat.satiety = 999;
				acc.rat.gold = 999;
				acc.rat.health = 999;
				acc.countFeed = 999;
				break;
			case 5:
				printTypes();
				break;
			default:
				break;
			}
			acc.rat.rating = 0;
			acc.rat.mode = num;

		} while (num == 5);
		addElem(account, sizeAcc, acc);
	}
	
	void printRAT(char eyes = 'O')  //Состояние Крысы
	{
		//^^ OO XX 
		switch (account[sizeAcc - 1].rat.mode)
		{
		case 1:
			SetColor(White, Black);
			break;
		case 2:
			SetColor(DarkGray, Black);
			break;
		case 3:
			SetColor(LightRed, Black);
			break;
		case 4:
			SetColor(Brown, Black);
			break;
		};
		gotoxy(83, 18);
		cout << " ___      ___  ";
		gotoxy(83, 19);
		cout << "/   \\    /   \\ ";
		gotoxy(83, 20);
		cout << "|    \\__/    | ";
		gotoxy(83, 21);
		cout << "|            | ";
		gotoxy(83, 22);
		cout << "\\__        __/ ";
		gotoxy(83, 23);
		cout << "  / " << eyes << "   " << eyes << " |  ";
		gotoxy(83, 24);
		cout << "@         |  ";
		gotoxy(83, 25);
		if (eyes == 'X')
			cout << " \\___     |  ";
		else
			cout << " \\___/    |  ";
		gotoxy(83, 26);
		cout << " |        |  ";

	}
	int rulesBullAndCows()
	{
		string rows[] = {
		"Быки и коровы:",
		" ",
		"Это логическая игра, в ходе которой за N-количество попыток",
		"Вы должны отгадать загаданное число",
		"Числа генерируются от 0 до 9 без повторов",
		"Количесво цифр и попыток зависит от выбраного режима",
		"После кажой попытки вам дается \"оценка\" - быки и коровы ",
		"Коровы - это количесво угаданных цифр на своих местах",
		"Быки -  это количесвто угаданных цифр",
		"За победу вам дается рейтинг и золото",
		"За поражение у вас отнимается рейтинг и здоровье и сытость"

		};
		int sizeRowsArray = sizeof(rows) / sizeof(string);
		for (int i = 0; i < sizeRowsArray; i++)
		{
			if (i == 0)
				SetColor(Red, Black);
			else
				SetColor(White, Black);
			gotoxy(26, 2 + i, size(rows[i]), 100);
			cout << rows[i] << endl;
		}

		SetColor(Red, Black);
		gotoxy(35,14);
		cout << "Стоимость 1 игры состоявлеят 10 здоровья и 10 сытости";

		SetColor(Cyan, Black);
		printFrame(8, 54, 35, 16);

		SetColor(LightCyan, Black);
		tableCowAndBulls(25, 16);




		int option = 0;
		Menu m;
		vector<string> mainMenu = { "        Играть", "        Назад" };
		return option = m.select_vertical(mainMenu, 50, 26) + 1;
	}

	void miniGames(int acc)
	{
		do {
			system("cls");
			SetColor(Magenta, Black);
			printFrame(28, 98, 1, 1);
			for (size_t i = 2; i < 28; i++)
			{
				gotoxy(26, i);
				cout << "|";
			}

			Menu mP;
			vector<string> mPlayer = { "    Быки и коровы", "   Крысиное казино", "    Угадай факты", "   Крестики-нолики", "       Выход" };

			int num = mP.select_vertical(mPlayer, 3, 5) + 1;

			switch (num)
			{
			case 1:
				if (rulesBullAndCows() == 1)
				{
					if (account[acc].rat.health >= 10 && account[acc].rat.satiety >= 10) //Блок самоубийц
					{
						int modeSize = 0;
						if (bullsAndCows(modeSize)) //Бонусы за исход игры
						{
							switch (modeSize)
							{
							case 3:
								account[acc].rat.gold += 2;
								account[acc].rat.rating += 10;
								break;
							case 4:
								account[acc].rat.gold += 3;
								account[acc].rat.rating += 25;
								break;
							case 5:
								account[acc].rat.gold += 5;
								account[acc].rat.rating += 30;
								break;
							case 6:
								account[acc].rat.gold += 7;
								account[acc].rat.rating += 50;
								break;
							default:
								break;
							}
						}
						else
						{
							if (modeSize == 3)
								account[acc].rat.rating -= 10;
							else if (modeSize = 4)
								account[acc].rat.rating -= 25;
							else if (modeSize = 5)
								account[acc].rat.rating -= 30;
							else
								account[acc].rat.rating -= 50;

							account[acc].rat.health -= 10;
							account[acc].rat.satiety -= 10;
						}
					}
					else
					{
						gotoxy(26, 15,23,100);
						SetColor(Red, Black);
						cout << "Самоубийц не пускаем!!" << endl;
						SetColor(Magenta, Black);
						gotoxy(25, 28,44,100);
						system("pause");
					}
				}

				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				return;
			default:
				break;
			}

		} while (true);

		gotoxy(30, 28);
		system("pause");
	}

	void menuPlayer(int acc = -1)
	{
		if (acc == -1)
			acc = (sizeAcc - 1);

		Timer time;
		time.reset();
		time.elapsed();

		do {
			system("cls");
			SetColor(Magenta, Black);
			printFrame(25, 88, 6, 1);
			printRAT();

			Menu mP;
			vector<string> mPlayer = { "     Мини-игры", "   Покормить крысу", "      Магазин", "     Сохранение", "       Выход" };

			int num = mP.select_vertical(mPlayer, 39, 18) + 1;
			switch (num)
			{
			case 1:
				miniGames(acc);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				account[acc].time += time.elapsed();
				return;
			default:
				break;
			}

		} while (true);

		gotoxy(30, 28);
		system("pause");
	}
	void printAcc()
	{
		setlocale(0, "");
		system("cls");
		for (size_t i = 0; i < sizeAcc; i++)
		{
			cout << "----------Акк № " << i << endl;
			cout << "ИМЯ  " << account[i].rat.name << endl;
			cout << "Мод  " << account[i].rat.mode << endl;
			cout << "рейтинг  " << account[i].rat.rating << endl;
			cout << "сытость  " << account[i].rat.satiety << endl;
			cout << "голда  " << account[i].rat.gold << endl;
			cout << "здоровье  " << account[i].rat.health << endl;
			cout << "Время  " << account[i].time << endl;
		}
		gotoxy(30, 28);
		system("pause");
	}

	int AccSelection()
	{
		cout << "C возращением, выберите ваш аккаунт: " << endl;
		Menu c;
		vector<string> listCurrency;
		for (size_t i = 0; i < sizeAcc; i++)
		{
			listCurrency.push_back(account[i].rat.name);
		}
		return c.select_vertical(listCurrency, 1, 4);
	}
	void menu()
	{
		do {
			system("cls");
			SetColor(Magenta, Black);
			printFrame(28, 98, 1, 1);
			SetColor(Green, Black);
			printScreensaver(); //Заставка


			Menu m;
			vector<string> mainMenu = { "      Новая игра", "     Я уже играл", "       Рекорды", "       Правила" ,"      Об авторе" , "        Выход" };

			int num = m.select_vertical(mainMenu, 39, 18) + 1;
			switch (num)
			{
			case 1:
				newPlay();
				menuPlayer();
				break;
			case 2:
				/*	test();*/
				if (sizeAcc)
					menuPlayer(AccSelection());
				else
					cout << "Аккаунты не найдено" << endl;
				system("pause");
				break;
			case 3:
				printAcc();
				break;
			case 4:
				printRules();
				break;
			case 5:
				break;
			case 6:
				return;
			default:
				break;
			}
		} while (true);

	}
};
