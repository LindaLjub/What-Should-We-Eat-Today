#pragma once
#include <vector>
#include "recepies.h"

class activities
{
public:
	activities();
	~activities();

	std::vector<recepies *> recept;


	// funktioner
	void getData(); // funktion som hämtar in data från fil.
	void print();



};

