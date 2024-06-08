// Project_Cabify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;

vector<Customer> customers; // definition of extern variable


int main()
{

    CabifyLogo();
    int choice;

    while (true)
    {
        MainMenu(&choice);

        switch (choice)
        {
        case 1:
            ClearScreen();
            BookCab();
            cout << endl;
            break;

        case 2:
            // driver
            cout << endl;
            break;

        case 3:
            // terms and conditions
            cout << endl;
            break;

        case 4:
            ClearScreen();
            cout << "Thank you for using Cabify. Have a nice day." << endl;
            cout << endl;
            return 0;

        case 5:
            // login as admin
            cout << endl;
            break;
        default:
            ClearScreen();
            cout << "Invalid choice. Please choose again." << endl;
            cin.clear();
            cin.ignore();
            break;
        }
    }
    
}

