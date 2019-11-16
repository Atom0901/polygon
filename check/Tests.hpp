#pragma once
#include <iostream>
#include "gtest/gtest.h"
#include "../polygon.hpp"

TEST(PolygonEmptyConstructor,DefaultConstructor)
{
	Polygon a1;
	ASSERT_EQ(0, a1.getAmount());
}
TEST(PolygonPointConstructor,InitConstructors)
{
	Point i(2,3);
	Polygon a2(i);
	ASSERT_EQ(1, a2.getAmount());
	ASSERT_EQ(i.getX(), a2[0].getX());
	ASSERT_EQ(i.getY(), a2[0].getY());
}
TEST(PolygonArrayConstructor,InitConstructors)
{
	vector<Point> i;
	Point tmp;
	for(int k = 0; k < 3; k++){
		tmp.setX(k + 0.3);
		tmp.setY(2*k + 0.2);
		i.push_back(tmp);
	}
	Polygon a2(i);
	ASSERT_EQ(3, a2.getAmount());
	ASSERT_EQ(i[0].getX(), a2[0].getX());
	ASSERT_EQ(i[0].getY(), a2[0].getY());
	ASSERT_EQ(i[1].getX(), a2[1].getX());
	ASSERT_EQ(i[1].getY(), a2[1].getY());
	ASSERT_EQ(i[2].getX(), a2[2].getX());
	ASSERT_EQ(i[2].getY(), a2[2].getY());
}
TEST(PolygonCopyConstructor, CopyConstructor)
{
	vector<Point> i;
	Point tmp;
	for(int k = 0; k < 3; k++){
		tmp.setX(k + 0.3);
		tmp.setY(2*k + 0.2);
		i.push_back(tmp);
	}
	Polygon a1(i);
	Polygon a2(a1);
	ASSERT_EQ(3, a2.getAmount());
	ASSERT_EQ(i[0].getX(), a2[0].getX());
	ASSERT_EQ(i[0].getY(), a2[0].getY());
	ASSERT_EQ(i[1].getX(), a2[1].getX());
	ASSERT_EQ(i[1].getY(), a2[1].getY());
	ASSERT_EQ(i[2].getX(), a2[2].getX());
	ASSERT_EQ(i[2].getY(), a2[2].getY());
	
}
TEST(PolygonEqualOperator, EqualOperator)
{
	vector<Point> i;
	Point tmp;
	for(int k = 0; k < 3; k++){
		tmp.setX(k + 0.3);
		tmp.setY(2*k + 0.2);
		i.push_back(tmp);
	}
	tmp.setX(5);
	tmp.setY(5);
	Polygon a1(i);
	Polygon a2 = a1;
	Polygon a3(tmp);
	a3 = a1;
	ASSERT_EQ(3, a2.getAmount());
	ASSERT_EQ(i[0].getX(), a2[0].getX());
	ASSERT_EQ(i[0].getY(), a2[0].getY());
	ASSERT_EQ(i[1].getX(), a2[1].getX());
	ASSERT_EQ(i[1].getY(), a2[1].getY());
	ASSERT_EQ(i[2].getX(), a2[2].getX());
	ASSERT_EQ(i[2].getY(), a2[2].getY());
	ASSERT_EQ(3, a2.getAmount());
	ASSERT_EQ(i[0].getX(), a3[0].getX());
	ASSERT_EQ(i[0].getY(), a3[0].getY());
	ASSERT_EQ(i[1].getX(), a3[1].getX());
	ASSERT_EQ(i[1].getY(), a3[1].getY());
	ASSERT_EQ(i[2].getX(), a3[2].getX());
	ASSERT_EQ(i[2].getY(), a3[2].getY());
}
// TEST(PolygonMethodsGravity,Methods)
// {
// 	Point i[3];
// 	for(int k = 0; k < 3; k++){
// 		i[k].x = k + 0.3;
// 		i[k].y = 2*k + 0.2;
// 	}
// 	Polygon a(i, 3);
// 	Point tmp = {1.3,2.2};
// 	ASSERT_EQ(tmp.x, a.gravity().x);
// 	ASSERT_EQ(tmp.y, a.gravity().y);
// }
TEST(PolygonMethodsAddPoint,Methods)
{
	vector<Point> i;
	Point tmp(1.3,2.2);
	Point dot;
	for(int k = 0; k < 10; k++){
		dot.setX(k);
		dot.setY(2*k);
		i.push_back(dot);
	}
	Polygon op(i);
	ASSERT_NO_THROW(Polygon a(i));
	ASSERT_NO_THROW(op += tmp);
	ASSERT_EQ(op.getAmount(), 11);
}
TEST(PolygonMethodsGetPoint,Methods)
{
	vector<Point> i;
	Point tmp(1,2);
	Point dot;
	for(int k = 0; k < 3; k++){
		dot.setX(k);
		dot.setY(2*k);
		i.push_back(dot);
	}
	Polygon a(i);
	ASSERT_NO_THROW(a[2]);
	ASSERT_EQ(tmp.getX(), a[1].getX());
	ASSERT_EQ(tmp.getY(), a[1].getY());
	ASSERT_THROW(a[20], std::out_of_range);
}
TEST(PolygonMethodsRotate,Methods)
{
	vector<Point> i;
	int full = 360;
	int g = 90;
	Point tmp(1,2);
	Point dot;
	for(int k = 0; k < 3; k++){
		dot.setX(k);
		dot.setY(2*k);
		i.push_back(dot);
	}
	i[0].setY(6);
	Polygon a(i);
	a(full, tmp);
	ASSERT_EQ(i[0].getX(), a[0].getX());
	ASSERT_EQ(i[0].getY(), a[0].getY());
	ASSERT_EQ(i[1].getX(), a[1].getX());
	ASSERT_EQ(i[1].getY(), a[1].getY());
	ASSERT_EQ(i[2].getX(), a[2].getX());
	ASSERT_EQ(i[2].getY(), a[2].getY());
	a(g, tmp);
	i[0].setX(-3);
	i[0].setY(1);
	i[2].setX(-1);
	i[2].setY(3);
	ASSERT_EQ(i[0].getX(), a[0].getX());
	ASSERT_EQ(i[0].getY(), a[0].getY());
	ASSERT_EQ(i[1].getX(), a[1].getX());
	ASSERT_EQ(i[1].getY(), a[1].getY());
	ASSERT_EQ(i[2].getX(), a[2].getX());
	ASSERT_EQ(i[2].getY(), a[2].getY());
}
TEST(PolygonMethodsMove,Methods)
{
	vector<Point> i;
	Point tmp = {4,2};
	Point dot;
	for(int k = 0; k < 3; k++){
		dot.setX(k);
		dot.setY(2*k);
		i.push_back(dot);
	}
	i[0].setY(6);
	Polygon a(i);
	a(tmp);
	for(int l = 0; l < 3; l++){
		i[l].setX(i[l].getX() + tmp.getX());
		i[l].setY(i[l].getY() + tmp.getY());
	}
	ASSERT_EQ(i[0].getX(), a[0].getX());
	ASSERT_EQ(i[0].getY(), a[0].getY());
	ASSERT_EQ(i[1].getX(), a[1].getX());
	ASSERT_EQ(i[1].getY(), a[1].getY());
	ASSERT_EQ(i[2].getX(), a[2].getX());
	ASSERT_EQ(i[2].getY(), a[2].getY());
}
