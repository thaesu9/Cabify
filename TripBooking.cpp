#include <iostream>
#include <string>
#include <sstream> // istringstream
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;
vector<Journey> journey;
// vector<Driver> drivers;

// function for trip booking
void TripBooking(const string* email)
{
    Journey newTrip;  // journey struct
    srand(static_cast<unsigned>(time(NULL)));  // function for random number generation

    vector<int> num;   // vector to keep track of unique num generated
    int randomNum;
    bool unique;       // boolean to check number uniqueness

    do {
        unique = true;
        randomNum = 1000 + rand() % 9000;  // generate random 4 digit code

        // check if the generated random number is already present in the 'num' vector
        if (find(num.begin(), num.end(), randomNum) != num.end())
        {
            // if the number is found in the vector, set the boolean to false
            unique = false;
        }
    } while (!unique);  // repeat until the number is not unique

    num.push_back(randomNum);   // put the unique random number in 'num' vector
    newTrip.tripID = randomNum; // assign that unique number as trip ID
    
    cin.ignore();
    cout << " \n Let Cabify take you to your destination." << endl << endl;
    cout << " Enter current location : ";
    getline(cin, newTrip.tripStart);
    cout << " Enter your destination : ";
    getline(cin, newTrip.tripEnd);

    while (true)
    {
        string date;
        cout << " Booking Date (DD/MM/YYYY) : ";
        getline(cin, date);

        // Create an istringstream object for parsing the date
        istringstream Date(date);
        int dd, mm, yyyy;
        char slash1, slash2;

        // Parse the date into day, month, year separated by '/'
        if (Date >> dd >> slash1 >> mm >> slash2 >> yyyy)
        {
            if (yyyy < 2024 || yyyy > 2024)
            {
                cout << " Invalid date. Please fill again." << endl << endl;
            }

            // Check if the slashes are in correct positions and date is valid
            else if (slash1 == '/' && slash2 == '/' && CheckDate(dd, mm, yyyy))
            {
                newTrip.bookingDate = to_string(dd) + "/" + to_string(mm) + "/" + to_string(yyyy);
                break;
            }
            else
            {
                cout << " Invalid date. Please fill again." << endl << endl;
            }

            
        }
    }
    
    cout << " Booking Time (00:00 am/pm) : ";
    getline(cin, newTrip.bookingTime);

    while(true)
    {
<<<<<<< HEAD
        while (true)
        {
            cout << " Number of Passengers : ";
            cin >> newTrip.passengers;

            if (cin.fail()) // if the user accidently input the invalid datatype
            {
                cin.clear();
                cin.ignore();
                cout << " Invalid input. Please choose again." << endl << endl;
            }
            else
                break;
        }       
=======
        cout << " Number of Passengers : ";
        cin >> newTrip.passengers;
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac

        // if number of passenger is more than 6
        if (newTrip.passengers > 6)
        {
            cout << " Too many passengers. Please choose again." << endl << endl;
        }
        // if the number of passenger is less than 1
        else if (newTrip.passengers < 1)
        {
            cout << " Invalid. Please choose again." << endl << endl;
        }
        else
        {
            break;
        }
    }
    
    while (true)
    {
<<<<<<< HEAD
        while (true)
        {
            cout << " Number of Luggages : ";
            cin >> newTrip.luggage;

            if (cin.fail()) // if the user accidently input the invalid datatype
            {
                cin.clear();
                cin.ignore();
                cout << " Invalid input. Please choose again." << endl << endl;
            }
            else
                break;
        }
        
=======
        cout << " Number of Luggages : ";
        cin >> newTrip.luggage;
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac

        // if the number of luggages of more than 8
        if (newTrip.luggage > 8)
        {
            cout << " Too many passengers. Please choose again." << endl << endl;
        }
        // if the number of luggages if less than 0
        else if (newTrip.luggage < 0)
        {
            cout << " Invalid customer. Please choose again." << endl << endl;
        }
        else
        {
            break;
        }
    }

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

        // if the user input fails or the user choice is not equal to either 1,2 or 3
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
    cin.ignore(); // ignore or discard character from input buffer

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
    for (const auto& cus : customers) // search from customer vector
    {
        if (cus.email == *email)
        {
            newTrip.customerName = cus.firstName;

            if (cus.paymentMethod == 2)  // if the customer chose payment method as 2
            {
                cout << " Payment Status : Pending" << endl; // customer pay in cash
                newTrip.payStatus = false;
            }
            else if (cus.paymentMethod == 1) // if the customer chose payment method as 1
            {
                cout << " Payment Status : Paid" << endl; // customer paid in card
                newTrip.payStatus = true;
            }
        }
        
    }   

    // show customer trip ID
    cout << "\n Your trip ID : " << newTrip.tripID << endl;

    journey.push_back(newTrip); // push back (store) new trip information to 'journey' vector
    
    // printing bill
    ClearScreen();
    PrintBill(newTrip.tripID);
}

// function to print bill for customer
void PrintBill(long int tripID)
{
    for (const auto& trip : journey) // search through journey vector
    {
        if (tripID == trip.tripID)
        {
            cout << "\n Your Receipt" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << " Trip ID           : " << trip.tripID << endl;            
            
            if (!trip.driverstatus) // if the trip is not assigned to driver yet
            {
                cout << " Driver Name       : searching for driver...." << endl;
                cout << " Cab Plate Number  : searching for driver...." << endl;
            }
            else // if the trip has been assigned to driver, display with relevant driver information
            {
                cout << " Driver Name       : " << trip.driverName << endl;
                cout << " Cab Plate Number  : " << trip.licensePlate << endl;
            }

            cout << " Pick up location  : " << trip.tripStart << endl;
            cout << " Drop off location : " << trip.tripEnd << endl;
            cout << " Booking Date      : " << trip.bookingDate << endl;
            cout << " Booking Time      : " << trip.bookingTime << endl;
            cout << " Total Passengers  : " << trip.passengers << endl;        
            cout << " Total Luggages    : " << trip.luggage << endl;

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

// function for customer booking cancel
void CancelBooking(const string* email)
{
    Journey newTrip;

    long int tripID;

    // search with trip ID
<<<<<<< HEAD
    while (true)
    {
        cout << "\n Enter trip ID : ";
        cin >> tripID;

        if (cin.fail()) // if the user accidently input the invalid datatype
        {
            cin.clear();
            cin.ignore();
            cout << " Invalid input. Please choose again." << endl;
        }
        else
            break;
    }
    
=======
    cout << "\n Enter trip ID : ";
    cin >> tripID;
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac
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
<<<<<<< HEAD
                    while (true)
                    {
                        cout << "\n Choice: ";
                        cin >> choice;

                        if (cin.fail() || choice !=1 && choice !=2) // if the user accidently input the invalid datatype
                        {
                            cin.clear();
                            cin.ignore();
                            cout << " Invalid input. Please choose again." << endl;
                        }
                        else
                            break;
                    }
=======
                    cout << " \n Choice : ";
                    cin >> choice;
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac

                    switch (choice)
                    {
                    case 1:
                        // customer cancels the trip, change trip status to cancelled(false)
                        cin.ignore();
                        cout << "\n The trip (Trip ID : " << trip.tripID << ") is cancelled." << endl;
                        cout << "\n Press Enter to go back." << endl;
                        cin.get();
                        trip.tripStatus = false;
                        return;

                    case 2:
                        // customer chose not to cancel the trip
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
        // if the trip ID is not found
        if (!found)
        {
            cout << "\n Trip ID not found.";
            cout << " Press Enter to go back." << endl;
            cin.get();
        }
    }
}

// function to assign driver to available (unassigned trip)
void DriverDriveNow(const string* email)
{
    cin.ignore();
    // check for available trips
    bool tripsAvailable = false;
    for (auto& trip : journey)  // search through journey vector 
    {
        if (!tripsAvailable && trip.tripStatus)  // if the trip status is available (true) and trip is available(true)
        {
            ClearScreen();
            // display all available trip information 1 by 1

            cout << "\n Available Trip Information " << endl;
            cout << " ------------------------------------" << endl;
            cout << " Trip ID              : " << trip.tripID << endl;
            cout << "\n Customer Name        : " << trip.customerName << endl;
            cout << " Pick Up Location     : " << trip.tripStart << endl;
            cout << " Drop Off Location    : " << trip.tripEnd << endl;
            cout << " Booking Date         : " << trip.bookingDate << endl;
            cout << " Booking Time         : " << trip.bookingTime << endl;
            cout << " Number of Passengers : " << trip.passengers << endl;
            cout << " Number of Luggages   : " << trip.luggage << endl;

            if (trip.specialN == 1)
                cout << " Special Request      : None " << endl << endl;
            else if (trip.specialN == 2)
                cout << " Special Request      : Passenger has a baby " << endl << endl;
            else if (trip.specialN == 3)
                cout << " Special Request      : Passenger needs special aid " << endl << endl;
            else
                cout << " Special Request      : None " << endl << endl;

            int choice;
            cout << "\n Accept the trip? : " << endl;
            cout << "\n 1. Yes " << endl;
            cout << " 2. No" << endl;
            cout << " 0. Back" << endl;
<<<<<<< HEAD
            while (true)
            {
                cout << "\n Choice: ";
                cin >> choice;

                if (cin.fail()) // if the user accidently input the invalid datatype
                {
                    cin.clear();
                    cin.ignore();
                    cout << " Invalid input. Please choose again." << endl;
                }
                else
                    break;
            }
=======
            cout << "\n Choice : ";
            cin >> choice;
>>>>>>> 2aef44af26f10fe1e0d9a8c5a63321d6359b9fac

            switch (choice)
            {
            case 1:
                // driver accepts the trip

                trip.assigned = true;     // trip assigned to driver
                tripsAvailable = true;    // trip not available for other drivers
                trip.driverstatus = true; // driver status assigned

                ClearScreen();
                cout << "\n You have accepted the trip." << endl;
                cout << "\n Your Trip Information " << endl;
                cout << " ------------------------------------" << endl;
                cout << " Trip ID              : " << trip.tripID << endl;
                cout << "\n Customer Name        : " << trip.customerName << endl;
                cout << " Pick Up Location     : " << trip.tripStart << endl;
                cout << " Drop Off Location    : " << trip.tripEnd << endl;
                cout << " Booking Date         : " << trip.bookingDate << endl;
                cout << " Booking Time         : " << trip.bookingTime << endl;
                cout << " Number of Passengers : " << trip.passengers << endl;
                cout << " Number of Luggages   : " << trip.luggage << endl;

                if (trip.specialN == 1)
                    cout << " Special Request      : None " << endl << endl;
                else if (trip.specialN == 2)
                    cout << " Special Request      : Passenger has a baby " << endl << endl;
                else if (trip.specialN == 3)
                    cout << " Special Request      : Passenger needs special aid " << endl << endl;
                else
                    cout << " Special Request      : None " << endl << endl;

                if (trip.payStatus == true)
                    cout << " Payment Status       : Paid " << endl << endl;
                else
                    cout << " Payment Status       : Pending (Please collect from the customer.) " << endl << endl;

                // assigning to certain driver ID
                for (auto& driver : drivers)
                {
                    if (driver.email == *email)
                    {
                        trip.driverID = driver.driverID;
                        trip.driverName = driver.firstName;
                        trip.licensePlate = driver.licensePlate;
                    }
                }

                cin.ignore();
                cout << " Press Enter to go back." << endl;
                cin.get();
                break;

            case 2:
                // driver chose not to accept the trip
                cout << "\n Press Enter to go back." << endl;
                cin.get();
                break;

            case 0:
                // return
                ClearScreen();
                return;

            default:
                ClearScreen();
                cout << "Invalid choice. Please choose again : ";
                break;

            }  
        }
    }
    // if there is no available trip
    if (!tripsAvailable)
    {
        cout << "\n There are no available trips yet. " << endl << endl;
        cout << " Press Enter to go back." << endl;
        cin.get();
    }

}