#pragma once

void shop(Account* account, int acc)
{
	system("cls");

	//SetColor(Magenta, Black);
	//printFrame(28, 98, 1, 1);

	//SetColor(LightMagenta, Black);
	//printFrame(28, 98, 1, 1);

	printShopRat();


	string ratArt = R"Rat(
КРЫСИНЫЙ МАГАЗИН ПАЦЮЧОК
Привет, хвостатая, решила обновиться?
Выбери интересующий тебя раздел
)Rat";

	printRaw(ratArt, 0, 2, 1, Red, Black, 50);





	Menu sP;
	vector<string> shopPointer = { "    Забота о себе", "     Аксессуары", "      Интерьер", "        Выход" };

	int num = sP.select_vertical(shopPointer, 45, 21) + 1;

	SetColor(Green, Black);
	gotoxy(30, 27);
	system("pause");
}