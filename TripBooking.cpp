#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;
vector<Journey> journey;

// function for trip booking
void TripBooking(const string* email)
{
    Journey newTrip;
    srand(static_cast<unsigned>(time(NULL)));
    newTrip.tripID = 1000 + rand() % 9000; // to generate random 4 digit code
    
    cin.ignore();
    cout << " \n Let Cabify take you to your destination." << endl << endl;
    cout << " Enter current location : ";
    getline(cin, newTrip.tripStart);
    cout << " Enter your destination : ";
    getline(cin, newTrip.tripEnd);
    cout << " Booking Date (DD/MM/YYYY) : ";
    getline(cin, newTrip.bookingDate);
    cout << " Booking Time (00:00 am/pm) : ";
    getline(cin, newTrip.bookingTime);
    cout << " Number of Passengers : ";
    cin >> newTrip.passengers;

    // special needs
    int aidChoice;
    while(true)
    {
        cout << "\n Do you need any additional request ? " << endl;
        cout << " 1. No" << endl;
        cout << " 2. I have a baby." << endl;
        cout << " 3. I need special aid. " << endl;  
        cout << " Choice : ";
        cin >> aidChoice;

        if (cin.fail() || (aidChoice != 1 && aidChoice != 2 && aidChoice != 3))
        {
            cin.clear(); // clear input
            cin.ignore(); // discard invalid input
            cout << " Invalid choice. Please enter valid input." << endl << endl;
        }
        else
        {
            break;
        }
    }
    cin.ignore();

    switch (aidChoice)
    {
    case 1:
        newTrip.specialN = SpecialNeeds::none;
        break;
    case 2:
        newTrip.specialN = SpecialNeeds::infant;
        break;
    case 3:
        newTrip.specialN = SpecialNeeds::physicalNeeds;
        break;
    default:
        newTrip.specialN = SpecialNeeds::none;
        break;
    }

    // payment status
    for (const auto& cus : customers)
    {
        if (cus.email == *email)
        {
            newTrip.customerName = cus.firstName;

            if (cus.paymentMethod == 2)
            {
                cout << " Payment Status : Pending" << endl; // customer pay in cash
            }
            else if (cus.paymentMethod == 1)
            {
                cout << " Payment Status : Paid" << endl; // customer paid in card
            }
        }
        
    }   

    cout << "\n Your trip ID : " << newTrip.tripID << endl;


    journey.push_back(newTrip);
    
    // printing bill
    ClearScreen();
    PrintBill(newTrip.tripID);
}

void PrintBill(long int tripID)
{
    for (const auto& trip : journey)
    {
        if (tripID == trip.tripID)
        {
            cout << "\n Your Receipt" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << " Trip ID           : " << trip.tripID << endl;
            cout << " Pick up location  : " << trip.tripStart << endl;
            cout << " Drop off location : " << trip.tripEnd << endl;
            cout << " Booking Date      : " << trip.bookingDate << endl;
            cout << " Booking Time      : " << trip.bookingTime << endl;
            cout << " Total Passengers  : " << trip.passengers << endl;           

            if (trip.specialN == 1)
                cout << " Special Request   : None " << endl << endl;
            else if (trip.specialN == 2)
                cout << " Special Request   : I have a baby " << endl << endl;
            else if (trip.specialN == 3)
                cout << " Special Request   : I need special aid " << endl << endl;
            else
                cout << " Special Request   : None " << endl << endl;

            cout << " Taxi fare : 3 NZD per km" << endl << endl;

            for (const auto& cus : customers)
            {
                if (cus.firstName == trip.customerName)
                {
                    if (cus.paymentMethod == 2)
                    {
                        cout << " Payment Status : Pending" << endl; // customer pay in cash
                        cout << " (Please pay the driver upon arriving your destination.)" << endl;
                    }
                    else if (cus.paymentMethod == 1)
                    {
                        cout << " Payment Status : Paid" << endl; // customer paid in card
                    }
                }

            }
            cout << endl;

            cout << "             Thank you for using Cabify. Have a nice journey." << endl;
            cout << "-----------------------------------------------------------------------------" << endl;

            
        }
    }

    cout << " Press Enter to go back." << endl;
    cin.get();
}

void CancelBooking(const string* email)
{
    Journey newTrip;

    long int tripID;
    cout << "\n Enter trip ID : ";
    cin >> tripID;
    cin.ignore();
    {
        bool found = 0;
        for (auto& trip : journey)
        {
            if (tripID == trip.tripID)
            {
                found = true;
                if (trip.tripStatus == true)
                {
                    cout << "\n Do you want to cancel this trip (Trip ID : " << trip.tripID << ")?" << endl;
                    cout << "\n 1. Yes" << endl;
                    cout << " 2. No" << endl;
                    int choice;
                    cout << " \n Choice : ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        cin.ignore();
                        cout << "\n The trip (Trip ID : " << trip.tripID << ") is cancelled." << endl;
                        cout << "\n Press Enter to go back." << endl;
                        cin.get();
                        trip.tripStatus = false;
                        return;

                    case 2:
                        ClearScreen();
                        return;

                    default:
                        ClearScreen();
                        cout << " Invalid choice. Please choose again : ";
                        break;
                    }
                }
                else
                {
                    cout << "\n The trip (Trip ID : " << trip.tripID << ") is already cancelled." << endl;
                    cin.ignore();
                    cout << "\n Press Enter to go back." << endl;
                    cin.get();
                }
            }
            
        }
        if (!found)
        {
            cout << "\n Trip ID not found.";
            cout << " Press Enter to go back." << endl;
            cin.get();
        }
    }
}