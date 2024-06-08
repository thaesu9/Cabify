#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;

// function for new account
void NewAcc()
{
    Customer newCus;  // call struct
    cout << "Customer Registration Page" << endl;
    cout << "---------------------------" << endl;

    cout << "First Name : ";
    cin.ignore(); // clear input
    getline(cin, newCus.firstName);   // use getline to read entire line (including space)
    cout << "Last Name : ";
    getline(cin, newCus.lastName);

    newCus.fullName = newCus.firstName + " " + newCus.lastName;  // string concatenation

    cout << "Contact Number : ";
    getline(cin, newCus.phone);

    cout << "Address : ";
    getline(cin, newCus.address);

    cout << "Email : ";
    getline(cin, newCus.email);

    cout << "Payment method (Choose, 1 = card, 2 = cash) : ";
    cin >> newCus.paymentMethod;

    if (newCus.paymentMethod == 1)
    {
        cout << "Please enter Visa Card Number : ";
        cin.ignore();
        getline(cin, newCus.visaCard);
        cout << "Visa card expiry date (MM/YY) : ";
        getline(cin, newCus.visaExp);
    }
    else
    {
        newCus.visaCard = "nil";
        newCus.visaExp = "nil";
    }

    customers.push_back(newCus);  // add new customer in vector

    cout << "\nThank you for joining Cabify. You can now start your journey." << endl;
    cout << "Please login to proceed your booking." << endl;
}


// function for trip booking
void TripBooking()
{
    srand(time_t(NULL));
    int tripNumber = 100000 + rand() % 900000; // to generate random 6 digit code

    cout << "\nYour trip ID is " << tripNumber << ". " << endl;
}


// function - login for existing account
void ExistingAcc()
{
    // find customer by email
    string email;
    cout << "Enter your email : ";
    cin.ignore();
    getline(cin, email);

    bool found = 0;
    for (const auto& cus : customers) // find in customers vector using struct
    {
        if (cus.email == email)
        {
            while (true)
            {
                cout << "What can we do for you today? " << endl;
                cout << "1. Book a cab" << endl;
                cout << "2. Cancel Booking" << endl;
                cout << "3. Back" << endl;
                int choice;
                cout << "\nChoice : ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    // book a trip
                    TripBooking();
                    cout << endl;
                    break;

                case 2:
                    //cancel booking
                    cout << endl;
                    break;

                case 3:
                    return;

                default:
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
        cout << "No account found. Please register first." << endl << endl;
        NewAcc();
    }

}

// Booking screen main menu
void BookCab()
{
    while (true)
    {
        cout << "Booking Screen. \nPlease choose from following options to proceed with your booking." << endl;
        cout << "1. Register (I'm new customer)" << endl;
        cout << "2. Login (I have an account)" << endl;
        cout << "3. Back" << endl;
        cout << "4. Exit" << endl;
        int choiceB;
        cout << "\nChoice: ";
        cin >> choiceB;

        switch (choiceB)
        {
        case 1:
            ClearScreen();
            NewAcc();
            cout << endl;
            break;
        case 2:
            ClearScreen();
            ExistingAcc();
            cout << endl;
            break;
        case 3:
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