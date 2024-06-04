// Project_Cabify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
using namespace std;

void CabifyLogo()
{
    cout << "                                                                     " << endl;
    cout << "                              ========                               " << endl;
    cout << "                          ___/________\\___                           " << endl;
    cout << "                         /                \\                          " << endl;
    cout << "               _________/                  \\________                " << endl;
    cout << "              /       __   _   __  ___  __ _  _     \\               " << endl;
    cout << "             /      //    /_\\ |__|  |  |__ \\\\//      \\              " << endl;
    cout << "            /       \\\\__ /   \\|__| _|_ |    ||        \\             " << endl;
    cout << "           /     ______                      ______    \\            " << endl;
    cout << "          /_____|      |____________________|      |____\\           " << endl;
    cout << "                |______|                    |______|                 " << endl;
    cout << "=====================================================================" << endl << endl;
}

int main()
{
    CabifyLogo();

    cout << "                         Welcome to CABIFY!                          " << endl;

    cout << "This is Cabify, your Taxi service to make your journey pleasurable..." << endl;

    cout << "Please choose ONE option from below." << endl;
    cout << "(By making a choice, you agree to our terms and conditions.)" << endl << endl;
    cout << "1. Book a Cab. (Customer)" << endl;
    cout << "2. Drive for Cabify. (Driver)" << endl;
    cout << "3. Check Terms and Conditions." << endl;
    cout << "4. Exit." << endl;

    int choice;
    cout << "\nChoice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << endl;
        break;

    case 2:
        cout << endl;
        break;

    case 3:
        cout << endl;
        break;

    case 4:
        cout << endl;
        return 0;

    default:
        cout << "Invalid choice. Please choose again : ";
        break;
    }



}

