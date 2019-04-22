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
	void getData(); // funktion som h�mtar in data fr�n fil.
	void mainMenu(); // huvudmeny
	void listOfDishes(); // lista r�tter
	void searchMainIngredient(); // s�kfunktion
	template <typename T> T searchIn(T inParameter);
	void add(); //l�gg till matr�tt
	void chooseRandom(); // v�lj vad som ska slumpas
	template <typename T> T randomDinnerSpec(T); // slumpa bland specifika/alla r�tter
};

