#pragma once


void careRat(Account* account, int acc)
{
	system("cls");

	gotoxy(0, 1,14); SetColor(Cyan, Black);
	cout << "ЗАБОТА О СЕБЕ";

	gotoxy(80, 26); SetColor(Yellow, Black);
	cout << "Мое золото: " << account[acc].rat.gold << endl;

	int item = menuShop(&firstAidKit); //Запуск
	while (item != 0) //Пустые прилавки
	{
		gotoxy(0, 23, 34);
		SetColor(Red, Black);
		cout << "Прилавок пустой!! Ты что слепая??" << endl;
		system("pause>nul");
		system("cls");
		gotoxy(80, 26); SetColor(Yellow, Black);
		cout << "Мое золото: " << account[acc].rat.gold << endl;
		item = menuShop(&firstAidKit, NULL, NULL, item);
	}

	Menu sP;
	vector<string> shopPointer = { "        Купить", "        Назад" };

	int num = sP.select_vertical(shopPointer, 39, 23) + 1;

	switch (num)
	{
	case 1:
		system("cls");
		if (item == 0 && account[acc].rat.gold >= 100) //Аптечка
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 50;
			account[acc].rat.health += 50;
		}
		else
			purchase(account, acc, false);
		break;
	case 2:
		break;
	}
}


void accessories(Account* account, int acc, int item = 0)
{
	system("cls");

	gotoxy(0, 1, 11); SetColor(Cyan, Black);
	cout << "АКСЕССУАРЫ";

	gotoxy(80, 26); SetColor(Yellow, Black);
	cout << "Мое золото: " << account[acc].rat.gold << endl;

	if (item >= 0 && item <= 2)  //Запуск на первую страницу 
		item = menuShop(&bowRat, &headsetRat, &glassesRat, item);

	while (item >= 3 && item <= 5) // Страница 2 
	{
		system("cls");
		item = menuShop(&collarRat, NULL, NULL, item);

		gotoxy(80, 26); SetColor(Yellow, Black);
		cout << "Мое золото: " << account[acc].rat.gold << endl;

		if (item == 0) //Если переход на 1 страницу
		{
			item = menuShop(&bowRat, &headsetRat, &glassesRat, item);
		}
		else if (item == 3)
		{
			break;
		}
		else //Пустые прилавки
		{
			gotoxy(0, 23, 34); SetColor(Red, Black);
			cout << "Прилавок пустой!! Ты что слепая??" << endl;
			system("pause>nul"); system("cls");

			gotoxy(80, 26); SetColor(Yellow, Black);
			cout << "Мое золото: " << account[acc].rat.gold << endl;
			accessories(account, acc, item);
			return;
		}
	}

	int color = Brown;
	switch (item)
	{
	case 0: //Бантик
		color = colorSelection(&bowRat, color, 7, 15);
		break;
	case 1: //Наушники
		color = colorSelection(&headsetRat, color, 39, 15);
		break;
	case 2: //Очки
		color = colorSelection(&glassesRat, color, 71, 15);
		break;
	case 3: //Ошейник
		color = colorSelection(&collarRat, color, 7, 15);
		break;
	}

	Menu sP;
	vector<string> shopPointer = { "        Купить", "        Назад" };

	int num = sP.select_vertical(shopPointer, 39, 23) + 1;

	switch (num)
	{
	case 1:
		system("cls");
		if (item == 0 && account[acc].rat.gold >= 7) //Бантик
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 7;
			account[acc].shop.bow = true;
			account[acc].shop.colorBow = color;
			return;
		}
		else if (item == 1 && account[acc].rat.gold >= 10) //Наушники
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 10;
			account[acc].shop.headphones = true;
			account[acc].shop.colorHeadphones = color;
			return;
		}
		else if (item == 2 && account[acc].rat.gold >= 12) //Очки
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 12;
			account[acc].shop.glasses = true;
			account[acc].shop.colorGlasses = color;
			return;
		}
		else if (item == 3 && account[acc].rat.gold >= 5) //Ошейник
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 5;
			account[acc].shop.collar = true;
			account[acc].shop.colorCollar = color;
			return;
		}
		else
			purchase(account, acc, false);

		break;
	case 2:
		accessories(account, acc, item);
	}
}


void interior(Account* account, int acc, int item = 0)
{
	system("cls");

	gotoxy(0, 1, 9); SetColor(Cyan, Black);
	cout << "ИНТЕРЬЕР";

	gotoxy(80, 26); SetColor(Yellow, Black);
	cout << "Мое золото: " << account[acc].rat.gold << endl;

	while (item >= 0 && item <= 3) //Запуск
	{
		item = menuShop(&armchairRat, &lampRat, NULL, item);
		if (item >= 0 && item <= 1) //Если 1 или 2 ячейка
		{
			break;
		}
		else if (item == 2) //Пустые прилавки
		{
			gotoxy(0, 23, 34); SetColor(Red, Black);
			cout << "Прилавок пустой!! Ты что слепая??" << endl;
			system("pause>nul"); system("cls");

			gotoxy(80, 26); SetColor(Yellow, Black);
			cout << "Мое золото: " << account[acc].rat.gold << endl;
		}
	}

	int color = Brown;
	switch (item)
	{
	case 0: //Кресло
		color = colorSelection(&armchairRat, color, 7, 15);
		break;
	case 1: //Торшер
		color = colorSelection(&lampRat, color, 39, 15);
		break;
	}

	Menu sP;
	vector<string> shopPointer = { "        Купить", "        Назад" };

	int num = sP.select_vertical(shopPointer, 39, 23) + 1;

	switch (num)
	{
	case 1:
		system("cls");
		if (item == 0 && account[acc].rat.gold >= 20) //Кресло
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 20;
			account[acc].shop.armchair = true;
			account[acc].shop.colorArmchair = color;
			return;
		}
		else if (item == 1 && account[acc].rat.gold >= 15) //Торшер
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 15;
			account[acc].shop.lamp = true;
			account[acc].shop.colorLamp = color;
			return;
		}
		else
			purchase(account, acc, false);

		break;
	case 2:
		interior(account, acc, item);
	}
}


void shop(Account* account, int acc)
{
	system("cls");

	printShopRat();

	string signboard = R"Rat(
КРЫСИНЫЙ МАГАЗИН ПАЦЮЧОК
)Rat";
	printRaw(signboard, 0, 1, 1, Red, Black);

	if (account[acc].rat.gold > 0)
	{
		string ratArt = R"Rat(
- Привет, хвостатая, решила обновиться?
- Выбери интересующий тебя раздел
)Rat";
		printRaw(ratArt, 0, 3, 1, LightRed, Black, 0);


		Menu sP;
		vector<string> shopPointer = { "    Забота о себе", "     Аксессуары", "      Интерьер", "        Выход" };

		int num = sP.select_vertical(shopPointer, 39, 18) + 1;

		switch (num)
		{
		case 1:
			careRat(account, acc);
			break;
		case 2:
			accessories(account, acc);
			break;
		case 3:
			interior(account, acc);
			break;
		case 4:
			return;
		}

	}
	else
	{
		playRozbiinik();
		string ratArt = R"Rat(
- Ты кто такая? Крыса )Rat";
		ratArt.append(account[acc].rat.name);
		ratArt += R"Rat(??
- Нет, не слышал про таких
- Не хочу иметь дело с незнакомцами
- Ты еще и без денег???
- Брысь отсюда! 
- Приходи когда заработаешь денег!
)Rat";
		printRaw(ratArt, 0, 3, 1, LightRed, Black, 50);
	}
	SetColor(Red, Black);
	gotoxy(30, 27);
	system("pause");
}
