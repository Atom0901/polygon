#include <iostream>
#include "dialog.hpp"
#include "polygon.hpp"

using namespace std;

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
						cout << "enter number: ";
						cin >> it;
					}
					catch (const exception &msg)
					{
						cout << msg.what() << endl;
						c = 1;
					}
				}while(c);
				continue;
		case 2:
				cout << it;
                it.print(cout);
				continue;
		case 3:
				t = it.gravity();
				cout << "gravity center is :" << setw(10) << t.x
				<< setw(10) << t.y
				<< endl;
				continue;
		case 4:
				cout << "enter number: ";
				get_flow(u, cin);
				try{
					t = it[u];
				}
				catch (const exception &msg)
				{
					cout << msg.what() << endl;
					continue;
				}
				cout << '(' << u << ')' << setw(10) << t.x
				<< setw(10) << t.y
				<< endl;
				continue;
		case 5:
				cout << "enter x: ";
				get_flow(t.x, cin);
				cout << "enter y: ";
				get_flow(t.y, cin);
				cout << "enter angle: ";
				get_flow(u, cin);
				it(u, t);
				cout << it;
				continue;
		case 6:
				cout << "enter x: ";
				get_flow(t.x, cin);
				cout << "enter y: ";
				get_flow(t.y, cin);
				it(t);
				cout << it;
				continue;
		case 7:
				cout << "enter x: ";
				get_flow(t.x, cin);
				cout << "enter y: ";
				get_flow(t.y, cin);
				it += t;
				cout << it;
				continue;
		default:
				cout << "thanks" << endl;
				break;
		}
	}while(p);
	
	return 0;
}
