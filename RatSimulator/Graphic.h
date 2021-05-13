#pragma once
#include<iostream>
#include<fstream>
#include"Menu.h"
#include"Timer.h"
#include"Struct.h"

void printScreensaver() //�������� 
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
	SetColor(Magenta, Black);
	printFrame(8, 74, 13, 12);
	SetColor(LightMagenta, Black);
	const int ROWS_CONT = 6;
	string rows[ROWS_CONT] = {
	" ��� �����: | ��������: | �������: | ���������: | ������:  | ���������: ",
	"________________________________________________________________________",
	"   �����    |    200    |   200    |     5      |   10     |   ������   ",
	"   �����    |    100    |   100    |     2      |    5     | ���������� ",
	"   ������   |    50     |   50     |     0      |    0     |   �������  ",
	"  ��������  |    999    |   999    |    999     |   999    |    �����   "
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(0, 12 + i + 1, size(rows[i]));
		cout << rows[i] << endl;
	}

	SetColor(Green, Black);
	gotoxy(30, 20);
	system("pause");
}

void printRules()
{
	system("cls");
	SetColor(Magenta, Black);
	printFrame(28, 98, 1, 1);
	string rows[] = {
	"�������:",
	" ",
	" ���� ������ ������� ������������ ���������� �������. ",
	"����� � ����-����, �� ������ �������� ������ ������. ",
	" ",
	"������:",
	"���������� 5 ������� ��� �� ������� ������� �����.",
	"������� �� � ������������ ������ �������� � �������, ��� �� � ������� �������� ������. ",
	" ",
	"���� ��������:",
	"��������� �� ����-����, +25 ��� -25. ���� � ����� ������� ��������.",
	" ",
	" ������:",
	"������ ��� �������� � ����-����. ����� ��� �������� �����, �����������",
	" ",
	"��������:",
	"���������� ��� ��������� � ����-����, ��������� ��� ����� ����� �������.",
	" ",
	"�������:",
	"���������� �� ����� � ����-����, ����� ��������� ����� 0/2/4/999 ��� � ����������� �� ������."
	};
	int sizeRowsArray = sizeof(rows) / sizeof(string);
	for (int i = 0; i < sizeRowsArray; i++)
	{
		switch (i) //��������� ��� ������� ��������� ��� �����
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
	"  ������: | N-����: | �������: | �������: | ������: ",
	"____________________________________________________",
	"  ������  |    3    |    15    |    10    |    2    ",
	"  ������� |    4    |    15    |    25    |    3    ",
	"  ������� |    5    |    25    |    30    |    5    ",
	"  ������� |    6    |    30    |    50    |    7    "
	};
	for (int i = 0; i < ROWS_CONT; i++)
	{
		gotoxy(x, y + i + 1, size(rowsT[i]));
		cout << rowsT[i] << endl;
	}

}


void printRAT(Account* account, int acc, char eyes = 'O')  //��������� �����. �������� � ������������. 
{
	//^^ OO XX  (����� ����� �������� � ����������� �� �������� ����)
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


void printAcc(Account* account, int sizeAcc) //�������� �������
{
	setlocale(0, "");
	system("cls");
	for (size_t i = 0; i < sizeAcc; i++)
	{
		cout << "----------��� � " << i << endl;
		cout << "���  " << account[i].rat.name << endl;
		cout << "���  " << account[i].rat.mode << endl;
		cout << "�������  " << account[i].rat.rating << endl;
		cout << "�������  " << account[i].rat.satiety << endl;
		cout << "�����  " << account[i].rat.gold << endl;
		cout << "��������  " << account[i].rat.health << endl;
		cout << "�����  " << account[i].time << endl;
	}
	gotoxy(30, 28);
	system("pause");
}
