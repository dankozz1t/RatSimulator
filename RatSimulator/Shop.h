#pragma once




void careRat()
{
	system("cls");
	SetColor(LightCyan, Black);
	printFrame(28, 98, 1, 1);

	string signboard = R"Rat(
ЗАБОТА О СЕБЕ
)Rat";
	printRaw(signboard, 0, 0, 1, Cyan, Black);

	//SetColor(LightCyan, Black);
	//printFrame(16, 30, 3, 3);
	//printFrame(16, 30, 35, 3);
	//printFrame(16, 30, 67, 3);

	//SetColor(Green, Black);
	//printFrame(16, 30, 3, 3);
	char c = 0;
	int pos = 0;
	while (c != Enter)
	{
		for (int i = 0; i < 2; i++)
		{
			SetColor(LightCyan, Black);
			printFrame(16, 30, 3, 3);
			printFrame(16, 30, 35, 3);
			printFrame(16, 30, 67, 3);

			SetColor(Green, Black);
			int xOs = (pos == 0 || pos == 1) ? ((pos == 0) ? 3 : 35) : 67;
				printFrame(16, 30, xOs, 3);
				cout << "\t" << pos << " " << endl;

		}
		c = _getch();
		cout << "\t\t\t" << (int)c << endl;
		switch (c)
		{
		case Left: //разобраться с багом!
			if (pos < 0)
				pos = 4;
				pos--;
			break;
		case Right:
			if (pos > 3)
				pos = 1;
				pos++;
			break;
		}
	}


	//Menu sP;
	//vector<string> shopPointer = { "    Аптечка", "     неАптечка", "      НеАптечка", "        Выход" };

	//int num = sP.select_vertical(shopPointer, 39, 23) + 1;

	//switch (num)
	//{
	//case 1:
	//
	//	break;
	//case 2:
	//	
	//	break;
	//case 3:

	//	break;
	//case 4:
	//	return;
	//}


	SetColor(Blue, Black); gotoxy(30, 27); system("pause");
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
			careRat();
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
