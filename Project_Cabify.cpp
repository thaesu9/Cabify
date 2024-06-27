// Project_Cabify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Cabify.h"

using namespace std;

<<<<<<< HEAD
Admin adm;  // admin struct

=======
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac
// check if it is valid date
bool CheckDate(int day, int month, int year)
{
    if (year < 1 || month < 1 || month>12 || day < 1)
        return false;

    int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };  // 0,Jan to Dec

    // leap year, Feb = 29
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        days[2] = 29;

    return day <= days[month]; // day for month
}

<<<<<<< HEAD
// to check for user valid input email
bool validEmail(string& email)
{
    string gmail = "@gmail.com";

    if (email.size() >= gmail.size()  // check if gmail filled is longer than "@gmail.com"
        &&  
        email.compare(email.size() - gmail.size(), gmail.size(), gmail) == 0) // if the email input ends in "@gmail.com"
    {
        return true;
    }
    return false;
}
=======
Admin adm;  // admin struct
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac

int main()
{
    // to clear the file after/for every run
    fstream CustomerFile("customer.txt", ios::out);
    if (CustomerFile.is_open())
    {
        CustomerFile.close();
    }

    // to clear the file after/for every run
    fstream DriverFile("driver.txt", ios::out);
    if (DriverFile.is_open())
    {
        DriverFile.close();
    }

    CabifyLogo();  // display logo
    int choice;

    while (true)
    {        
        MainMenu(&choice);  // main menu with int choice value

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

        case 9:
            // end program
            ClearScreen();
            cout << "Thank you for using Cabify. Have a nice day." << endl;
            cout << endl;
            return 0;

        case 6:
            // login as admin
            if(!adm.attemptFailed)
            {
                ClearScreen();
                adminLogin();
            }
            else
            {
                // if login attempt fail beyond allowed number of attempts
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

