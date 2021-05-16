#pragma once
#include<iostream>
#include<fstream>
#include"Menu.h"
#include"Timer.h"
#include"Struct.h"

void printScreensaver() //Заставка 
{
	int t = 10;
	for (int x = 2; x != 20; x++)
	{
		{
			const int ROWS_COUNT = 6;
			string rows[ROWS_COUNT] = {
			" ___    _    _",
			"| _ \\  | |  | |",
			"||_) | | |_ | |",
			"| _ <  | _ \\| |",
			"||_) | ||_) | |",
			"|___/  |___/|_|"
			};
			for (int i = 0; i < ROWS_COUNT; i++)
			{
				gotoxy(x, 6 + i);
				cout << rows[i] << endl;

			}
			if (x != 19)
			{
				for (size_t i = 6; i < 12; i++)
				{
					gotoxy(x, i);
					cout << " ";
				}
			}
			Sleep(t);
		}
		const int ROWS_COUNT = 6;
		string rows[ROWS_COUNT] = {
		" _    _   ____    _    _   ____   _____",
		"| |  | | |  _ \\  | |  | | /  __| |  _  \\ ",
		"| |_ / | | |_) | | |_ | | | /    | |_) |  ",
		"|  _  /  |  __/  | _ \\| | | |    |  _  | ",
		"| | \\ \\  | |     ||_) | | | \\__  | | | |  ",
		"|_|  |_| |_|     |___/|_| \\____| |_| |_|  "
		};
		for (int i = 0; i < ROWS_COUNT; i++)
		{
			gotoxy(41, 6 + i);
			cout << rows[i] << endl;
		}

	}
};

void printTypes()
{
	SetColor(LightGreen, Black);
	printFrame(8, 74, 13, 6);
	SetColor(Green, Black);
	const int ROWS_CONT = 6;
	string rows[ROWS_CONT] = {
	" Тип крысы: | Здоровье: | Сытость: | Покормить: | Зотоло:  | Сложность: ",
	"________________________________________________________________________",
	"   Хаски    |    200    |   200    |     5      |   10     |   ЛЕГКАЯ   ",
	"   Дамбо    |    100    |   100    |     2      |    5     | НОРМАЛЬНАЯ ",
	"   Сфинкс   |    50     |   50     |     0      |    0     |   ХАРДКОР  ",
	"  Общажная  |    999    |   999    |    999     |   999    |    ЧИТЕР   "
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(0, 6 + i + 1, size(rows[i]));
		cout << rows[i] << endl;
	}

}

void printRules()
{
	system("cls");
	SetColor(Magenta, Black);
	printFrame(28, 98, 1, 1);
	string rows[] = {
	"Правила:",
	" ",
	" Ваша задача прожить максимальное количество времени. ",
	"Играя в мини-игры, вы можете получить разные плюшки. ",
	" ",
	"Режимы:",
	"Существует 5 режимов или же окрасов главной крысы.",
	"Разница их в максимальном запасе здоровья и сытости, так же в базовом капитале золота. ",
	" ",
	"Очки рейтинга:",
	"Получаете и теряете за исход мини-игр. Идут в общую таблицу рекордов.",
	" ",
	" Золото:",
	"Дается при выигрыше в мине-игре. Нужно для прокачки крысы, аксессуаров",
	" ",
	"Здоровье:",
	"Отнимается при проигрыше в мини-игры, пополнять его можно купив аптечку.",
	" ",
	"Сытость:",
	"Отнимается за заход в мини-игру, можно покормить крысу 0/2/4/999 раз в зависимости от режима."
	};
	int sizeRowsArray = sizeof(rows) / sizeof(string);
	for (int i = 0; i < sizeRowsArray; i++)
	{
		switch (i) //Погуглить как сделать адекватно эту хуйню
		{
		case 0:
			SetColor(Red, Black);
			break;
		case 5:
			SetColor(LightBlue, Black);
			break;
		case 9:
			SetColor(LightCyan, Black);
			break;
		case 12:
			SetColor(Yellow, Black);
			break;
		case 15:
			SetColor(LightRed, Black);
			break;
		case 18:
			SetColor(Brown, Black);
			break;
		default:
			SetColor(White, Black);
		}

		gotoxy(-1, 1 + i + 1, size(rows[i]));
		cout << rows[i] << endl;
	}

	SetColor(Green, Black);
	gotoxy(0, 27, 44);
	system("pause");
}

void tableCowAndBulls(int x, int y)
{
	const int ROWS_CONT = 6;
	string rowsT[ROWS_CONT] = {
	"  Режимы: | N-цифр: | Попыток: | Рейтинг: | Зотоло: ",
	"____________________________________________________",
	"  Легкий  |    3    |    15    |    10    |    2    ",
	"  Обычный |    4    |    15    |    25    |    3    ",
	"  Сложный |    5    |    25    |    30    |    5    ",
	"  Хардкор |    6    |    30    |    50    |    7    "
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(x, y + i + 1, size(rowsT[i]));
		cout << rowsT[i] << endl;
	}

}


void printRAT(Account* account, int acc, char eyes = 'O')  //Состояние Крысы. Привести к адекватности. 
{
	//^^ OO XX  (Глава крысы меняются в зависимости от действий игры)
	switch (account[acc].rat.mode)
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
	string ratArt = R"Rat(
 ___      ___  
/   \    /   \ 
|    \__/    | 
|            | 
\__        __/
  / )Rat";
	ratArt.push_back(eyes);
	ratArt.append("   ");
	ratArt.push_back(eyes);
	ratArt.append(" |  \n");
	ratArt.append("@         |  \n");

	if (eyes == 'X')
		ratArt.append(" \\___     |  \n");
	else
		ratArt.append(" \\___/    |  \n");
	ratArt.append(" |        |  ");

	printRaw(ratArt, 83, 17);

}


void printAcc(Account* account, int sizeAcc) //Тестовый вариант
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


void printCharacteristics(Account* account, int acc)
{
	gotoxy(60, 26);
	SetColor(LightRed, Black);
	string mode;
	switch (account[acc].rat.mode)
	{
	case 1:
		mode = "Хаски";
		break;
	case 2:
		mode = "Дабмо";
		break;
	case 3:
		mode = "Сфинкс";
		break;
	case 4:
		mode = "Общажная";
		break;
	};
	cout << mode << " крыса ";
	SetColor(Red, Black);
	cout << account[acc].rat.name;


	gotoxy(13, 2);
	SetColor(Red, Black);
	cout << "Здоровье: ";
	SetColor(White, Black);
	cout << account[acc].rat.health;

	gotoxy(33, 2);
	SetColor(Brown, Black);
	cout << "Сытость: ";
	SetColor(White, Black);
	cout << account[acc].rat.satiety;

	gotoxy(53, 2);
	SetColor(Yellow, Black);
	cout << "Золото: ";
	SetColor(White, Black);
	cout << account[acc].rat.gold;

	gotoxy(73, 2);
	SetColor(LightCyan, Black);
	cout << "Рейтинг: ";
	SetColor(White, Black);
	cout << account[acc].rat.rating;
}

void printPolic() //злой чел(агрессивный)
{
	const int ROWS_COUNT = 17;
	string rows[ROWS_COUNT] = {

	"``````||||||||||||||||",
	"`````=``````````````\\ ",
	"`````=```````````````|",
	"````_=````````````___/",
	"```/`_\\```````````(o)\\ ",
	"``|`|`\\````````````_``\\ ",
	"``|`| / ````````````(____)",
	"```\__ / ``````````/```|",
	"````/```````````/``___)",
	"```/````\```````\````_)```````````````````````)",
	"``\``````\```````````/```````````````````````(",
	"\ / `\``````\_________ / ```|\_________________,_`)",
	"`\ / `\``````/````````````|`````= == = `_______)__)",
	"``\ / `\````/```````````__/___``= == = _ /",
	"```\ / `\``/```````````(O____)\\_(_ /",
	"````````````````````(O_`____)",
	"`````````````````````(O____)"
	};

	for (int i = 0; i < ROWS_COUNT; i++)
	{
		gotoxy(1, 6 + i);
		cout << rows[i] << endl;
	}
}

void printShopRat()
{
	string ratArt = R"Rat(
            :                       
           `:-....```.--.           
            -`.... .-...-.          
          ``::..`.:+:-:/::`         
          `./...---.    `.-         
           .`   :.`      `/`````    
          `.  - `/.  `.. `-.```     
          -    ...:::` -.:  `       
         -          `..`  -         
        .`                `.        
        -   .     ``````.` -`       
   :.` -   .`            ..-.-...-. 
 ``.-.:..-.               --.-``..  
`..:.`-. -                `-.`--.--.
  .....  -                 - .-..-` 
  .``   .`                 -  `.    
  ``.--:`                  -   ..   
       -                  -     -   
       -                 .`     -   
       .`              `.      ..   
        -          ````       ..    
        `.  `.``````````..``-:-`    
     :------`            `...:./    
     -...`                        )Rat";

	SetColor();
	printRaw(ratArt, 1, 1);
}

void purchase(Account* account, int acc, bool acquisition)
{
	printShopRat();
	string signboard = R"Rat(
КРЫСИНЫЙ МАГАЗИН ПАЦЮЧОК
)Rat";
	printRaw(signboard, 5, 1, 1, Red, Black);

	if (acquisition)
	{
		string textDealer = R"Rat(
- Спасибо за покупку! Приходите еще!
)Rat";
		printRaw(textDealer, 0, 3, 1, LightRed, Black, 50);
	}
	else
	{
		string textDealer = R"Rat(
- Эх, помню я был такой же молодой и глу..
)Rat";
		printRaw(textDealer, 0, 3, 1, LightRed, Black, 50);


		Menu m;
		vector<string> Dealer = { " Выслушать торговца", "   Чел...Ты в муте" };

		int num = m.select_vertical(Dealer, 39, 18) + 1;
		if (num == 1)
		{
			system("cls");
			printShopRat();
			string signboard = R"Rat(
КРЫСИНЫЙ МАГАЗИН ПАЦЮЧОК
)Rat";
			printRaw(signboard, 0, 1, 1, Red, Black);

			string textDealer2 = R"Rat(
- Эх, помню я был такой же молодой и глупой крысой
- Лез в драки, разбойничал, но ничего повзрослел-помудрел..
- Да и вообще....
- Я в своём познании настолько преисполнился, что как будто бы уже 100
- триллионов миллиардов лет проживаю на триллионах и триллионах таких же планет
- Понимаешь?
- Да ничего ты не понимаешь!
- Ладно, я вижу ты не плохая крыса.....
- Но сожалению я не могу дать тебе этот товар
- Пойми меня, пенсии маленькие...
- Приходи когда появятся деньги
)Rat";

			printRaw(textDealer2, 5, 3, 1, LightRed, Black, 50);
			SetColor(Red, Black);
			gotoxy(30, 27);
			system("pause");

			system("cls");

			string textGlobal = R"Rat(
Вы очень понравили продавцу, он рассказал о вас другим крысам
- вы получили +25 рейтинга
)Rat";
			printRaw(textGlobal, 0, 13, 1, LightRed, Black, 50);
			account[acc].rat.rating += 25;
		}
		else
		{
			system("cls");
			printShopRat();
			string signboard = R"Rat(
КРЫСИНЫЙ МАГАЗИН ПАЦЮЧОК
)Rat";
			printRaw(signboard, 8, 1, 1, Red, Black);

			string textRat = R"Rat(
- Чел...Ты в муте
)Rat";
			printRaw(textRat, 8, 3, 1, Yellow, Black, 50);

			string textDealer2 = R"Rat(
- Чт..чт...ЧТО???

- ЭТО ЧТО ЗА НЕВЕЖЛЕВАЯ КРЫСА? 
- Я ВСЕ ПОНЯЛ, ТЫ ХОТЕЛА СВОРОВАТЬ МОЙ ТОВАР???
- БРЫСЬ ОТСЮДА, ПОКА Я НЕ ВЫЗВАЛ КРЫСИНЫЙ ПАТРУЛЬ!!!
)Rat";
			printRaw(textDealer2, 8, 6, 1, LightRed, Black, 50);
			SetColor(Red, Black);
			gotoxy(30, 27);
			system("pause");


			system("cls");

			string textGlobal = R"Rat(
Продавец написал на вас заявление в крысиный патруль
- вы получили -25 рейтинга
)Rat";
			printRaw(textGlobal, 0, 13, 1, LightRed, Black, 50);

			account[acc].rat.rating -= 25;
		}
	}
}


int firstAidKit()
{
	string printСell = R"Rat(
АПТЕЧКА
+50 к здоровью

       .-----.      
#::::::|+:::+|::::::#
|-      `````      .|
|`      .@@@.      .|
|`   `::/@@@+::`   .|
|`   .@@@@@@@@@-   .|
|`   `--/@@@/--`   .|
|`      .@@@.     ..|
#..................:#

ЦЕНА: 50 золота
)Rat";

	printRaw(printСell, 7, 3, 1, LightRed, Black, 0, 30);
	return 0;
}

void printBow(int x = 85, int y = 19, int textColor = LightMagenta)
{
	string printСell = R"Rat(
|  \__/  |
|  |__|  |
|_/   \__|)Rat";

	printRaw(printСell, x, y, 0, textColor, Black);

	SetColor(textColor, Black);
	gotoxy(x + 1, y);
	cout << "_";
	gotoxy(x + 8, y);
	cout << "_";
	SetColor();
}

int bowRat() //В меню
{
	gotoxy(7, 4, 7, 30); SetColor(Red, Black);
	cout << "БАНТИК";

	gotoxy(7, 11, 16, 30); SetColor(Yellow, Black);
	cout << "ЦЕНА: 7  золота";

	printBow(13, 5, Brown);

	return 0;
}
int bowRat(int colorItem = LightMagenta) //Выбор цвета
{
	gotoxy(7, 4, 7, 30); SetColor(Red, Black);
	cout << "БАНТИК";

	gotoxy(7, 11, 16, 30); SetColor(Yellow, Black);
	cout << "ЦЕНА: 7  золота";

	printBow(13, 5, colorItem);
	return 0;

}


void printHeadphones(int x = 81, int y = 17, int textColor = LightGray)
{
	string printСell = R"Rat(
   ___________
  /.
 / |
(  |
 \_|)Rat";
	printRaw(printСell, x, y, 0, textColor, Black);

	string printСell2 = R"Rat(
_
.\ 
| \ 
|  ) 
|_/)Rat";
	printRaw(printСell2, x+14, y, 0, textColor, Black);
}

int headsetRat() //В меню
{
	gotoxy(46, 4); SetColor(Red, Black);
	cout << "НАУШНИКИ";

	gotoxy(43, 11); SetColor(Yellow, Black);
	cout << "ЦЕНА: 10 золота";

	printHeadphones(41, 4, Brown);

	return 0;
}

int headsetRat(int colorItem = Brown) //В меню
{
	gotoxy(46, 4); SetColor(Red, Black);
	cout << "НАУШНИКИ";

	gotoxy(43, 11); SetColor(Yellow, Black);
	cout << "ЦЕНА: 10 золота";

	printHeadphones(41, 4, colorItem);

	return 0;
}

int colorSelection(int (*printCell)(int), int color, int x = 7, int y = 15)
{
	Menu mP;
	vector<string> mPlayer = { "       Розовый", "       Красный", "       Зеленый", "        Синий" };
	int num = mP.select_vertical(mPlayer, x, y) + 1;
	switch (num)
	{
	case 1:
		color = LightMagenta;
		break;
	case 2:
		color = Red;
		break;
	case 3:
		color = Green;
		break;
	case 4:
		color = Blue;
		break;
	}
	printCell(color);
	return color;
}

//string ratArt = R"Rat(
// ___      ___  
///   \    /   \ 
//|    \__/    | 
//|            | 
//\__        __/
//  / )Rat";
//ratArt.push_back(eyes);
//ratArt.append("   ");
//ratArt.push_back(eyes);
//ratArt.append(" |  \n");
//ratArt.append("@         |  \n");
//
//if (eyes == 'X')
//ratArt.append(" \\___     |  \n");
//else
//ratArt.append(" \\___/    |  \n");
//ratArt.append(" |        |  ");
//
//printRaw(ratArt, 83, 17);
