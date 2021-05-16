#pragma once


void careRat(Account* account, int acc)
{
	system("cls");

	string signboard = R"Rat(
ЗАБОТА О СЕБЕ
)Rat";
	printRaw(signboard, 0, 0, 1, Cyan, Black);

	gotoxy(80, 26); SetColor(Yellow, Black);
	cout << "Мое золото: " << account[acc].rat.gold << endl;
	int item = menuShop(&firstAidKit);
	while (item != 0)
	{
		gotoxy(0, 23, 34);
		SetColor(Red, Black);
		cout << "Прилавок пустой!! Ты что слепая??" << endl;
		system("pause>nul");
		system("cls");
		gotoxy(80, 26); SetColor(Yellow, Black);
		cout << "Мое золото: " << account[acc].rat.gold << endl;
		item = menuShop(&firstAidKit, NULL, item);
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


void accessories(Account* account, int acc)
{
	system("cls");

	string signboard = R"Rat(
АКСЕССУАРЫ
)Rat";
	printRaw(signboard, 0, 0, 1, Cyan, Black);
	int ds = Blue;
	gotoxy(80, 26); SetColor(Yellow, Black);
	cout << "Мое золото: " << account[acc].rat.gold << endl;
	int item = menuShop(&bowRat, &headsetRat);
	while (item > 1)
	{
		gotoxy(0, 23, 34);
		SetColor(Red, Black);
		cout << "Прилавок пустой!! Ты что слепая??" << endl;
		system("pause>nul");
		system("cls");
		gotoxy(80, 26); SetColor(Yellow, Black);
		cout << "Мое золото: " << account[acc].rat.gold << endl;
		item = menuShop(&bowRat, &headsetRat, item);
	}

	int color = Brown;
	switch (item)
	{
	case 0: //Бантик
		color = colorSelection(&bowRat, color, 7, 15);
		break;
	case 1: //Наушники
		color = colorSelection(&headsetRat, color, 38, 15);
	default:
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
			account[acc].rat.gold -= 50;
			account[acc].shop.bow = true;
			account[acc].shop.colorBow = color;

		}
		else if (item == 1 && account[acc].rat.gold >= 10) //Наушники
		{
			purchase(account, acc, true);
			account[acc].rat.gold -= 50;
			account[acc].shop.headphones = true;
			account[acc].shop.colorHeadphones = color;
		}
		else
			purchase(account, acc, false);


		break;
	case 2:
		accessories(account, acc);
	}
}


void interior(Account* account, int acc)
{
	system("cls");
	SetColor(Magenta, Black);
	printFrame(25, 88, 6, 1);


	SetColor(Green, Black); gotoxy(30, 27); system("pause");
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
