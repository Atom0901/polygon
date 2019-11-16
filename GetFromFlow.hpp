#pragma once

template <class Number, class Stream>
int getFromFlow(Number &num, Stream &flow){
	flow >> num;
	while (!flow.good()){
		std::cout << "Error. Repeat: ";
		flow.clear();
		flow.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		flow >> num;
	}
	return 1;
}
