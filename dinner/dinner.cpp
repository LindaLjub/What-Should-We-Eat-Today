
#include "pch.h"
#include "activities.h"
#include <iostream>


int main()
{
	setlocale(LC_ALL, "");


	activities go;
	go.getData(); // h�mta in all data
	std::cout << "\n -Hello there hungry! \n -What would you like to do? \n" << std::endl;
	go.mainMenu(); // g� till menyn

}

