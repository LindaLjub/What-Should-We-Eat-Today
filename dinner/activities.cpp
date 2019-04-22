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
	for (int i = 0; i < meat.size(); i++)
	{
		delete meat[i];
	}
	for (int i = 0; i < chicken.size(); i++)
	{
		delete chicken[i];
	}
	for (int i = 0; i < fish.size(); i++)
	{
		delete fish[i];
	}
	for (int i = 0; i < veg.size(); i++)
	{
		delete veg[i];
	}
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
	std::string name, mainIngredient, addon, Category;

	// Om filen �r �ppen, h�mta in datum, tid osv. till dess variabler.
	if (datafile.is_open())
	{
		while (!datafile.eof()) // forts�tt s� l�nge som det finns n�got i datan.
		{
			getline(datafile, name, ',');	// forts�tt till f�rsta mellanslag. Tilldela datan till variabeln date.
			getline(datafile, mainIngredient, ',');
			getline(datafile, addon, ',');
			getline(datafile, Category);

			recept.push_back(new recepies(name, mainIngredient, addon, Category)); 

			if (Category == "meat")
			{
				meat.push_back(new recepies(name, mainIngredient, addon, Category));
			}
			if (Category == "fish")
			{
				fish.push_back(new recepies(name, mainIngredient, addon, Category));
			}
			if (Category == "chicken")
			{
				chicken.push_back(new recepies(name, mainIngredient, addon, Category));
			}
			if (Category == "veg")
			{
				veg.push_back(new recepies(name, mainIngredient, addon, Category));
			}
		}

		// St�nger filen n�r man �r f�rdig med den.
		datafile.close();

	}
	else
	{
		std::cout << " Could not open file.." << std::endl;
	}

}

// en printfunktion, fungerar f�r olika vektorer
template <typename T> T printFunc(T inParameter)
{
	int size = inParameter.size();
	std::cout << "- - - -\n" << std::endl;
	if (size < 1)
	{
		std::cout << " Nothing found!" << std::endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
		std::cout << " Dish: " << inParameter[i]->get_name() << std::endl;
		std::cout << " Main: " << inParameter[i]->get_MainIngridient() << std::endl;
		std::cout << " Addon: " << inParameter[i]->get_addon() << std::endl;
		std::cout << " Category: " << inParameter[i]->get_kategori() << std::endl;
		
		}
	}
	std::cout << "\n- - - -" << std::endl;
	return inParameter;
}

void activities::mainMenu()
{
	bool b_main = false;
	while (!b_main)
	{
			std::cout << " [1] Get a random dish\n [2] Search for dishes\n [3] See a list of available dishes\n [4] Add dishes\n [5] Update list of dishes\n [6] Quit" << std::endl;
			std::cout << " --> "; 
			std::cin >> answer;
			

		switch (answer[0])
		{
			case '1':
			{	
				chooseRandom();
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
				listOfDishes();
				break;
			}
			case '4':
			{
				add();
				break;
			}
			case '5':
			{	
				int size = meat.size();
				for (int i = 0; i < size; i++)
				{
					meat.pop_back();
				}

				size = chicken.size();
				for (int i = 0; i < size; i++)
				{
					chicken.pop_back();
				}

				size = fish.size();
				for (int i = 0; i < size; i++)
				{
					fish.pop_back();
				}

				size = veg.size();
				for (int i = 0; i < size; i++)
				{
					veg.pop_back();
				}

				size = recept.size();
				for (int i = 0; i < size; i++)
				{
					recept.pop_back();
				}

				getData();
				std::cout << " Content updated" << std::endl;
				break;
			}
			case '6':
			{
				b_main = true;
				break;
			}
		}

	}

}

void activities::listOfDishes()
{
	bool b_listD = false;
	while (!b_listD)
	{
		std::cout << "-Which dishes would you like to see? " << std::endl;
		std::cout << " [1] Chicken\n [2] Fish\n [3] Meat\n [4] Vegetarian\n [5] All dishes\n [6] Go back" << std::endl;
		std::cout << " --> ";
		std::cin >> answer;
		switch (answer[0])
		{
			case '1':
			{
				printFunc(chicken);
				break;
			}
			case '2':
			{
				printFunc(fish);
				break;
			}
			case '3':
			{
				printFunc(meat);
				break;
			}
			case '4':
			{
				printFunc(veg);
				break;
			}
			case '5':
			{
				printFunc(recept);
				break;
			}
			case '6':
			{
				b_listD = true;
				break;
			}
		}
	}
}

void activities::chooseRandom()
{
	bool b_chooseR = false;
	while (!b_chooseR)
	{
		std::cout << " -Which category would you like to get a random dish from?\n" 
		<< " [1] Chicken\n [2] Fish\n [3] Meat\n [4] Vegetarian\n [5] All dishes\n [6] Go back" << std::endl;
		std::cout << " --> "; 
		std::cin >> answer;
		switch (answer[0])
		{
			case '1':
			{
				randomDinnerSpec(chicken);
				break;
			}
			case '2':
			{
				randomDinnerSpec(fish);
				break;
			}
			case '3':
			{
				randomDinnerSpec(meat);
				break;
			}
			case '4':
			{	
				randomDinnerSpec(veg);
				break;
			}
			case '5':
			{
				randomDinnerSpec(recept);
				break;
			}
			case '6':
			{
				b_chooseR = true;
				break;
			}
		}
	}
}

void activities::add()
{
	std::string name, main, addon, category;

		std::cout << " Enter the name of the dish (one word only): ";
		std::cin >> name;
		std::cout << " Enter main (ex falukorv, steak):" ;
		std::cin >> main;
		std::cout << " Enter addon (ex. rise, potatoes): " ;
		std::cin >> addon;
		std::cout << " Choose a category: \n [1] Chicken\n [2] Fish\n [3] Meat\n [4] Vegetarian" << std::endl;
		std::cin >> answer;
		switch (answer[0]) {
			case '1':
			{
				category = "chicken";
				break;
			}
			case '2':
			{
				category = "fish";
				break;
			}
			case '3':
			{
				category = "meat";
				break;
			}
			case '4':
			{
				category = "veg";
				break;
			}
		}
		std::cout << " --- " << std::endl;


	// �ppna filen, ios::app betyder, append at end of file. f�r att den bara ska l�gge till text utan att ta bort text
	std::ofstream write;
	write.open("dinner.csv", std::ios::app);

	// Om filen �r �ppen, h�mta in datum, tid osv. till dess variabler.
	if (write.is_open())
	{
		write << name << "," << main << "," << addon << "," << category << "\n";
		std::cout << " " << name << " was added to the list! " << std::endl;
	}
	else
	{
		std::cout << " Could not open file.." << std::endl;
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
		std::cout << " --> "; 
		std::cin >> answer;
	
		switch (answer[0])
		{
			case '1':
			{
				searchIn(chicken);
				break;
			}
			case '2':
			{
				searchIn(fish);
				break;
			}
			case '3':
			{
				searchIn(meat);
				
				break;
			}
			case '4':
			{
				searchIn(veg);
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


// slumpa bland specifika/alla r�tter
template <typename T> T activities::randomDinnerSpec(T inParameter)
{
	// Skicka in en vector beroende p� vilken kategori det �r.

	int random, sizeOfVektor;
	sizeOfVektor = inParameter.size(); // s� att jag bara f�r tal som finns.

	std::cout << "- - - -\n" << std::endl;
	if (sizeOfVektor < 1)
	{
		std::cout << " Nothing found!" << std::endl;

	}
	else
	{ 

	srand(time(NULL)); // s� att den inte alltid b�rjar p� samma
	random = rand() % sizeOfVektor + 0;
	std::cout << " Your dish is " << inParameter[random]->get_name() << ", bon app�tit! " << std::endl;
	}
	std::cout << "\n- - - -" << std::endl;
	return inParameter;
}


// en s�kfunktion, fungerar f�r olika vektorer
template <typename T> T activities::searchIn(T inParameter)
{
	std::cout << "- - - -\n" << std::endl;
	int size = inParameter.size();

	for (int i = 0; i < size; i++)
	{
		std::cout << " * " << inParameter[i]->get_name() << std::endl;

	}
	if (size < 1)
	{
		std::cout << " Nothing found!" << std::endl;
	}
	std::cout << "\n- - - -" << std::endl;

	return inParameter;
}


