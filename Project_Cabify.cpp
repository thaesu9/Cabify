// Project_Cabify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

enum SpecialNeeds { infant = 1, physicalNeeds };

enum Luggage { normal = 1, heavy };

enum paymentStatus { paid = 1, pending };

//structs
struct Customer
{
    string firstName;
    string lastName;
    string fullName;
    string email;
    string address;
    string phone;
    int paymentMethod;
    string visaCard;
    string visaExp;
};

vector<Customer> customers; // store customers information in vector

struct Journey
{
    string tripStart;
    string tripEnd;
    string bookingDate;
    string bookingTime;
    int passengers;
    SpecialNeeds specialN;
    Luggage luggage;
    paymentStatus payStatus;
};


// function to print logo
void CabifyLogo()
{
    cout << " " << endl;
    cout << "                                ========                                     " << endl;
    cout << "                            ___/________\\___                                 " << endl;
    cout << "                           /                \\                                " << endl;
    cout << "                 _________/                  \\________                " << endl;
    cout << "                /       __   _   __  ___  __ _  _     \\               " << endl;
    cout << "               /      //    /_\\ |__|  |  |__ \\\\//      \\              " << endl;
    cout << "              /       \\\\__ /   \\|__| _|_ |    ||        \\             " << endl;
    cout << "             /     ______                      ______    \\            " << endl;
    cout << "            /_____|      |____________________|      |____\\           " << endl;
    cout << "                  |______|                    |______|                 " << endl;
    cout << "=============================================================================" << endl << endl;

    cout << "                            Welcome to CABIFY!                          " << endl;

    cout << "   This is Cabify, your Taxi service to make your journey pleasurable..." << endl;
    cout << "\n=============================================================================" << endl;
}

void MainMenu(int* choice)
{
    cout << "\nPlease choose ONE option from below." << endl;
    cout << "(By making a choice, you agree to our terms and conditions.)" << endl << endl;
    cout << "1. Book a Cab. (Customer)" << endl;
    cout << "2. Drive for Cabify. (Driver)" << endl;
    cout << "3. Check Terms and Conditions." << endl;
    cout << "4. Exit." << endl;

    cout << "\nChoice: ";
    cin >> *choice;
}


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

void TripBooking()
{
    srand(time(NULL));
    int tripNumber = 100000 + rand() % 900000; // to generate random 6 digit code

    cout << "\nYour trip ID is " << tripNumber << ". " << endl;
}

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
            while(true)
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

void BookCab()
{ 
    while(true)
    {
        cout << "Booking Screen. \nPlease choose from following options to proceed with your booking." << endl;
        cout << "1. I'm new customer." << endl;
        cout << "2. I have an account. Let's book a trip." << endl;
        cout << "3. Back" << endl;
        int choiceB;
        cout << "\nChoice: ";
        cin >> choiceB;

        switch (choiceB)
        {
        case 1:
            NewAcc();
            cout << endl;
            break;
        case 2:
            ExistingAcc();
            cout << endl;
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Please choose again : ";
            break;
        }
    }
}

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
            cout << "Thank you for using Cabify. Have a nice day." << endl;
            cout << endl;
            return 0;

        case 5:
            // login as admin
            cout << endl;
            break;
        default:
            cout << "Invalid choice. Please choose again : ";
            break;
        }
    }
    
}

