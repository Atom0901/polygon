//
//  polygon.hpp
//  polygon
//
//  Created by Ivan Yakovenko on 13/10/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef polygon_
#define polygon_
#include <iostream>
#include <iomanip>




struct point{
	float x, y;
	point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
};


template <class NUMBER, class STREAM>
int get_flow(NUMBER &num, STREAM &flow);

class polygon
{
private:
	static const int QUOTA = 10;
	int SZ;
	point *mas;
	int size;
public:
	polygon() : size(0), SZ(QUOTA), mas(new point[QUOTA]) {};//DONE
	polygon(point one) : size(1), SZ(QUOTA), mas(new point[QUOTA]){mas[0].x = one.x; mas[0].y = one.y;};//DONE
	polygon(point *m, int s);//DONE
	
	polygon(const polygon&);//копирующий конструктор, DONE
	polygon(polygon&&);//перемещающий конструктор, DONE
	
	~polygon(){ delete[] mas; };//деструктор, DONE
	polygon &operator =(const polygon &); //перегруженный оператор присваивания, DONE
	polygon &operator =(polygon &&);//пермещающий оператор присваивания, DONE
	
//	polygon & operator +=(const polygon &);// копирование одного многоугольника в другой
//	polygon & operator ()(polygon &);// перемещение из одного многоугольника в другой
	
	//polygon& add_point(point a);//has test
	polygon & operator += ( point ne );//DONE
	
	point operator [] (int a);//DONE
	//point get_point(int a);//has test
	
	point gravity();//has test, DONE
	
	polygon& operator () (int alfa, point x);//DONE
	//polygon& rotate(int angle, point x);//has test
	
	polygon& operator () (point x);//DONE
	//polygon& move(point x);//has test
	
	int get_sz(){return SZ;};//DONE
	friend std::istream & operator >> (std::istream &, polygon &);//DONE
	friend std::ostream & operator << (std::ostream & s, polygon & r);//DONE
	
	//for tests
	int get_size() {return size;};//DONE
	int get_quota() {return QUOTA;};//DONE
};


#endif
