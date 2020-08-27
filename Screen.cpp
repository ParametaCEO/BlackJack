#include "Screen.h"
#include <iostream>

Screen::Screen(string strPrompt)
{
    strTextTable = strPrompt;
}

Screen::Screen()
{
    strTextTable = ">";
}


Screen::~Screen()
{
    //dtor
}

string Screen::displayScreen(string val)
{
    cout << val << endl;
    cout << GetstrMessage() << endl;
    cout << GetstrTextTable();
    cin >> strCommand;
    return strCommand;
}
