#pragma once
#ifndef CABIFY_H
#define CABIFY_H

#include <string>
#include <vector>

// struct for customer information
struct Customer
{
    std::string firstName;
    std::string lastName;
    std::string fullName;
    std::string email;
    std::string password;
    std::string address;
    std::string phone;
    int paymentMethod = 0;
    std::string visaCard;
    std::string visaExp;
};

extern std::vector<Customer> customers; // store customers information in vector
// extern to avoid multiple definition error

// struct for driver
struct Driver
{
    int age;
    int drivingExp;                // driving experience
    int carYear;                   // car production year
    int WOFdd, WOFmm, WOFyyyy;
    std::string WOFexpire;
    std::string carModel;          // eg - Toyota Prius
    std::string licensePlate;      // car license plate number
    std::string firstName;
    std::string lastName;
    std::string fullName;
    int gender;
    std::string dob;
    std::string nationality;
    std::string D_licenseNum;       // driver license num
    std::string D_licenseVersion;
    int Ldd, Lmm, Lyyyy;            // get license date
    std::string licenseExpireDate;      // license expire date
    std::string email;
    std::string password;
    std::string address;
    std::string phone;
    std::string bankAcc;
    std::string bankName;
    std::string driverID;                   // ID start from 001
};

extern std::vector<Driver> drivers;

// enumerated - trip booking
enum SpecialNeeds { none = 1, infant , physicalNeeds };

// struct for trip booking
struct Journey
{
    long int tripID = 0;
    std::string customerName;
    std::string tripStart;
    std::string tripEnd;
    std::string bookingDate;
    std::string bookingTime;
    int passengers = 0;
    SpecialNeeds specialN;
    int luggage = 0;
    bool payStatus;
    bool tripStatus = true;
    bool assigned;             // trip assigned to driver status
    std::string driverID;
    std::string driverName;
    std::string licensePlate;
    bool driverstatus = false;
};

extern std::vector<Journey> journey;

// struct for admin
struct Admin
{
    std::string username = "admin";
    std::string password = "admin";
    bool attemptFailed = false;
    int failedAttempts = 1;
};

// function to print logo - Logo.cpp
void CabifyLogo();

// function for Main menu - MainMenu.cpp
void MainMenu(int* choice);
void TermsConditions();
void ClearScreen();

// Project_Cabify.cpp
bool CheckDate(int day, int month, int year);  // to check valid date

// trip - TripBooking.cpp
void TripBooking(const std::string* email);
void PrintBill(long int tripID);
void CancelBooking(const std::string* email);
void DriverDriveNow(const std::string* email);  // getting trip for driver

// customer - CustomerFunctions.cpp
bool VisaCardCheck(const std::string& visaCard);  // visa card check
void NewAcc();
void ExistingAcc();
void BookCab(); // main menu

// driver - DriverFunctionss.cpp
void DriverMainMenu();
void NewDriverAcc();
void ExistingDriverAcc();

// admin - Admin.cpp
void adminLogin();
void adminMenu();
void customerInformation();
void driverInformation();
void TripInformation();

#endif 
