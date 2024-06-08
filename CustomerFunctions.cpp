#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;

vector<Customer> customers; // definition of extern variable

// function for new account


// function - login for existing account
void ExistingAcc()
{
    cin.ignore();

    // find customer by email
    string email;
    cout << "\n Enter your email : ";
    getline(cin, email);

    bool found = 0;
    for (const auto& cus : customers) // find in customers vector using struct
    {
        if (cus.email == email)
        {
            while (true)
            {
                ClearScreen();
                cout << " \n Welcome " << cus.firstName << " .";
                cout << " What can we do for you today? " << endl << endl;
                cout << " 1. Book a cab" << endl;
                cout << " 2. Cancel Booking" << endl;
                cout << " 3. Back" << endl;
                int choice;
                cout << "\n Choice : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    ClearScreen();
                    // book a trip
                    TripBooking();
                    cout << endl;
                    break;

                case 2:
                    //cancel booking
                    cout << endl;
                    break;

                case 3:
                    ClearScreen();
                    return;

                default:
                    ClearScreen();
                    cout << "Invalid choice. Please choose again : ";
                    break;
                }
            }

            found = 1;
            break;
        }
    }
    if (!found)
    {
        ClearScreen();
        cout << " No account found. Please register first." << endl << endl;
        NewAcc();
    }

}

void NewAcc()
{
    Customer newCus;  // call struct
    cout << "\n Customer Registration Page" << endl;
    cout << " ---------------------------" << endl;

    cout << " Email : ";
    cin.ignore(); // clear input buffer
    getline(cin, newCus.email);

    cout << " First Name : ";
    getline(cin, newCus.firstName);   // use getline to read entire line (including space)
    cout << " Last Name : ";
    getline(cin, newCus.lastName);

    newCus.fullName = newCus.firstName + " " + newCus.lastName;  // string concatenation

    cout << " Contact Number : ";
    getline(cin, newCus.phone);

    cout << " Address : ";
    getline(cin, newCus.address);

    cout << " Payment method (Choose, 1 = card, 2 = cash) : ";
    cin >> newCus.paymentMethod;

    if (newCus.paymentMethod == 1)
    {
        cout << " Please enter Visa Card Number : ";
        cin.ignore();
        getline(cin, newCus.visaCard);
        cout << " Visa card expiry date (MM/YY) : ";
        getline(cin, newCus.visaExp);
    }
    else
    {
        newCus.visaCard = "nil";
        newCus.visaExp = "nil";
    }

    customers.push_back(newCus);  // add new customer in vector

    ClearScreen();
    cout << "\n Thank you for joining Cabify. You can now start your journey." << endl;
    cout << "\n Please login to proceed with your booking." << endl;

}


// Booking screen main menu
void BookCab()
{
    while (true)
    {
        cout << "\n Please choose from following options to proceed with your booking." << endl << endl;
        cout << " 1. Register (I'm new customer)" << endl;
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
            NewAcc();
            break;

        case 2:
            ClearScreen();
            ExistingAcc();
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



// function for trip booking
void TripBooking()
{
    srand(time_t(NULL)); // time_t = long long int
    int tripNumber = 100000 + rand() % 900000; // to generate random 6 digit code



    cout << "\nYour trip ID is " << tripNumber << ". " << endl;
}