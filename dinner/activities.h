#pragma once
#include <vector>
#include "recepies.h"

class activities
{
public:
	activities();
	~activities();

	std::vector<recepies *> recept;
	std::string answer;


	// funktioner
	void getData(); // funktion som hämtar in data från fil.
	void print(); // printar ut alla recept
	void searchMainIngredient(); //
	void mainMenu();



};

