#pragma once
#include <string> // getline, string
#include <iostream>

class recepies
{
private:
	std::string name, mainIngredient;


public:
	recepies();
	recepies(std::string a, std::string b) : name(a), mainIngredient(b){};
	~recepies();



	// getters

	std::string get_name()
	{
		return this->name;
	}

	std::string get_MainIngridient()
	{
		return this->mainIngredient;
	}
};

