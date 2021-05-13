#pragma once


void generateSecretNum(int modeSize, char secretNum[]) 
{
	srand(time(0));
	char buff[2]{ NULL };
	int randNum[8]{ NULL };

	for (int i = modeSize - 1; i >= 0; i--) //Муть, но работает
	{
		randNum[i] = rand() % 10;

		for (int j = modeSize - 1; j > i; j--)
		{
			if (randNum[i] == randNum[j])
				i++;
		}
	}
	for (size_t i = 0; i < modeSize; i++) //Из инт в чар
	{
		_itoa(randNum[i], buff, 10);
		strcat(secretNum, buff);
	}

}
void cinNumber(int modeSize, char cinNum[], char secretNum[]) {
	cout << "#-------------------" << endl;
	cout << "|-Ваше число: ";
	SetColor(Red, Black);
	cin.getline(cinNum, 8);
	SetColor(Green, Black);

	if (strlen(cinNum) != strlen(secretNum))
	{
		cout << " Введите " << modeSize << " значное число!\n";
		cinNumber(modeSize, cinNum, secretNum);
	}

}

int guessNum(int modeSize, char secretNum[], int att, char* previous[], int sizePrevious = 0) {

	if (att != 0)
	{
		att--;
		char cinNum[8]{ NULL };
		cinNumber(modeSize, cinNum, secretNum);
		int cow = 0;
		int bull = 0;
		for (int i = 0; i < modeSize; i++)
		{
			if (secretNum[i] == cinNum[i])
				cow++;
			else
			{
				for (int j = 0; j < modeSize; j++)
				{
					if (secretNum[i] == cinNum[j])
						bull++;
				}
			}
		}
		system("cls");
		cout << " Коров: " << cow << endl;
		cout << " Быков: " << bull << endl;
		cout << " Отеточка: " << secretNum << endl; //Загаданное число

		addElem(previous, sizePrevious, cinNum);
		cout << " Предыдущие числа:";
		SetColor(Red, Black);
		for (size_t i = 0; i < sizePrevious; i++)
		{
			cout << " " << previous[i];

		}
		cout << endl;
		SetColor(Green, Black);

		cout << " Попыток: " << att << endl;

		if (cow == modeSize)
		{
			cout << "\n Победа! " << endl;
			cout << " Попыток: " << att << endl;

			system("pause");

			return true;
		}
		else
			guessNum(modeSize, secretNum, att, previous, sizePrevious);
	}
	else
	{
		cout << "\n Поражение! " << endl;

		system("pause");
		return false;
	}

}

int bullsAndCows(int& modeSize)
{
	system("cls");
	SetColor(Magenta, Black);
	printFrame(28, 98, 1, 1);

	SetColor(LightGreen, Black);
	printFrame(8, 54, 23, 7);

	SetColor(Green, Black);
	tableCowAndBulls(0, 7);


	Menu m;
	vector<string> mainMenu = { "        Лекий", "       Обычный", "       Сложный","       Хардкор" };
	int num = m.select_vertical(mainMenu, 39, 19) + 1;

	int att;
	if (num == 1)
	{
		modeSize = 3;
		att = 15;
	}
	else if (num == 2)
	{
		modeSize = 4;
		att = 15;
	}
	else if (num == 3)
	{
		modeSize = 5;
		att = 25;
	}
	else
	{
		modeSize = 6;
		att = 30;
	}

	system("cls");
	SetColor(Green, Black);
	ShowConsoleCursor(true);

	char* secretNum = new char[modeSize] {NULL};
	char* previous = new char[] {NULL};
	cout << "#--------------------------------------#" << endl;
	cout << " Попыток: " << att << endl;
	generateSecretNum(modeSize, secretNum);
	return guessNum(modeSize, secretNum, att, &previous);
}