#pragma once
#ifndef CABIFY_H
#define CABIFY_H

#include <string>
#include <vector>

// using namespace std;

// structures
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

enum SpecialNeeds { infant = 1, physicalNeeds };
enum Luggage { normal = 1, heavy };
enum paymentStatus { paid = 1, pending };

struct Journey
{
    std::string tripStart;
    std::string tripEnd;
    std::string bookingDate;
    std::string bookingTime;
    int passengers;
    SpecialNeeds specialN;
    Luggage luggage;
    paymentStatus payStatus;
};


// function to print logo - Logo.cpp
void CabifyLogo();

// function for Main menu - MainMenu.cpp
void MainMenu(int* choice);
void ClearScreen();

void NewAcc();
void TripBooking();
void ExistingAcc();
void BookCab(); // book cab main screen

#endif 
