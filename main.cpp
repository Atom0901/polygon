#include <iostream>
#include "dialog.hpp"
#include "polygon.hpp"

int main(int argc, const char * argv[]) {
	Dialog items;
	
	items.print_line("Hey this is program to test polygons");
	
	Polygon it;
	Point t;
	int c, p = 0, u;

	
	do{
		switch(items.menu()){
		case 1:
				do{
					c = 0;
					try{
						std::cout << "enter number: ";
						std::cin >> it;
					}
					catch (const std::exception &msg)
					{
						std::cout << msg.what() << std::endl;
						c = 1;
					}
				}while(c);
				continue;
		case 2:
				std::cout << it;
                it.print(std::cout);
				continue;
		case 3:
				t = it.gravity();
				std::cout << "gravity center is :" << std::setw(10) << t.x
				<< std::setw(10) << t.y
				<< std::endl;
				continue;
		case 4:
				std::cout << "enter number: ";
				get_flow(u, std::cin);
				try{
					t = it[u];
				}
				catch (const std::exception &msg)
				{
					std::cout << msg.what() << std::endl;
					continue;
				}
				std::cout << '(' << u << ')' << std::setw(10) << t.x
				<< std::setw(10) << t.y
				<< std::endl;
				continue;
		case 5:
				std::cout << "enter x: ";
				get_flow(t.x, std::cin);
				std::cout << "enter y: ";
				get_flow(t.y, std::cin);
				std::cout << "enter angle: ";
				get_flow(u, std::cin);
				it(u, t);
				std::cout << it;
				continue;
		case 6:
				std::cout << "enter x: ";
				get_flow(t.x, std::cin);
				std::cout << "enter y: ";
				get_flow(t.y, std::cin);
				it(t);
				std::cout << it;
				continue;
		case 7:
				std::cout << "enter x: ";
				get_flow(t.x, std::cin);
				std::cout << "enter y: ";
				get_flow(t.y, std::cin);
				it += t;
				std::cout << it;
				continue;
		default:
				std::cout << "thanks" << std::endl;
				break;
		}
	}while(p);
	
	return 0;
}
