#include "Polygon.hpp"
#include "GetFromFlow.hpp"

using namespace std;

Polygon::Polygon(const Point & one){
	this->points.push_back(one);
}

Polygon::Polygon(const vector<Point> & dots){
	for(auto & dot : dots){
		this->points.push_back(dot);
	}
}

Polygon::Polygon(const Polygon & old){
	for(auto & dot : old.points){
		this->points.push_back(dot);
	}
}

Polygon::Polygon(Polygon && old){
	this->points.swap(old.points);
}

Polygon & Polygon::operator = (const Polygon & another){
	for(auto & dot : another.points){
		this->points.push_back(dot);
	}
	return *this;
}

Polygon & Polygon::operator = (Polygon && old){
	this->points.swap(old.points);
	return *this;
}

Polygon & Polygon::operator += (Point new_point){
	this->points.push_back(new_point);
	return *this;
}

Point Polygon::operator [] (int a){
	if (a > -1 && a < this->points.size())
		return this->points[a];
	else
		throw out_of_range("The index is out of range");
}

float Polygon::area(){
	float result = 0.0;
	for(auto i = 0; i < this->points.size(); i++){
		result += this->points[i].getX() * this->points[i + 1].getY();
		result -= this->points[i + 1].getX() * this->points[i].getY();
	}
	return result / 2;
}

Point Polygon::gravityCenter(){
	Point gravity;
	float _x = 0.0, _y = 0.0, semiresult = 0.0;
	for(auto i = 0; i < this->points.size(); i++){
		semiresult = this->points[i].getX() * this->points[i + 1].getY();
		semiresult -= this->points[i + 1].getX() * this->points[i].getY();
		_x += (this->points[i].getX() + this->points[i + 1].getX())
			* semiresult;
		_y += (this->points[i].getY() + this->points[i + 1].getY())
			* semiresult;
	}

	_x = _x / (6 * this->area());
	_y = _y / (6 * this->area());

	return Point(_x, _y);
}

int Polygon::getAmount(){
	return points.size();
}

Polygon& Polygon::operator () (int angle, Point shift){
	if(angle < 0)
		angle = -angle;
	float _x = 0.0, _y = 0.0;
	float cs = cos(angle * M_PI / 180);
	float sn = sin(angle * M_PI / 180);
	for(auto l = 0; l < this->points.size(); l++){
		_x = this->points[l].getX() - shift.getX();
		_y = this->points[l].getY() - shift.getY();
		_x = _x * cs - _y * sn;
		_y = _x * sn + _y * cs;
		_x = _x + shift.getX();
		_y = _y - shift.getY();
		this->points[l].setX(_x);
		this->points[l].setY(_y);
	}
	return *this;
}

Polygon& Polygon::operator () (Point shift){
	float _x = 0.0, _y = 0.0;
	for(int l = 0; l < this->points.size(); l++){
		_x = this->points[l].getX() + shift.getX();
		_y = this->points[l].getY() + shift.getY();
		this->points[l].setX(_x);
		this->points[l].setY(_y);
	}
	return *this;
}

ostream & Polygon::print (ostream & out) {
	if (this->points.empty())
		out << "There is no polygon"<< endl;
	else
		for(int l = 0; l < this->points.size(); l++){
			out << '(' << l+1 << ')'
			<< setw(10) << this->points[l].getX()
			<< setw(10) << this->points[l].getY()
			<< endl;
		}
	return out;
}

istream & operator >> (istream & in, Polygon & object) {
	int size;
	getFromFlow(size, in);
	float _x, _y;
	for(auto k = 0; k < size; k++){
		getFromFlow(_x, in);
		getFromFlow(_y, in);
		object += Point(_x, _y);
	}
	return in;
}

ostream & operator << (ostream & out, Polygon & object) {
	object.print(out);
	return out;
}
