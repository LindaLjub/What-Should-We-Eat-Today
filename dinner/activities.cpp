#include "pch.h"
#include "activities.h"
#include <iostream>
#include <fstream> // h�mta in data fr�n fil
#include <string> // getline, string


activities::activities()
{
}


activities::~activities()
{
}

void activities::mainMenu()
{
	bool b_main = false;
	while (!b_main)
	{

	std::cout << " [1] Slumpa bland alla recept\n [2] Se alla recept\n [3] Avsluta" << std::endl;
	std::cin >> answer;
	

		switch (answer[0])
		{
			case '1':
			{
				break;
			}
			case '2':
			{
				print();
				break;
			}
			case '3':
			{	
				b_main = true;
				break;
			}
		}

	}

}


// h�mtar in all data till vektorn.
void activities::getData()
{
	//std::ofstream datafile("dinner.csv"); // skapar en fil med namn "dinner.csv" i samma mapp som programmet.

	// �ppnar filen 
	std::ifstream datafile("dinner.csv");
	std::string name, mainIngredient;

	// Om filen �r �ppen, h�mta in datum, tid osv. till dess variabler.
	if (datafile.is_open())
	{
		while (!datafile.eof()) // forts�tt s� l�nge som det finns n�got i datan.
		{
			getline(datafile, name, ' ');	// forts�tt till f�rsta mellanslag. Tilldela datan till variabeln date.
			getline(datafile, mainIngredient, ',');	// forts�tt till f�rsta mellanslag. Tilldela datan till variabeln date.

			recept.push_back(new recepies(name, mainIngredient));
		}

		// St�nger filen n�r man �r f�rdig med den.
		datafile.close();

	}

}

void activities::print()
{

	for (int i = 0; i < recept.size(); i++)
	{
		std::cout << " Matr�tt: " << recept[i]->get_name() << std::endl;
		std::cout << " Huvudingrediens: " << recept[i]->get_MainIngridient() << std::endl;
		std::cout << " --- " << std::endl;
	}





}


void activities::searchMainIngredient()
{





}