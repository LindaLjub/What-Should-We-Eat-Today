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
	void getData(); // funktion som h�mtar in data fr�n fil.
	void print();



};

