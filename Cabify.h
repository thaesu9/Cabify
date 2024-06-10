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
    std::string address;
    std::string phone;
    int paymentMethod = 0;
    std::string visaCard;
    std::string visaExp;
};

extern std::vector<Customer> customers; // store customers information in vector
// extern to avoid multiple definition error

enum SpecialNeeds { none = 1, infant , physicalNeeds };

// struct for trip booking
struct Journey
{
    long long int tripID = 0;
    std::string customerName;
    std::string tripStart;
    std::string tripEnd;
    std::string bookingDate;
    std::string bookingTime;
    int passengers = 0;
    SpecialNeeds specialN;
    int luggage = 0;
    int payStatus = 0;
    bool tripStatus = true;
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

// trip - TripBooking.cpp
void TripBooking(const std::string* email);
void PrintBill(long int tripID);
void CancelBooking(const std::string* email);

// customer - CustomerFunctions.cpp
void NewAcc();
void ExistingAcc();
void BookCab(); // main menu


// admin - Admin.cpp
void adminLogin();
void adminMenu();
void customerInformation();
void TripInformation();

#endif 
