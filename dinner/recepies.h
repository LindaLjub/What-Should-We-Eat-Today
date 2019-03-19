#pragma once
#include <string> // getline, string
#include <iostream>

class recepies
{
private:
	std::string name, mainIngredient, addon, kategori;

public:
	recepies();
	recepies(std::string a, std::string b, std::string c, std::string d) : name(a), mainIngredient(b), addon(c), kategori(d){};
	~recepies();



	// getters

	std::string get_name() const
	{
		return this->name;
	}

	std::string get_MainIngridient() const
	{
		return this->mainIngredient;
	}

	std::string get_addon() const
	{
		return this->addon;
	}

	std::string get_kategori() const
	{
		return this->kategori;
	}
};

