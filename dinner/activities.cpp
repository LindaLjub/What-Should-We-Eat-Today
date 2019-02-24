#include "pch.h"
#include "activities.h"
#include <iostream>
#include <fstream> // hämta in data från fil
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

	std::cout << " vector content deleted.. " << std::endl;
}

// sortera efter huvudingrediens
bool text(const recepies *a, const recepies *b)
{
	return a->get_MainIngridient() < b->get_MainIngridient();
};

// hämtar in all data till vektorn.
void activities::getData()
{
	//std::ofstream datafile("dinner.csv"); // skapar en fil med namn "dinner.csv" i samma mapp som programmet.

	// Öppnar filen 
	std::ifstream datafile("dinner.csv");
	std::string name, mainIngredient, addon, kategori;

	// Om filen är öppen, hämta in datum, tid osv. till dess variabler.
	if (datafile.is_open())
	{
		while (!datafile.eof()) // fortsätt så länge som det finns något i datan.
		{
			getline(datafile, name, ':');	// fortsätt till första mellanslag. Tilldela datan till variabeln date.
			getline(datafile, mainIngredient, ',');
			getline(datafile, addon, ',');
			getline(datafile, kategori, '.');

			recept.push_back(new recepies(name, mainIngredient, addon, kategori));
		}

		// Stänger filen när man är färdig med den.
		datafile.close();

	}

}

// en printfunktion, fungerar för olika vektorer
template <typename T, typename U> T printFunc(T inParameter, U swe_lang)
{
	for (int i = 0; i < inParameter.size() - 1; i++)
	{
		if (swe_lang == true)
		{
			std::cout << " Maträtt: " << inParameter[i]->get_name() << std::endl;
			std::cout << " Huvudingrediens: " << inParameter[i]->get_MainIngridient() << std::endl;
			std::cout << " Tillbehör: " << inParameter[i]->get_addon() << std::endl;
			std::cout << " Kategori: " << inParameter[i]->get_kategori() << std::endl;
			std::cout << " --- " << std::endl;
		}
		else
		{
			std::cout << " Dish: " << inParameter[i]->get_name() << std::endl;
			std::cout << " Main ingredient: " << inParameter[i]->get_MainIngridient() << std::endl;
			std::cout << " Addon: " << inParameter[i]->get_addon() << std::endl;
			std::cout << " Category: " << inParameter[i]->get_kategori() << std::endl;
			std::cout << " --- " << std::endl;
		}

	}

	return inParameter;
}

void activities::chooseLang()
{
	bool b_lang = false;
	while (!b_lang)
	{
		std::cout << "--> CHOOSE LANGUAGE" << std::endl;
		std::cout << " [1] English\n [2] Swedish\n [3] Quit" << std::endl;
		std::cin >> answer;

		switch (answer[0])
		{
			case '1':
			{
				b_lang = true;
				swe_lang = false;
				mainMenu();
				break;
			}
			case '2':
			{
				b_lang = true;
				swe_lang = true;
				mainMenu();
				break;
			}
			case '3':
			{
				b_lang = true;
				break;
			}
		}
	}

}

// huvudmeny
void activities::mainMenu()
{
	bool b_main = false;
	while (!b_main)
	{
		if (swe_lang == true)
		{
			std::cout << " [1] Slumpa bland alla rätter\n [2] Sök efter rätter\n [3] Se alla rätter\n [4] Lägg till rätter\n [5] Avsluta" << std::endl;
			std::cin >> answer;
		}
		else
		{
			std::cout << " [1] Get a random dish\n [2] Search for dishes\n [3] See all dishes\n [4] Add dishes\n [5] Quit" << std::endl;
			std::cin >> answer;
		}

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
				printFunc(recept, swe_lang);
				break;
			}
			case '4':
			{
				
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



// sökfunktion
void activities::searchMainIngredient()
{

	bool b_serach = false;
	while (!b_serach)
	{
		if (swe_lang == true)
		{
			std::cout << " Sök efter: \n [1] Kyckling\n [2] Fisk\n [3] Kött\n [4] Vegetariskt\n [5] Tillbaka" << std::endl;
			std::cin >> answer;
		}
		else
		{
			std::cout << " Search for: \n [1] Chicken\n [2] Fish\n [3] Meat\n [4] Vegetarian\n [5] Go back" << std::endl;
			std::cin >> answer;
		}


		switch (answer[0])
		{
			case '1':
			{
				searchIn("kyckling");
				break;
			}
			case '2':
			{
				searchIn("fisk");
				break;
			}
			case '3':
			{
				searchIn("kött");
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

// slumpa bland alla rätter
void activities::randomDinner()
{
	// även denna går kanske att göra med templates för att kunna slumpa efter kyckling/kött osv?


	int random, sizeOfVektor;
	sizeOfVektor = recept.size() - 1; // så att jag bara får tal som finns.

	srand(time(NULL)); // så att den inte alltid börjar på samma
	random = rand() % sizeOfVektor; 

	std::cout << " --- " << std::endl;

	if (swe_lang == true)
	{
		std::cout << " Du ska äta " << recept[random]->get_name() << std::endl;
	}
	else
	{
		std::cout << " Your dish is " << recept[random]->get_name() << std::endl;
	}
	std::cout << " --- " << std::endl;

}



// en sökfunktion, fungerar för olika vektorer
void activities::searchIn(std::string x)
{
	std::cout << "- - - -\n" << std::endl;;
	for (int i = 0; i < recept.size() - 1; i++)
	{
		if (recept[i]->get_kategori() == x) {

			std::cout << " * " << recept[i]->get_name() << std::endl;
		}

	}
	std::cout << "\n- - - -" << std::endl;;
}


