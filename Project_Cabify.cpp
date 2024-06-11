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

// vector<Customer> customers; // definition of extern variable

Admin adm;

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
            // customer 
            ClearScreen();
            BookCab();
            break;

        case 2:
            // driver
            ClearScreen();
            DriverMainMenu();
            break;

        case 3:
            // terms and conditions
            ClearScreen();
            TermsConditions();
            break;

        case 4:
            ClearScreen();
            cout << "Thank you for using Cabify. Have a nice day." << endl;
            cout << endl;
            return 0;

        case 0:
            // login as admin
            if(!adm.attemptFailed)
            {
                ClearScreen();
                adminLogin();
            }
            else
            {
                ClearScreen();
                cout << "\n You have reached the maximum number of attempts. Press Enter to go back to main menu." << endl;
                cin.ignore();
                cin.get();
                ClearScreen();
            }
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

