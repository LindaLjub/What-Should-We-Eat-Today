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
	void getData(); // funktion som hämtar in data från fil.
	void mainMenu(); // huvudmeny
	void searchMainIngredient(); // sökfunktion
	void randomDinner(); // slumpa fram en middag

	void searchIn(std::string); // sök efter huvudingridiens
	//void chooseLang(); // välj språk
	void add(); //lägg till maträtt

};

