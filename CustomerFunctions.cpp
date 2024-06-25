#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Cabify.h"

using namespace std;

vector<Customer> customers; // definition of extern variable

// check for valid visa card, 16 digits and start with '4'
bool VisaCardCheck(const string& visaCard)
{
    if (visaCard.length() != 16)
    {
        return false;
    }

    // check first digit
    if (visaCard[0] != '4')
    {
        return false;
    }

    for (char c : visaCard)
    {
        if (!isdigit(c))   // if char c is not digit
        {
            return false;
        }
    }
    return true;
}

// file handling function - save to customer file
void CustomerFile(const Customer& cus)
{
    fstream customerFile;
    customerFile.open("Customer.txt", ios::app); // append instead of out
    
    if (customerFile.is_open())
    {
        customerFile << " Name           : " << cus.fullName << endl;
        customerFile << " Email          : " << cus.email << endl;
        customerFile << " Contact Number : " << cus.phone << endl;
        customerFile << " Address        : " << cus.address << endl;
        if (cus.paymentMethod == 2)
        {
            customerFile << " Payment Method : Cash" << endl;
        }
        else if (cus.paymentMethod == 1)
        {
            customerFile << " Payment Method : Card" << endl;
            customerFile << " Visa Card      : " << cus.visaCard << " (" << cus.visaExp << ")" << endl;
        }
        customerFile << endl;
        customerFile.close();
    }
}

// function for new account
void NewAcc()
{
    Customer newCus;  // call struct
    cout << "\n Customer Registration Page" << endl;
    cout << " ---------------------------" << endl;

    cin.ignore();
    while (true) 
    {
        // not to let user enter empty email
        do{
            cout << " Email : ";
            getline(cin, newCus.email);

            if (newCus.email.empty())
            {
                cout << " Please enter your email address." << endl << endl;
            }
        } while (newCus.email.empty());

        bool emailExists = false;  // to check if email exist in the system
        // find email in customer vector
        for (const auto& customer : customers)
        {
            if (newCus.email == customer.email)
            {
                emailExists = true;
                break;
            }
        }
        // find email in driver vector
        for (const auto& driver : drivers)
        {
            if (newCus.email == driver.email)
            {
                emailExists = true;
                break;
            }
        }

        // if the email already exist in the system
        if (emailExists)
        {
            ClearScreen();
            cout << "\n The email already exists. Please try another email." << endl;
            cout << "\n Customer Registration Page" << endl;
            cout << " ---------------------------" << endl;
            
        }
        else
        {
            break; // if email is unique, exit
        }
    }

    // not to let user enter empty password
    do{
        cout << " Password : ";
        getline(cin, newCus.password);

        if (newCus.password.empty())     // if the user enter password is empty
        {
            cout << " Please enter your password." << endl << endl;
        }
    } while (newCus.password.empty());

    ClearScreen();
    cout << "\n Customer Registration Page" << endl;
    cout << " ---------------------------" << endl;

    cout << " First Name : ";
    getline(cin, newCus.firstName);   // use getline to read entire line (including space)
    cout << " Last Name : ";
    getline(cin, newCus.lastName);

    newCus.fullName = newCus.firstName + " " + newCus.lastName;  // string concatenation

    cout << " Contact Number : ";
    getline(cin, newCus.phone);

    cout << " Address : ";
    getline(cin, newCus.address);

    while(true)
    {
        cout << " Payment method (Choose, 1 = card, 2 = cash) : ";
        cin >> newCus.paymentMethod;
        if (cin.fail() || (newCus.paymentMethod != 1 && newCus.paymentMethod != 2)) // if user input fail or user input != 1 or != 2
        {
            cin.clear(); // clear input
            cin.ignore(); // discard invalid input
            cout << " Invalid choice. Please enter 1 for card or 2 for cash." << endl << endl;
        }
        else
        {
            break;
        }
    }
    cin.ignore();
    // if the user input for payment method is 1, ask for visa card information
    if (newCus.paymentMethod == 1)
    {
        while (true)
        {
            cout << " Please enter Visa Card Number (no spacing) : ";
            getline(cin, newCus.visaCard);

            // check for visa card validity using function
            if (VisaCardCheck(newCus.visaCard))
            {
                break;
            }
            else
            {
                cout << "\n Invalid visa card. Please fill the valid visa card." << endl << endl;
            }
            
        }
        
        cout << " Visa card expiry date (MM/YY) : ";
        getline(cin, newCus.visaExp);
    }
    // if the user payment method input is 2, put "nil" in visa card and visa expiration
    else
    {
        newCus.visaCard = "nil";
        newCus.visaExp = "nil";
    }

    customers.push_back(newCus);  // add new customer in vector

    CustomerFile(newCus);         // add new customer to customer.txt file

    ClearScreen();
    cout << "\n Thank you for joining Cabify. You can now start your journey." << endl;
    cout << " Please login to proceed with your booking." << endl;

}


// function - login for existing account
void ExistingAcc()
{
    cin.ignore();

    // find customer by email
    string email, password;
    cout << "\n Email : ";
    getline(cin, email);

    bool found = 0;
    bool incorrectPW = 0; // for wrong password attempts
    int attempt = 0;      // num of attempts
    int maxAttempt = 10;  // maximum number of attempt is 10 times

    while(attempt < maxAttempt)
    {
        cout << " Password : ";
        getline(cin, password);

        for (const auto& cus : customers) // find in customers vector using struct
        {
            if (cus.email == email)
            {
                if(cus.password == password)
                {
                    found = 1;  // acc found
                    while (true)
                    {
                        ClearScreen();
                        cout << " \n Kia Ora " << cus.firstName << " .";
                        cout << " What can we do for you today? " << endl << endl;
                        cout << " 1. Book a cab" << endl;
                        cout << " 2. Cancel Booking" << endl;
                        cout << " 3. View my Profile" << endl;
                        cout << " 4. My Bookings" << endl;
                        cout << " 0. Back" << endl;
                        cout << " 9. Exit" << endl;
                        int choice;
                        cout << "\n Choice : ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                            ClearScreen();
                            // book a trip
                            TripBooking(&email);
                            break;

                        case 2:
                            ClearScreen();
                            //cancel booking
                            CancelBooking(&email);
                            break;

                        case 3:
                            ClearScreen();
                            // view profile
                            cout << "\n Profile Details" << endl;
                            cout << " -----------------------------" << endl;
                            cout << " Name           : " << cus.fullName << endl;
                            cout << " Email          : " << cus.email << endl;
                            cout << " Contact Number : " << cus.phone << endl;
                            cout << " Address        : " << cus.address << endl << endl;
                            if (cus.paymentMethod == 2)
                            {
                                cout << " Payment Method : Cash" << endl;
                            }
                            else if (cus.paymentMethod == 1)
                            {
                                cout << " Payment Method : Card" << endl;
                                cout << " Visa Card      : " << cus.visaCard << " (" << cus.visaExp << ")" << endl;
                            }

                            cin.ignore();
                            cout << "\n Press Enter to go back." << endl;
                            cin.get();
                            break;

                        case 4:
                            ClearScreen();
                            // view booking
                            cout << "\n Booking history" << endl;
                            cout << " -----------------------------" << endl;

                            {
                                bool tripexist = 0;
                                for (const auto& trip : journey)
                                {
                                    if (cus.firstName == trip.customerName)
                                    {
                                        cout << " Trip ID           : " << trip.tripID << endl;
                                        if (!trip.driverstatus)
                                        {
                                            cout << " Driver Name       : searching for driver...." << endl;
                                            cout << " Cab Plate Number  : searching for driver...." << endl;
                                        }
                                        else
                                        {
                                            cout << " Driver Name       : " << trip.driverName << endl;
                                            cout << " Cab Plate Number  : " << trip.licensePlate << endl;
                                        }
                                        cout << " Pick up location  : " << trip.tripStart << endl;
                                        cout << " Drop off location : " << trip.tripEnd << endl;
                                        cout << " Booking Date      : " << trip.bookingDate << endl;
                                        cout << " Booking Time      : " << trip.bookingTime << endl;
                                        cout << " Total Passengers  : " << trip.passengers << endl;

                                        if (trip.specialN == 1)
                                            cout << " Special Request   : None " << endl;
                                        else if (trip.specialN == 2)
                                            cout << " Special Request   : I have a baby " << endl;
                                        else if (trip.specialN == 3)
                                            cout << " Special Request   : I need special aid " << endl;
                                        else
                                            cout << " Special Request   : None " << endl;

                                        if (trip.tripStatus == true)
                                            cout << " Trip Status       : Completed" << endl << endl;
                                        else
                                            cout << " Trip Status       : Cancelled" << endl << endl;

                                        tripexist = 1;
                                    }
                                    if (!tripexist)
                                    {
                                        cout << "\n You have no bookings yet." << endl << endl;
                                    }

                                }
                            }

                            cin.ignore();
                            cout << "\n Press Enter to go back." << endl;
                            cin.get();
                            break;

                        case 0:
                            // return
                            ClearScreen();
                            return;

                        case 9:
                            ClearScreen();
                            cout << "\nThank you for using Cabify. Please come again." << endl;
                            exit(0); // to entire exit and end the program
                            break;

                        default:
                            ClearScreen();
                            cout << "Invalid choice. Please choose again : ";
                            break;
                        }
                    }
                }
                else  // if email is correct with incorrect password
                {
                    incorrectPW = 1;  // incorrect password boolean = true
                }
            }
        }
        if (found) // if the email is found and correct password
        {
            break;
        }
        else if (incorrectPW) // if the password is incorrect
        {
            cout << "\n Incorrect password. Please try again." << endl;
            incorrectPW = 0;
            attempt++;
        }
        else // if the email is not found in the system
        {
            cout << "\n No account found. Press Enter to go back to register." << endl;
            cin.get();
            ClearScreen();
            return;
        }
    }
    // if the login attempt becomes more than 10 times (maximum attempts)
    if (!found && attempt >= maxAttempt)
    {
        cout << "\n Invalid login. Too many failed password attempts.\n Please try again later." << endl;
        cin.get();
        ClearScreen();
    }
    
}

// Booking screen main menu
void BookCab()
{
    while (true)
    {
        cout << "\n Kia Ora. Please choose from following options to proceed with your booking." << endl << endl;
        cout << " 1. Register (I'm new customer)" << endl;
        cout << " 2. Login (I have an account)" << endl;
        cout << " 0. Back" << endl;
        cout << " 9. Exit" << endl;
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

        case 0:
            // return to main menu
            ClearScreen();
            return;
            
        case 9:
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


