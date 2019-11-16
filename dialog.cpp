#include <iostream>
#include "dialog.hpp"
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

