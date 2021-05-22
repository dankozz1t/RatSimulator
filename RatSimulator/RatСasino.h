#pragma once
#include "Func.h"
#include"Menu.h"
#include"Graphic.h"

int rulesRatCasino()
{
	string creatorText = R"Rat(
%4Крысиное казино%7

Правила просты
Вы делаете ставку%6(Золото)%7 и загадываете число. (от 0 до 9)
Если ваше число равняется выигрышным, ваша ставка удваеватся
Если ваше число +-1 от выгрышного, то ваша ставка не исчезает
Вы можете продолжить игру с вашей ставкой или же остановится
При продолжении игры, стоимость захода не отнимается

%2При выигрыше:%7 +золота ставки, +25 рейтинга
%4При проигрыше:%7 -золота ставки, -25 рейтинга и списание захода 
)Rat";

	printRawF(creatorText, 62, 1, true);

	SetColor(Red, Black);
	gotoxy(35, 14);
	cout << "Стоимость захода составляет 10 здоровья и 10 сытости";

	int option = 0;
	Menu m;
	vector<string> mainMenu = { "        Играть", "        Назад" };
	return option = m.select_vertical(mainMenu, 50, 18) + 1;
}

int RatCasino(int& goldRate)
{
	system("cls");
	bool defeat = 0;
	int firstBet = goldRate;

	while (!defeat)
	{
		system("cls"); SetColor(Red, Black);

		gotoxy(0, 13, 16);
		cout << "Ваша ставка: "; SetColor(Brown, Black); cout << goldRate; SetColor(Red, Black);

		gotoxy(0, 14, 33);
		int userNumber = 0;
		cout << "Введите ваше число(от 0 до 9): "; SetColor(LightGreen, Black); cin >> userNumber;

		playCasino(); Sleep(100);

		Timer t; int timeNow = t.elapsed();

		int winningNumber = 0;
		srand(time(0));
		while (timeNow < 12)
		{
			winningNumber = rand() % 10;
			Sleep(timeNow + 100); //Не так быстро

			SetColor(Green, Black); gotoxy(0, 15, 1);
			cout << winningNumber << endl;

			timeNow = t.elapsed();
		}
		winningNumber = 2; //Тесты

		if (userNumber == winningNumber)
		{
			playWin();
			gotoxy(0, 17, 7);  SetColor(Green, Black);
			cout << "ПОБЕДА" << endl;
			goldRate *= 2;
			gotoxy(0, 18, 35);
			cout << "Ваш выигрыш состовляет: "; SetColor(Brown, Black); cout << goldRate;

			Menu m; vector<string> casinoPlay = { "     Продолжить", "        Выход" };
			if (defeat = m.select_vertical(casinoPlay, 39, 21))
			{
				goldRate -= firstBet;
				return 0;
			}


		}
		else if (userNumber - 1 == winningNumber || userNumber + 1 == winningNumber)
		{
			gotoxy(0, 17, 10);
			cout << "Чуть-чуть" << endl;
			gotoxy(0, 18, 24);
			cout << "Ваша ставка не исчезает" << endl;

			Menu m; vector<string> casinoPlay = { "     Продолжить", "        Выход" };
			if (defeat = m.select_vertical(casinoPlay, 39, 21))
				return 0;
	
		}
		else
		{
			playGameOver();
			defeat = true;
		}
	}

	SetColor(Red, Black); gotoxy(0, 17, 10);
	cout << "ПОРАЖЕНИЕ" << endl;
	gotoxy(0, 18, 26);
	cout << "Ваш проигрыш состовляет: "; SetColor(Brown, Black); cout << goldRate << endl;
	goldRate = firstBet;

	SetColor(Green, Black); gotoxy(30, 28); system("pause");
	return defeat;
}