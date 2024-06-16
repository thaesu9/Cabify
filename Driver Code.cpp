// Driver Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Dc.h"
using namespace std;

//void driver_register(){}
//void driver_login)(){}

int main() {
    driver dr;
    int choice;
    cout << "1. Driver basic_Details + elgibility check" << endl;
    cout << "2. Driver Register";
    cout << "\nChoose from the options above" << endl;
    cin >> choice;



    switch (choice)
    {
        {
            case 1:
                cout << "\nBasic details" << endl;
                basic_details();
        }

        {
            case 2:
                cout << "Driver eligibility check ";
                eligibility_check();
        }
        {
            case 3:
                cout << "Driver Register";
                driver_register();
        }

        {
    default:
        cout << "Goodbye!";
        break;
        }
    }
    return 0;
}