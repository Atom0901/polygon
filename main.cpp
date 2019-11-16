#include <iostream>
#include "dialog.hpp"
#include "polygon.hpp"
#include "GetFromFlow.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	Dialog items;
	
	enum{EXIT, MAKE, PRINT, GRAVITY, GET, ROTATE, MOVE, ADD};
	
	items.print_line("Hey this is program to test polygons");
	
	Polygon shape;
	bool run = true;
	
	while(run){
		switch(items.menu()){
		case MAKE:
			while(true){
				try{
					cout << "Enter number of apexes: ";
					cin >> shape;
					break;
				}
				catch (const exception &msg)
				{
					cout << msg.what() << endl;
				}
			}
			continue;
		case PRINT:
			cout << "First way" << endl;
			cout << shape;
			cout << "Second way" << endl;
			shape.print(cout);
			continue;
		case GRAVITY:
			Point gravity_center;
			gravity_center = shape.gravityCenter();
			cout << "Gravity center is :" 
			<< setw(10) << gravity_center.getX()
			<< setw(10) << gravity_center.getY() << endl;
			continue;
		case GET:
			cout << "Enter index: ";
			int index;
			Point dot;
			getFromFlow(index, cin);
			try{
				dot = shape[index];
			}
			catch (const exception &msg)
			{
				cout << msg.what() << endl;
				continue;
			}
			cout << '(' << index << ')' 
			<< setw(10) << dot.getX()
			<< setw(10) << dot.getY() << endl;
			continue;
		case ROTATE:
			cout << "Enter x: ";
			float x, y;
			int angle;
			getFromFlow(x, cin);
			cout << "Enter y: ";
			getFromFlow(y, cin);
			cout << "Enter angle: ";
			getFromFlow(angle, cin);
			shape(angle, Point(x, y));
			cout << shape;
			continue;
		case MOVE:
			int x, y;
			cout << "Enter x: ";
			getFromFlow(x, cin);
			cout << "Enter y: ";
			getFromFlow(y, cin);
			shape(Point(x, y));
			cout << shape;
			continue;
		case ADD:
			int x, y;
			cout << "Enter x: ";
			getFromFlow(x, cin);
			cout << "Enter y: ";
			getFromFlow(y, cin);
			shape += Point(x, y);
			cout << shape;
			continue;
		default:
			cout << "Thanks" << endl;
			run = false;
			break;
		}
	}
	
	return 0;
}
