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
	void getData(); // funktion som h�mtar in data fr�n fil.
	void print(); // printar ut alla recept
	void searchMainIngredient(); //
	void mainMenu();



};

