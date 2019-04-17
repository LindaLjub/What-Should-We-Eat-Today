#include "pch.h"
#include "activities.h"
#include <iostream>
#include <fstream> // h�mta in data fr�n fil
#include <string> // getline, string
#include <stdlib.h> // rand
#include <time.h> // srand
#include <algorithm> // till stablesort



activities::~activities()
{
	for (int i = 0; i < recept.size(); i++)
	{
		delete recept[i];
	}

	std::cout << " Vector content deleted.. " << std::endl;
}

// sortera efter huvudingrediens
bool text(const recepies *a, const recepies *b)
{
	return a->get_MainIngridient() < b->get_MainIngridient();
};

// h�mtar in all data till vektorn.
void activities::getData()
{
	//std::ofstream datafile("dinner.csv"); // skapar en fil med namn "dinner.csv" i samma mapp som programmet.

	// �ppnar filen 
	std::ifstream datafile("dinner.csv");
	std::string name, mainIngredient, addon, kategori;

	// Om filen �r �ppen, h�mta in datum, tid osv. till dess variabler.
	if (datafile.is_open())
	{
		while (!datafile.eof()) // forts�tt s� l�nge som det finns n�got i datan.
		{
			getline(datafile, name, ':');	// forts�tt till f�rsta mellanslag. Tilldela datan till variabeln date.
			getline(datafile, mainIngredient, ',');
			getline(datafile, addon, ',');
			getline(datafile, kategori);

			recept.push_back(new recepies(name, mainIngredient, addon, kategori));
		}

		// St�nger filen n�r man �r f�rdig med den.
		datafile.close();

	}
	else
	{
		std::cout << "Could not open file.." << std::endl;
	}

}

// en printfunktion, fungerar f�r olika vektorer
template <typename T> T printFunc(T inParameter)
{
	for (int i = 0; i < inParameter.size() - 1; i++)
	{
			std::cout << " Dish: " << inParameter[i]->get_name() << std::endl;
			std::cout << " Main: " << inParameter[i]->get_MainIngridient() << std::endl;
			std::cout << " Addon: " << inParameter[i]->get_addon() << std::endl;
			std::cout << " Category: " << inParameter[i]->get_kategori() << std::endl;
			std::cout << " --- " << std::endl;
	}

	return inParameter;
}

void activities::mainMenu()
{
	bool b_main = false;
	while (!b_main)
	{
			std::cout << " [1] Get a random dish\n [2] Search for dishes\n [3] See all dishes\n [4] Add dishes\n [5] Quit" << std::endl;
			std::cin >> answer;

		switch (answer[0])
		{
			case '1':
			{	
				randomDinner();
				break;
			}
			case '2':
			{
				searchMainIngredient();
				break;
			}
			case '3':
			{
				// sortera efter huvudingrediens
				//std::stable_sort(recept.begin(), recept.end(), text);
				printFunc(recept);
				break;
			}
			case '4':
			{
				add();
				break;
			}
			case '5':
			{	
				b_main = true;
				break;
			}
		}

	}

}

void activities::add()
{
	std::string name, main, addon, category;

		std::cout << " Enter name of dish: ";
		std::cin >> name;
		std::cout << " Enter main: " ;
		std::cin >> main;
		std::cout << " Enter addon: " ;
		std::cin >> addon;
		std::cout << " Choose category: ";
		std::cin >> category;
		std::cout << " --- " << std::endl;


	// �ppna filen, ios::app betyder, append at end of file. f�r att den bara ska l�gge till text utan att ta bort text
	std::ofstream write;
	write.open("dinner.csv", std::ios::app);

	// Om filen �r �ppen, h�mta in datum, tid osv. till dess variabler.
	if (write.is_open())
	{
		write << name << ":" << main << "," << addon << "," << category << "\n";
		std::cout << " Added to file! " << std::endl;
		std::cout << name << " " << main << " " << addon << " " << category << std::endl;
	}
	else
	{
		std::cout << "Could not open file.." << std::endl;
	}

	//st�ng filen
	write.close();

}


// s�kfunktion
void activities::searchMainIngredient()
{

	bool b_serach = false;
	while (!b_serach)
	{
			std::cout << " Search for: \n [1] Chicken\n [2] Fish\n [3] Meat\n [4] Vegetarian\n [5] Go back" << std::endl;
			std::cin >> answer;
	
		switch (answer[0])
		{
			case '1':
			{
				searchIn("chicken");
				break;
			}
			case '2':
			{
				searchIn("fish");
				break;
			}
			case '3':
			{
				searchIn("meat");
				
				break;
			}
			case '4':
			{
				searchIn("veg");
				break;
			}
			case '5':
			{
				b_serach = true;
				break;
			}
		}
		
	}
}

// slumpa bland alla r�tter
void activities::randomDinner()
{
	// �ven denna g�r kanske att g�ra med templates f�r att kunna slumpa efter kyckling/k�tt osv?


	int random, sizeOfVektor;
	sizeOfVektor = recept.size() - 1; // s� att jag bara f�r tal som finns.

	srand(time(NULL)); // s� att den inte alltid b�rjar p� samma
	random = rand() % sizeOfVektor; 

	std::cout << " --- " << std::endl;
	std::cout << " Your dish is " << recept[random]->get_name() << std::endl;
	std::cout << " --- " << std::endl;

}



// en s�kfunktion, fungerar f�r olika vektorer
void activities::searchIn(std::string x)
{
	found = 0;
	std::cout << "- - - -\n" << std::endl;
	for (int i = 0; i < recept.size() - 1; i++)
	{
		if (recept[i]->get_kategori() == x) {

			std::cout << " * " << recept[i]->get_name() << std::endl;
			found = 1;
		}

	}
	if (found == 0)
	{
		std::cout << " nothing found.." << std::endl;
		found = 1;
	}
	std::cout << "\n- - - -" << std::endl;
}


