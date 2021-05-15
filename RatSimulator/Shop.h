#pragma once




void careRat(Account* account, int acc)
{
	system("cls");

	string signboard = R"Rat(
ЗАБОТА О СЕБЕ
)Rat";
	printRaw(signboard, 0, 0, 1, Cyan, Black);

	int item = menuShop();
	while (item > 0)
	{
		gotoxy(0, 23, 34);
		SetColor(Red, Black);
		cout << "Прилавок пустой!! Ты что слепая??" << endl;
		system("pause>nul");
		system("cls");
		item = menuShop(item);
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
			account[acc].rat.gold -= 100;
			account[acc].rat.health += 100;
		}
		else
			purchase(account, acc, false);


		break;
	case 2:
		return;
	}
}


void accessories()
{
	system("cls");
	SetColor(Magenta, Black);
	printFrame(25, 88, 6, 1);


	SetColor(Green, Black); gotoxy(30, 27); system("pause");
}


void interior()
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
		printRaw(ratArt, 0, 3, 1, LightRed, Black, 50);


		Menu sP;
		vector<string> shopPointer = { "    Забота о себе", "     Аксессуары", "      Интерьер", "        Выход" };

		int num = sP.select_vertical(shopPointer, 39, 18) + 1;

		switch (num)
		{
		case 1:
			careRat(account, acc);
			break;
		case 2:
			accessories();
			break;
		case 3:
			interior();
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
