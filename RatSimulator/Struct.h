#pragma once
#include<iostream>
#include<fstream>
#include"Menu.h"
#include"Timer.h"

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
	int colorBow = 0;

	bool headphones = false;
	int colorHeadphones = 0;

	bool glasses = false;
	int colorGlasses = 0;

	bool collar = false;
	int colorCollar = 0;

	bool armchair = false;
	int colorArmchair = 0;

	bool lamp = false;
	int colorLamp = 0;
};

struct Account
{
	Rat rat;
	Shop shop;
	int time = 0;
	int FeedingAttempts = 0;
};