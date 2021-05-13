#pragma once
#include<iostream>
#include<fstream>
#include"Menu.h"
#include"Timer.h"

struct Date
{
	int d, m, y;

	void print()
	{
		if (d < 10)
			cout << 0;
		cout << d << ".";
		if (m < 10)
			cout << 0;
		cout << m << "." << y;
	}
};

struct Rat
{
	char name[10];
	int mode = 1;
	int rating = 0;
	int satiety = 0;
	int gold = 0;
	int health = 100;
};

struct Account
{
	Rat rat;
	Date date;
	int time = 0;
	int countFeed = 0;
};