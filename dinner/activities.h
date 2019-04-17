#pragma once
#include <vector>
#include "recepies.h"

class activities
{
public:
	activities() {};
	~activities();

	std::vector<recepies *> recept;
	std::string answer;
	//bool swe_lang = true;
	int found = 0;


	// funktioner
	void getData(); // funktion som h�mtar in data fr�n fil.
	void mainMenu(); // huvudmeny
	void searchMainIngredient(); // s�kfunktion
	void randomDinner(); // slumpa fram en middag

	void searchIn(std::string); // s�k efter huvudingridiens
	//void chooseLang(); // v�lj spr�k
	void add(); //l�gg till matr�tt

};

