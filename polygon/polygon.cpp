//
//  polygon.cpp
//  polygon
//
//  Created by Ivan Yakovenko on 13/10/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "polygon.hpp"

template <class NUMBER, class STREAM>
int get_flow(NUMBER &num, STREAM &flow){
	flow >> num;
	while (!flow.good()){
		std::cout << "repeat: ";
		flow.clear();
		flow.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		flow >> num;
	}
	return 1;
}

Polygon::Polygon(point *m, int s): size(s),SZ(s){
	mas = new point[s];
	for (int i = 0; i < s; i++){
		mas[i].x = m[i].x;
		mas[i].y = m[i].y;
	}
}

Polygon::Polygon(const Polygon& old): size(old.size), SZ(old.SZ){
	mas = new point[old.SZ];
	for (int i = 0; i < old.size; i++){
		mas[i].x = old.mas[i].x;
		mas[i].y = old.mas[i].y;
	}
}

Polygon::Polygon(Polygon&& old): size(old.size), SZ(old.SZ), mas(old.mas){
	old.mas = nullptr;
}

Polygon &Polygon::operator =(const Polygon &st){
	if(this != &st){
		size = st.size;
		SZ = st.SZ;
		delete [] mas;
		mas = new point [SZ];
		for (int i = 0; i < size; ++i){
			mas[i].x = st.mas[i].x;
			mas[i].y = st.mas[i].y;
		}
	}
	return *this;
}

Polygon &Polygon::operator =(Polygon &&old){
	int tmp = size;
	size = old.size;
	old.size = tmp;
	tmp = SZ;
	SZ = old.SZ;
	old.SZ = tmp;
	point *ptr = mas;
	mas = old.mas;
	old.mas = ptr;
	return *this;
}

Polygon & Polygon::operator += ( point ne ){
	if(size >= SZ){
		SZ += QUOTA;
		int c = 0;
		point *another = new point[SZ];
		while (c < size) {
			another[c] = mas[c];
			c++;
		}
		mas = another;
		another = nullptr;
	}
	mas[size].x = ne.x;
	mas[size].y = ne.y;
	size++;
	return *this;
}

point Polygon::operator [] (int a){
	if (a > -1 && a < size)
		return mas[a];
	else
		throw std::out_of_range("There is no such point");
}


point Polygon::gravity(){
	point res = {0,0};
	for(int l = 0; l < size; l++){
		res.x = res.x + mas[l].x;
		res.y = res.y + mas[l].y;
	}
	res.x = res.x / size;
	res.y = res.y / size;
	return res;
}


Polygon& Polygon::operator () (int alfa, point x){
	if(alfa<0)
		alfa = -alfa;
	float PI = 3.14159;
	int cs = cos(alfa*PI/180);
	int sn = sin(alfa*PI/180);
	for(int l = 0; l < size; l++){
		mas[l] = {mas[l].x - x.x, mas[l].y - x.y};
		mas[l] = {mas[l].x*cs - mas[l].y*sn, mas[l].x*sn + mas[l].y*cs};
		mas[l] = {mas[l].x + x.x, mas[l].y + x.y};
	}
	return *this;
}

Polygon& Polygon::operator () (point x){
	for(int l = 0; l < size; l++){
		mas[l] = {mas[l].x + x.x, mas[l].y + x.y};
	}
	return *this;
}

std::istream & operator >> (std::istream & s, Polygon & r) {
		get_flow(r.size, s);
	if (r.size > r.SZ){
			throw std::out_of_range("Too big");
		}else
			for (int k = 0; k < r.size; k++){
				get_flow(r.mas[k].x, s);
				get_flow(r.mas[k].y, s);
			}
		if(s.good()){
			s.setstate(std::ios::failbit);
		}
		return s;
 };

std::ostream & Polygon::print (std::ostream & s) {
	if (size == 0)
		s << "There is no polygon"<< std::endl;
	else
		for(int l = 0; l < size; l++){
			s << '(' << l+1 << ')'
			<< std::setw(10) << mas[l].x
			<< std::setw(10) << mas[l].y
			<< std::endl;
		}
	return s;
}

int Polygon::check(int i, int l){
	for (int y = 0; y < size; y++) {
		if ((mas[y].x == i)&&(mas[y].y == l))
			return 1;
	}
	return 0;
}

std::ostream & operator << (std::ostream & s, Polygon & r) {
	if (r.size == 0)
		s << "There is no polygon"<< std::endl;
	else
		for(int l = 0; l < 21; l++){
			s << std::setw(2) << l-1;
			for (int i = 0; i < 20; i++){
				if (!l)
					s << std::setw(2) << i;
				else{
					if (r.check(i, l))
						s << std::setw(2) << "@";
					else
						s << std::setw(2) << "  ";
				}
			}
			s << std::endl;
		}
	return s;
}

