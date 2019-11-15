//
//  tests.h
//  polygon-testing
//
//  Created by Ivan Yakovenko on 17/10/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef tests_h
#define tests_h
#include <iostream>
#include "gtest/gtest.h"
#include "polygon.hpp"

TEST(PolygonEmptyConstructor,DefaultConstructor)
{
	polygon a1;
	ASSERT_EQ(0, a1.get_size());
}
TEST(PolygonPointConstructor,InitConstructors)
{
	point i = {2,3};
	polygon a2(i);
	ASSERT_EQ(1, a2.get_size());
	ASSERT_EQ(i.x, a2[0].x);
	ASSERT_EQ(i.y, a2[0].y);
}
TEST(PolygonArrayConstructor,InitConstructors)
{
	point i[3];
	for(int k = 0; k < 3; k++){
		i[k].x = k + 0.3;
		i[k].y = 2*k + 0.2;
	}
	polygon a2(i, 3);
	ASSERT_EQ(3, a2.get_size());
	ASSERT_EQ(i[0].x, a2[0].x);
	ASSERT_EQ(i[1].x, a2[1].x);
	ASSERT_EQ(i[2].x, a2[2].x);
	ASSERT_EQ(i[0].y, a2[0].y);
	ASSERT_EQ(i[1].y, a2[1].y);
	ASSERT_EQ(i[2].y, a2[2].y);
}
TEST(PolygonCopyConstructor, CopyConstructor)
{
	point i[3];
	for(int k = 0; k < 3; k++){
		i[k].x = k + 0.3;
		i[k].y = 2*k + 0.2;
	}
	polygon a1(i, 3);
	polygon a2(a1);
	ASSERT_EQ(3, a2.get_size());
	ASSERT_EQ(i[0].x, a2[0].x);
	ASSERT_EQ(i[1].x, a2[1].x);
	ASSERT_EQ(i[2].x, a2[2].x);
	ASSERT_EQ(i[0].y, a2[0].y);
	ASSERT_EQ(i[1].y, a2[1].y);
	ASSERT_EQ(i[2].y, a2[2].y);
	
}
TEST(PolygonEqualOperator, EqualOperator)
{
	point i[3];
	point tmp = {5,5};
	for(int k = 0; k < 3; k++){
		i[k].x = k + 0.3;
		i[k].y = 2*k + 0.2;
	}
	polygon a1(i, 3);
	polygon a2 = a1;
	polygon a3(tmp);
	a3 = a1;
	ASSERT_EQ(3, a2.get_size());
	ASSERT_EQ(i[0].x, a2[0].x);
	ASSERT_EQ(i[1].x, a2[1].x);
	ASSERT_EQ(i[2].x, a2[2].x);
	ASSERT_EQ(i[0].y, a2[0].y);
	ASSERT_EQ(i[1].y, a2[1].y);
	ASSERT_EQ(i[2].y, a2[2].y);
	ASSERT_EQ(3, a3.get_size());
	ASSERT_EQ(i[0].x, a3[0].x);
	ASSERT_EQ(i[1].x, a3[1].x);
	ASSERT_EQ(i[2].x, a3[2].x);
	ASSERT_EQ(i[0].y, a3[0].y);
	ASSERT_EQ(i[1].y, a3[1].y);
	ASSERT_EQ(i[2].y, a3[2].y);
}
TEST(PolygonMethodsGravity,Methods)
{
	point i[3];
	for(int k = 0; k < 3; k++){
		i[k].x = k + 0.3;
		i[k].y = 2*k + 0.2;
	}
	polygon a(i, 3);
	point tmp = {1.3,2.2};
	ASSERT_EQ(tmp.x, a.gravity().x);
	ASSERT_EQ(tmp.y, a.gravity().y);
}
TEST(PolygonMethodsAddPoint,Methods)
{
	int o = 10;
	point i[o];
	point tmp = {1.3,2.2};
	for(int k = 0; k < o; k++){
		i[k].x = k;
		i[k].y = 2*k;
	}
	polygon op(i,o);
	ASSERT_NO_THROW(polygon a(i, o));
	ASSERT_NO_THROW(op += tmp);
	ASSERT_EQ(op.get_sz(), o + op.get_quota());
}
TEST(PolygonMethodsGetPoint,Methods)
{
	point i[3];
	point tmp = {1,2};
	for(int k = 0; k < 3; k++){
		i[k].x = k;
		i[k].y = 2*k;
	}
	polygon a(i, 3);
	ASSERT_NO_THROW(a[2]);
	ASSERT_EQ(tmp.x, a[1].x);
	ASSERT_EQ(tmp.y, a[1].y);
	ASSERT_THROW(a[20], std::out_of_range);
}
TEST(PolygonMethodsRotate,Methods)
{
	point i[3];
	int full = 360;
	int g = 90;
	point tmp = {1,2};
	for(int k = 0; k < 3; k++){
		i[k].x = k;
		i[k].y = 2*k;
	}
	i[0].y = 6;
	polygon a(i, 3);
	a(full, tmp);
	ASSERT_EQ(i[0].x, a[0].x);
	ASSERT_EQ(i[1].x, a[1].x);
	ASSERT_EQ(i[2].x, a[2].x);
	ASSERT_EQ(i[0].y, a[0].y);
	ASSERT_EQ(i[1].y, a[1].y);
	ASSERT_EQ(i[2].y, a[2].y);
	a(g, tmp);
	i[0].x = -3;
	i[0].y = 1;
	i[2].x = -1;
	i[2].y = 3;
	ASSERT_EQ(i[0].x, a[0].x);
	ASSERT_EQ(i[1].x, a[1].x);
	ASSERT_EQ(i[2].x, a[2].x);
	ASSERT_EQ(i[0].y, a[0].y);
	ASSERT_EQ(i[1].y, a[1].y);
	ASSERT_EQ(i[2].y, a[2].y);
}
TEST(PolygonMethodsMove,Methods)
{
	point i[3];
	point tmp = {4,2};
	for(int k = 0; k < 3; k++){
		i[k].x = k;
		i[k].y = 2*k;
	}
	i[0].y = 6;
	polygon a(i, 3);
	a(tmp);
	for(int l = 0; l < 3; l++){
		i[l] = {i[l].x + tmp.x, i[l].y + tmp.y};
	}
	ASSERT_EQ(i[0].x, a[0].x);
	ASSERT_EQ(i[1].x, a[1].x);
	ASSERT_EQ(i[2].x, a[2].x);
	ASSERT_EQ(i[0].y, a[0].y);
	ASSERT_EQ(i[1].y, a[1].y);
	ASSERT_EQ(i[2].y, a[2].y);
}

#endif /* tests_h */
