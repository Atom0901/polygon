#include <iostream>
#include "Dialog.hpp"
#include "GetFromFlow.hpp"

using namespace std;

void Dialog::print_line(const string & line){
    cout << line << endl;
}

int Dialog::menu(){
    int ReturnCode = -1;

    cout << "0. exit" << endl;
    cout << "1. make polygon" << endl;
    cout << "2. print polygon" << endl;
    cout << "3. find gravity point" << endl;
    cout << "4. get point by number" << endl;
    cout << "5. rotate around point" << endl;
    cout << "6. move polygon" << endl;
    cout << "7. add point" << endl;

    cout << "Make your choice: --> ";
    while (ReturnCode > 7 || ReturnCode < 0)
    {
        getFromFlow(cin, ReturnCode);
    }
    
    return ReturnCode;
}

void Dialog::MakeItem(Polygon & shape){
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
}

void Dialog::PrintItem(Polygon & shape){
    cout << "First way" << endl;
    cout << shape;
    cout << "Second way" << endl;
    shape.print(cout);
}

void Dialog::GravityItem(Polygon & shape){
    Point gravity_center;
    gravity_center = shape.gravityCenter();
    cout << "Gravity center is :" 
    << setw(10) << gravity_center.getX()
    << setw(10) << gravity_center.getY() << endl;
}

void Dialog::GetPointItem(Polygon & shape){
    cout << "Enter index: ";
    int index;
    Point dot;
    getFromFlow(index, cin);
    try{
        dot = shape[index];
        cout << '(' << index << ')' 
        << setw(10) << dot.getX()
        << setw(10) << dot.getY() << endl;
    }
    catch (const exception &msg)
    {
        cout << msg.what() << endl;
    }
}

void Dialog::RotateItem(Polygon & shape){
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
}

void Dialog::MoveItem(Polygon & shape){
    int x, y;
    cout << "Enter x: ";
    getFromFlow(x, cin);
    cout << "Enter y: ";
    getFromFlow(y, cin);
    shape(Point(x, y));
    cout << shape;
}

void Dialog::AddPointItem(Polygon & shape){
    int x, y;
    cout << "Enter x: ";
    getFromFlow(x, cin);
    cout << "Enter y: ";
    getFromFlow(y, cin);
    shape += Point(x, y);
    cout << shape;
}


