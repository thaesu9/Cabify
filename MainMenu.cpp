#include <iostream>
#include "Cabify.h"

using namespace std;

void ClearScreen()
{
    system("cls");  // to clear the screen
    CabifyLogo();
}

void MainMenu(int* choice)
{
    cout << "\nPlease choose ONE option from below." << endl;
    cout << "(By making a choice, you agree to our terms and conditions.)" << endl << endl;
    cout << "1. Book a Cab. (Customer)" << endl;
    cout << "2. Drive for Cabify. (Driver)" << endl;
    cout << "3. Check Terms and Conditions." << endl;
    cout << "4. Exit." << endl;
    cout << "5. Login as Admin" << endl;

    cout << "\nChoice: ";
    cin >> *choice;

}
