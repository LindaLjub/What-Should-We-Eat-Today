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


	// funktioner
	void getData(); // funktion som h�mtar in data fr�n fil.
	void mainMenu(); // huvudmeny
	void searchMainIngredient(); // s�kfunktion
	void randomDinner(); // slumpa fram en middag

	void searchIn(std::string);

};

