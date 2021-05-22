#pragma once
#include<iostream>
#include "Func.h"
#include"Struct.h"
#include"Graphic.h"
#include<fstream>
#include"Menu.h"
#include"Timer.h"
#include"FeedRat.h"
#include"Shop.h"
#include"Music.h"
#include"CowAndBull.h"
#include"RatСasino.h"

struct RatSimulator
{
	Account* account = nullptr;
	int sizeAcc = 0;

	void save()
	{
		ofstream out("Save\\sizeRat.txt"); //имена и количесво аккаунтов
		out << sizeAcc << endl;
		for (size_t i = 0; i < sizeAcc; i++)
		{
			out << account[i].rat.name << endl;
		}
		out.close();

		for (size_t i = 0; i < sizeAcc; i++)
		{
			char* buff = new char[23]{"Save\\"};  //Каждый аккаунт в отдельный файл
			strcat(buff, account[i].rat.name);
			strcat(buff, ".txt");

			ofstream out(buff);
																							//Крыса		
			out << account[i].rat.name << endl; 
			out << account[i].rat.mode << endl;
			out << account[i].rat.rating << endl;
			out << account[i].rat.satiety << endl;
			out << account[i].rat.gold << endl;
			out << account[i].rat.health << endl;
																							//Магазин
			out << account[i].shop.bow << " " << account[i].shop.colorBow << endl;				
			out << account[i].shop.headphones << " " << account[i].shop.colorHeadphones << endl;
			out << account[i].shop.glasses << " " << account[i].shop.colorGlasses << endl;
			out << account[i].shop.collar << " " << account[i].shop.colorCollar << endl;
			out << account[i].shop.armchair << " " << account[i].shop.colorArmchair << endl;
			out << account[i].shop.lamp << " " << account[i].shop.colorLamp << endl;
																							//Аккаунт 
			out << account[i].time << endl;
			out << account[i].FeedingAttempts << endl;

			out.close();
		}
	}

	void load()
	{
		ifstream in("Save\\sizeRat.txt");
		Account acc;
		in >> sizeAcc;
		account = new Account[sizeAcc];
		in.ignore();
		for (size_t i = 0; i < sizeAcc; i++)
		{
			in.getline(account[i].rat.name, 11);
		}

		for (size_t i = 0; i < sizeAcc; i++)
		{
			char* buff = new char[23]{ "Save\\" };  //Каждый аккаунт в отдельный файл
			strcat(buff, account[i].rat.name);
			strcat(buff, ".txt");

			ifstream in(buff);
			//Крыса		
			in.getline(account[i].rat.name,11);
			in >> account[i].rat.mode;
			in >> account[i].rat.rating;
			in >> account[i].rat.satiety;
			in >> account[i].rat.gold; 
			in >> account[i].rat.health;	
			
			
			//Магазин
			in >> account[i].shop.bow  >> account[i].shop.colorBow;
			in >> account[i].shop.headphones >> account[i].shop.colorHeadphones;
			in >> account[i].shop.glasses  >> account[i].shop.colorGlasses;
			in >> account[i].shop.collar >> account[i].shop.colorCollar;
			in >> account[i].shop.armchair >> account[i].shop.colorArmchair;
			in >> account[i].shop.lamp >> account[i].shop.colorLamp;
			 
			//Аккаунт 
			in >> account[i].time;
			in >> account[i].FeedingAttempts;
		}
	}




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

			printTypes();

			gotoxy(36, 15);
			SetColor(Green, Black);
			cout << "Выберите ваш тип крысы:" << endl;
			Menu breed;
			vector<string> menuBreed = { "        Хаски", "        Дамбо" , "        Сфинкс", "       Общажная" };

			num = breed.select_vertical(menuBreed, 36, 19) + 1;
			switch (num)
			{
			case 1:
				acc.rat.satiety = 200;
				acc.rat.gold = 10;
				acc.rat.health = 200;
				acc.FeedingAttempts = 5;

				break;
			case 2:
				acc.rat.satiety = 100;
				acc.rat.gold = 5;
				acc.rat.health = 100;
				acc.FeedingAttempts = 2;
				break;
			case 3:
				acc.rat.satiety = 50;
				acc.rat.gold = 0;
				acc.rat.health = 50;
				acc.FeedingAttempts = 0;
				break;
			case 4:
				acc.rat.satiety = 999;
				acc.rat.gold = 999;
				acc.rat.health = 999;
				acc.FeedingAttempts = 999;
				break;
			case 5:
				return;
			}
			acc.rat.rating = 0;
			acc.rat.mode = num;

		} while (num == 5);
		addElem(account, sizeAcc, acc);
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
					int modeSize = 0;
					if (bullsAndCows(modeSize)) //Если победа + бонусы
					{
						playCoins();
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
						else if (modeSize == 4)
							account[acc].rat.rating -= 25;
						else if (modeSize == 5)
							account[acc].rat.rating -= 30;
						else
							account[acc].rat.rating -= 50;

						account[acc].rat.health -= 10;
						account[acc].rat.satiety -= 10;
						ShowConsoleCursor(false);
					}
				}
				break;
			case 2:
				if (rulesRatCasino() == 1)
				{
					system("cls"); SetColor(Red, Black);
					int goldRate = 0;
					gotoxy(0, 13, 24);
					cout << "Введите вашу ставку: "; SetColor(Brown, Black); cin >> goldRate; SetColor(Red, Black);

					if (account[acc].rat.gold >= goldRate) //Есть ли средства
					{
						if (RatCasino(goldRate)) //Если проигрыш
							account[acc].rat.gold -= goldRate;
						else
						{
							playCoins();
							account[acc].rat.gold += goldRate;
						}
					}
					else
					{
						gotoxy(0, 16, 24);
						cout << "У вас всего "; SetColor(Brown, Black); cout << account[acc].rat.gold; SetColor(Red, Black); cout << " золота!";

						gotoxy(30, 28); system("pause");
					}
				}
				break;
			case 3:
				system("cls");
				SetColor(Red, Black);
				gotoxy(0, 15, 11);
				cout << "В процессе" << endl;
				SetColor(Green, Black);
				gotoxy(30, 27);
				system("pause");
				break;
			case 4:
				system("cls");
				SetColor(Red, Black);
				gotoxy(0, 15, 11);
				cout << "В процессе" << endl;
				SetColor(Green, Black);
				gotoxy(30, 27);
				system("pause");
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

	void expirationRat(Account* account, int acc) //Проверочки!
	{

		if (!account[acc].rat.health == 0)						//Если крыса мертва
			printRAT(account, acc);
		else
			printRAT(account, acc, 'X');

		if (account[acc].shop.bow)								//Если бантик есть
			printBow(85, 19, account[acc].shop.colorBow);

		if (account[acc].rat.satiety == 0)						//Если голодная
			playImHungry();

		if (account[acc].shop.headphones)						//Если есть наушники 
			printHeadphones(81, 17, account[acc].shop.colorHeadphones);

		if (account[acc].shop.glasses)							 //Если есть очки
		{
			if ((!account[acc].rat.health == 0))
				printGlasses(84, 21, account[acc].shop.colorGlasses);
			else
				printGlasses(84, 21, account[acc].shop.colorGlasses, 'X');
		}

		if (account[acc].shop.collar)						  //Если есть ошейник
			printCollar(85, 26, account[acc].shop.colorCollar);

		if (account[acc].shop.armchair)						 //Если есть диван
			printArmchair(9, 12, account[acc].shop.colorArmchair);


		if (account[acc].shop.lamp)							//Если есть торшер
			printLamp(59, 10, account[acc].shop.colorLamp);
	}

	void menuPlayer(int acc)
	{
		Timer time;
		time.reset();
		time.elapsed();

		do {
			system("cls");
			SetColor(Magenta, Black);
			printFrame(25, 88, 6, 1);

			expirationRat(account, acc);

			printCharacteristics(account, acc);

			Menu mP;
			vector<string> mPlayer = { "     Мини-игры", "   Покормить крысу", "      Магазин", "     Сохранение", "       Выход" };

			int num = mP.select_vertical(mPlayer, 39, 18) + 1;
			switch (num)
			{
			case 1:
				miniGames(acc);
				break;
			case 2:
				feedRat(account, acc);
				break;
			case 3:
				shop(account, acc);
				break;
			case 4:
				save();
				playPositiveSound();
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

	int AccSelection()
	{
		system("cls"); gotoxy(0, 11, 37); SetColor(Red, Black);
		cout << "C возращением, выберите ваш аккаунт:" << endl;

		Menu c;
		vector<string> listCurrency;
		for (size_t i = 0; i < sizeAcc; i++)
		{
			char buff[22]{ " " };
			for (size_t j = 0; j < (21 - strlen(account[i].rat.name)) / 2; j++) //Форматирование в меню
			{
				strcat(buff, " ");
			}
			strcat(buff, account[i].rat.name);

			listCurrency.push_back(buff);
		}
		return c.select_vertical(listCurrency, 39, 16);
	}
	void menu()
	{
		load();

		do {
			system("cls");
			SetColor(Green, Black);
			printScreensaver();

			Menu m;
			vector<string> mainMenu = { "      Новая игра", "     Я уже играл", "       Рекорды", "       Правила" ,"      Об авторе" , "        Выход" };

			int num = m.select_vertical(mainMenu, 39, 18) + 1;
			switch (num)
			{
			case 1:
				newPlay();
				menuPlayer(sizeAcc-1);
				break;
			case 2:
				if (sizeAcc)
					menuPlayer(AccSelection());
				else
				{
					system("cls"); gotoxy(0, 15, 41); SetColor(Red, Black);
					cout << "Крыс не существует! Может быть вы хомяк?" << endl;
					playGetOut();
					gotoxy(30, 28); system("pause");
				}
				break;
			case 3:
				statistics(account, sizeAcc);
				break;
			case 4:
				printRules();
				break;
			case 5:
				creator();
				break;
			case 6:
				save();
				return;
			default:
				break;
			}
		} while (true);

	}
};
