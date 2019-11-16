#pragma once
#include <string>
#include "Polygon.hpp"
#include <iostream>

class Dialog
{
public:
    Dialog() {};
    void print_line(const string & line);
    int menu();

    void MakeItem(Polygon & shape);
    void PrintItem(Polygon & shape);
    void GravityItem(Polygon & shape);
    void GetPointItem(Polygon & shape);
    void RotateItem(Polygon & shape);
    void MoveItem(Polygon & shape);
    void AddPointItem(Polygon & shape);
};
