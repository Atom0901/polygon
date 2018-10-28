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

class Polygon
{
private:
	static const int QUOTA = 10;
	int SZ;//маскимальный доступный размер массива
	point *mas;//массив точек
	int size;//текущее число точек в массиве
public:
	Polygon() : size(0), SZ(QUOTA), mas(new point[QUOTA]) {};//пустой конструктор
	Polygon(point one) : size(1), SZ(QUOTA), mas(new point[QUOTA]){mas[0].x = one.x; mas[0].y = one.y;};//конструктор из точки
	Polygon(point *m, int s);//конструктор из массива точек
	Polygon(const Polygon&);//копирующий конструктор
	Polygon(Polygon&&);//перемещающий конструктор
	
	~Polygon(){ delete[] mas; };//деструктор
	
	Polygon &operator =(const Polygon &); //перегруженный оператор присваивания
	Polygon &operator =(Polygon &&);
	Polygon & operator += ( point ne );//оператор добавления точки
	
	point operator [] (int a);//оператор получения координат точки
	point gravity();//вычисление центра тяжести
	Polygon& operator () (int alfa, point x);//оператор поворота многоугольника на угол альфа относительно точки х
	Polygon& operator () (point x);//оператор перемещения многоугольника на вектор х из начала координат
	std::ostream & print (std::ostream & s);//вывод многоугольника списком
	friend std::istream & operator >> (std::istream &, Polygon &);//ввод многоугольника
	friend std::ostream & operator << (std::ostream & s, Polygon & r);//вывод многоугольника по точкам
	int check(int i, int l);//проверка принадлежности вершинам
};


#endif
