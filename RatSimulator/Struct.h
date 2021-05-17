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
	int mode;
	int rating;
	int satiety;
	int gold;
	int health;
};

struct Shop
{
	bool bow = false;
	int colorBow;

	bool headphones = false;
	int colorHeadphones;

	bool glasses = false;
	int colorGlasses;

	bool collar = false;
	int colorCollar;

	bool armchair = false;
	int colorArmchair;

	bool lamp = false;
	int colorLamp;
};

struct Account
{
	Rat rat;
	Date date;
	Shop shop;
	int time = 0;
	int FeedingAttempts;
};