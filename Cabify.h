#pragma once

// to prevent redefinition error (due to multiple mentioning of header file)
#ifndef CABIFY_H   // if not defined - check if macro CABIFY_H hasn't been defined yet
#define CABIFY_H   // define macro CABIFY_H

#include <string>
#include <vector>

// struct for customer information
struct Customer
{
    std::string firstName;
    std::string lastName;
    std::string fullName;  // first name + last name string concatenation
    std::string email;
    std::string password;  // email and password for login credential
    std::string address;
    std::string phone;
    int paymentMethod = 0; // payment method of choice (1=card, 2=cash)
    std::string visaCard;
    std::string visaExp;
};

extern std::vector<Customer> customers; // store customers information in vector
// extern to avoid multiple definition error

// struct for driver
struct Driver
{
    int age;                        // for age check
    int drivingExp;                 // driving experience
    int carYear;                    // car production year
    int WOFdd, WOFmm, WOFyyyy;      // to take WOF as day, month and year for condition check
    std::string WOFexpire;          // WOF expiry date
    std::string carModel;           // eg - Toyota Prius
    std::string licensePlate;       // car license plate number
    std::string firstName;
    std::string lastName;
    std::string fullName;
    int gender;                     // gender (1=male,2=female,3=gender diverse)
    std::string dob;                // date of birth
    std::string nationality;
    std::string D_licenseNum;       // driver license num
    std::string D_licenseVersion;   // license version (on driving license)
    int Ldd, Lmm, Lyyyy;            // get license date as day, month and year for condition check
    std::string licenseExpireDate;  // license expire date
    std::string email;
    std::string password;           // email and password for login credential check
    std::string address;
    std::string phone;
    std::string bankAcc;            // bank account
    std::string bankName;
    std::string driverID;           // ID start from 01
};

extern std::vector<Driver> drivers;   // vector for driver
// extern to avoid multiple definition error

// enumerated - trip booking
enum SpecialNeeds { none = 1, infant , physicalNeeds };

// struct for trip booking
struct Journey
{
    long int tripID = 0;       // trip ID will be 4-digit random generated number and unique
    std::string customerName;  
    std::string tripStart;     // pick up point
    std::string tripEnd;       // destination
    std::string bookingDate;
    std::string bookingTime;
    int passengers = 0;        // number of passengers (initiated 0)
    SpecialNeeds specialN;     // special need - taken from enum
    int luggage = 0;           // number of luggages (initiated 0)
    bool payStatus;            // payment status, paid or pending
    bool tripStatus = true;    // trip status active or cancelled
    bool assigned;             // trip assigned to driver status
    std::string driverID;
    std::string driverName;
    std::string licensePlate;
    bool driverstatus = false;  // driver assign status (false if not yet assigned)
};

extern std::vector<Journey> journey;

// struct for admin
struct Admin
{
    std::string username = "admin";   // admin login credential
    std::string password = "admin";   // admin login credential
    bool attemptFailed = false;       // boolean for login attempt successful or fail
    int failedAttempts = 1;           // fail attempt count
};

// function to print logo - Logo.cpp
void CabifyLogo();

// function for Main menu - MainMenu.cpp
void MainMenu(int* choice);    // display main menu
void TermsConditions();        // display terms and conditions
void ClearScreen();            // clear screen and display logo as a fresh page start

// Project_Cabify.cpp
bool CheckDate(int day, int month, int year);  // to check valid date

// trip - TripBooking.cpp
void TripBooking(const std::string* email);     // for customer trip booking
void PrintBill(long int tripID);                // printing bill for customer
void CancelBooking(const std::string* email);   // customer cancel booking
void DriverDriveNow(const std::string* email);  // getting trip for driver

// customer - CustomerFunctions.cpp
bool VisaCardCheck(const std::string& visaCard);  // visa card check
void NewAcc();                                    // customer new account - register 
void ExistingAcc();                               // customer existing account - login
void BookCab();                                   // display Customer main menu

// driver - DriverFunctionss.cpp
void DriverMainMenu();                      // display Driver main menu
void NewDriverAcc();                        // new driver - registration
void ExistingDriverAcc();                   // existing customer - login

// admin - Admin.cpp
void adminLogin();                      // admin login credential + attempt check
void adminMenu();                       // display Admin main menu
void customerInformation();             // admin - manage customer information
void driverInformation();               // admin - manage driver information
void TripInformation();                 // admin - manage trip information

#endif   // end conditional derifitive started by #ifndef
