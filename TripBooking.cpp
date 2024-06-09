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
void TripBooking()
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

    cout << "\n Your trip ID : " << newTrip.tripID << endl;

    cout << "Press Enter to go back." << endl;
    cin.get();
}