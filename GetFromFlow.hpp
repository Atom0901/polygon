#pragma once
#include <iostream>

template <class Number>
int getFromFlow(Number &num, istream &flow){
	flow >> num;
	while (!flow.good()){
		std::cout << "Error. Repeat: ";
		flow.clear();
		flow.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		flow >> num;
	}
	return 1;
}
