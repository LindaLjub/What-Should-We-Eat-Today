#pragma once
#include <vector>
#include "recepies.h"

class activities
{
public:
	activities() {};
	~activities();

	std::vector<recepies *> recept;
	std::vector<recepies *> chicken;
	std::vector<recepies *> fish;
	std::vector<recepies *> meat;
	std::vector<recepies *> veg;

	std::string answer;


	// funktioner
	void getData(); // funktion som hämtar in data från fil.
	void mainMenu(); // huvudmeny
	void listOfDishes(); // lista rätter
	void searchMainIngredient(); // sökfunktion
	template <typename T> T searchIn(T inParameter);
	void add(); //lägg till maträtt
	void chooseRandom(); // välj vad som ska slumpas
	template <typename T> T randomDinnerSpec(T); // slumpa bland specifika/alla rätter
};

