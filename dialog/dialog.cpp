//
//  dialog.cpp
//  dialog
//
//  Created by Ivan Yakovenko on 15/10/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//
//dialog for programs

#include <iostream>
#include "dialog.hpp"


void dialog::hello(const char *s){
	std::cout << s << std::endl;
}

int dialog::get_int(const char *s, int size){
	int res;
	std::cout << s << std::endl;
	std::cin >> res;
	while (!(res >= 0 && res <= size)  || (!std::cin.good())){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		std::cin >> res;
	}
	return res;
}

float dialog::get_float(const char *s, float size){
	float res;
	std::cout << s << std::endl;
	std::cin >> res;
	while (!(res >= 0 && res <= size)  || (!std::cin.good())){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		std::cout << "Error" << std::endl;
		std::cin >> res;
	}
	return res;
}

int dialog::menu(int N){
	int ReturnCode = 0;
	std::cout << "0. exit\n1. make polygon\n2. print polygon\n3. find gravity point\n4. get point by number\n5. rotate around point\n6. move polygon\n7. add point" << std::endl;
	ReturnCode = dialog::get_int("Make your choice: --> ", N);
	return ReturnCode;
}
