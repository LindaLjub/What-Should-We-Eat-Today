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
	bool swe_lang = true;


	// funktioner
	void getData(); // funktion som hämtar in data från fil.
	void mainMenu(); // huvudmeny
	void searchMainIngredient(); // sökfunktion
	void randomDinner(); // slumpa fram en middag

	void searchIn(std::string);
	void chooseLang(); // välj språk

};

