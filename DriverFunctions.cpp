#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;

vector<Driver> drivers;

// function for new driver account
void NewDriverAcc()
{
    Driver newDriver;
    cout << "\n Thank you for choosing to drive with Cabify. \n Please fill out the form to proceed with your registration." << endl << endl;
    cout << " Enter your age : ";
    int age;
    cin >> age;
    if (age < 18 || age > 80)
    {
        cout << "\n Sorry. You cannot register as our driver. You did not meet the age requirement. " << endl;
        cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;     // go back to main menu   
    }
    else
    {
        newDriver.age = age;
    }
    
    cout << " How many years of driving experience do you have? : ";
    int exp;
    cin >> exp;
    int n = age - exp;
    if (n < 17)
    {
        cout << "\n Your age and years of driving experience is irrelevant. You did not meet the requirement." << endl;
        cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;
    }
    else
    {
        newDriver.drivingExp = exp;
    }
    
    ClearScreen();
    // registration start
    cout << "\n Kia ora. Please fill out the following form to continue your registration." << endl;

    cin.ignore();
    while (true)
    {
        cout << " Email : ";
        getline(cin, newDriver.email);

        bool emailExists = false;
        for (const auto& customer : customers)
        {
            if (newDriver.email == customer.email)
            {
                emailExists = true;
                break;
            }
        }

        if (emailExists)
        {
            ClearScreen();
            cout << "\n The email already exists. Please try another email." << endl;
            cout << "\n Kia ora. Please fill out the following form to continue your registration." << endl;

        }
        else
        {
            break; // if email is unique, exit
        }
    }
    cout << " First Name : ";
    getline(cin, newDriver.firstName);   // use getline to read entire line (including space)
    cout << " Last Name : ";
    getline(cin, newDriver.lastName);

    newDriver.fullName = newDriver.firstName + " " + newDriver.lastName;  // string concatenation

    cout << " Contact Number : ";
    getline(cin, newDriver.phone);

    cout << " Address : ";
    getline(cin, newDriver.address);

    drivers.push_back(newDriver);

    cin.ignore();
    cout << "\n Press Enter to go back." << endl;
    cin.get();
    ClearScreen();
}

void ExistingDriverAcc()
{
    cout << "Existing driver acc" << endl;
}

void DriverMainMenu()
{
    while (true)
    {
        cout << "\n Kia Ora. Please choose from following options to proceed." << endl << endl;
        cout << " 1. Register (I'm new driver)" << endl;
        cout << " 2. Login (I have an account)" << endl;
        cout << " 3. Back" << endl;
        cout << " 4. Exit" << endl;
        int choiceB;
        cout << "\n Choice: ";
        cin >> choiceB;

        switch (choiceB)
        {
        case 1:
            ClearScreen();
            NewDriverAcc();
            break;

        case 2:
            ClearScreen();
            ExistingDriverAcc();
            break;

        case 3:
            // return to main menu
            ClearScreen();
            return;

        case 4:
            ClearScreen();
            cout << "\nThank you for using Cabify. Please come again." << endl;
            exit(0); // to entire exit and end the program
            break;

        default:
            ClearScreen();
            cout << "Invalid choice. Please choose again : " << endl;
            break;
        }
    }
}