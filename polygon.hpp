#pragma once
#include "Point.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

class Polygon
{
private:
	vector<Point> points;
public:
	Polygon(){};
	Polygon(const Point & one);
	Polygon(const vector<Point> & dots);
	Polygon(const Polygon & old);
	Polygon(Polygon && old);
	
	Polygon & operator = (const Polygon &);
	Polygon & operator = (Polygon &&);
	Polygon & operator += (Point new_point);
	
	Point operator [] (int index);
	Point gravityCenter();
	int getAmount();
	float area();
	Polygon& operator () (int angle, Point shift);
	Polygon& operator () (Point shift);
	ostream & print (ostream & out);
	friend istream & operator >> (istream & in, Polygon & object);
	friend ostream & operator << (ostream & out, Polygon & object);
};
