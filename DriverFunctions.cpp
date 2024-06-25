#include <iostream>
#include <string>
#include <sstream> // istringstream
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Cabify.h"

using namespace std;

vector<Driver> drivers;

// check whether user input for Driving License is valid or not
bool ValidLicense(string license)
{
    // driving license is 2 alphabet + 6 numbers = total 8 digits
    // if the input is not 8 digits, return false
    if (license.length() != 8)
    {
        return false;
    }

    // if the first 2 character inputs is not alphabet, return false
    for (int i = 0; i < 2; i++)
    {
        if (!isalpha(license[i]))
        {
            return false;
        }
    }

    // if the last 6 character inputs are not numbers, return false
    for (int i = 2; i < 8; i++)
    {
        if (!isdigit(license[i]))
        {
            return false;
        }
    }
    return true;
}

// add registered driver information to driver file
void DriverFile(const Driver& driver)
{
    fstream driverFile;
    driverFile.open("driver.txt", ios::app); // to append in the driver file

    if (driverFile.is_open())
    {
        driverFile << " Cabify ID       : " << driver.driverID << endl;
        driverFile << " Name            : " << driver.fullName << endl;
        driverFile << " Age             : " << driver.age << endl;
        driverFile << " Date of birth   : " << driver.dob << endl;

        if (driver.gender == 1)
            driverFile << " Gender          : Male " << endl;
        else if (driver.gender == 2)
            driverFile << " Gender          : Female " << endl;
        else if (driver.gender == 3)
            driverFile << " Gender          : Gender Diverse " << endl;
        else
            driverFile << " Gender          : Nil " << endl;

        driverFile << " Nationality     : " << driver.nationality << endl;
        driverFile << " Email           : " << driver.email << endl;
        driverFile << " Contact Number  : " << driver.phone << endl;
        driverFile << " Address         : " << driver.address << endl << endl;
        driverFile << " Driving Experience : " << driver.drivingExp << " years" << endl;
        driverFile << " Driver License     : " << driver.D_licenseNum << endl;
        driverFile << " License Version    : " << driver.D_licenseVersion << endl;
        driverFile << " License Expiry     : " << driver.licenseExpireDate << endl << endl;
        driverFile << " Bank Account       : " << driver.bankAcc << " (" << driver.bankName << " Bank)" << endl;

        driverFile << "\n Vehicle Details of Driver ID " << driver.driverID << endl;
        driverFile << " -----------------------------------------" << endl;
        driverFile << " Car Model           : " << driver.carModel << endl;
        driverFile << " Car Licence Plate   : " << driver.licensePlate << endl;
        driverFile << " Car Production Year : " << driver.carYear << endl;
        driverFile << " WOF Expiry Date     : " << driver.WOFexpire << endl << endl;
        driverFile << " -----------------------------------------" << endl;

        driverFile << endl;
        driverFile.close();
    }
}

// function for new driver account
void NewDriverAcc()
{
    Driver newDriver;
    cout << "\n Thank you for choosing to drive with Cabify. \n Please fill out the form to proceed with your registration." << endl << endl;

    // age check for eligibility (age between 18 to 70)
    cout << " Enter your age : ";
    int age;
    cin >> age;
    if (age < 18 || age > 70)
    {
        cout << "\n Sorry. You cannot register as our driver. You did not meet the age requirement. " << endl;
        cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;     // go back to main menu   
    }
    else
    {
        newDriver.age = age;
    }
    
    // driving experience in years cross-check with age
    cout << " How many years of driving experience do you have? : ";
    int exp;
    cin >> exp;
    int n = age - exp;
    if (n < 16)
    {
        cout << "\n Your age and years of driving experience is irrelevant. You did not meet the requirement." << endl;
        cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;
    }
    else if (exp <= 0)
    {
        cout << "\n You need at least 1 year driving experience. You did not meet the requirement." << endl;
        cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;
    }
    else
    {
        newDriver.drivingExp = exp;
    }
    
    ClearScreen();
    // registration start
    cout << "\n Kia ora. Please fill out the following form to continue your registration." << endl;
    cout << "\n Driver Registration Page" << endl;
    cout << " ---------------------------" << endl;

    cin.ignore();
    while (true)
    {
        // not to let user enter empty email
        do{
            cout << " Email : ";
            getline(cin, newDriver.email);

            if (newDriver.email.empty())
            {
                cout << " Please enter your email address." << endl << endl;
            }
        } while (newDriver.email.empty());

        // check if the email already exist in the system
        bool emailExists = false;
        // find in customer vector
        for (const auto& customer : customers)
        {
            if (newDriver.email == customer.email)
            {
                emailExists = true;
                break;
            }
        }
        // find in driver vector
        for (const auto& driver : drivers)
        {
            if (newDriver.email == driver.email)
            {
                emailExists = true;
                break;
            }
        }

        if (emailExists)
        {
            ClearScreen();
            cout << "\n The email already exists. Please try another email." << endl;
            cout << "\n Kia ora. Please fill out the following form to continue your registration." << endl;
            cout << "\n Driver Registration Page" << endl;
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
        getline(cin, newDriver.password);

        if (newDriver.password.empty())
        {
            cout << " Please enter your password." << endl << endl;
        }
    } while (newDriver.password.empty());

    ClearScreen();
    cout << "\n Driver Registration Page" << endl;
    cout << " ---------------------------" << endl;

    cout << " First Name : ";
    getline(cin, newDriver.firstName);   // use getline to read entire line (including space)
    cout << " Last Name : ";
    getline(cin, newDriver.lastName);

    newDriver.fullName = newDriver.firstName + " " + newDriver.lastName;  // string concatenation

    // gender
    while (true)
    {
        cout << " Gender (1 = male, 2 = female, 3 = gender diverse) : ";
        cin >> newDriver.gender;
        if (cin.fail() || (newDriver.gender != 1 && newDriver.gender != 2 && newDriver.gender != 3))
        {
            cin.clear();  // clear input
            cin.ignore(); // discard invalid input
            cout << " Invalid choice. Please choose again." << endl << endl;
        }
        else
        {
            break;
        }
    }
    cin.ignore(); // ignore previous cin

    while (true)
    {
        string date;
        cout << " Date of birth (dd/mm/yyyy) : ";
        getline(cin, date);

        // Create an istringstream object for parsing the date
        istringstream Date(date);
        int dd, mm, yyyy;
        char slash1, slash2;

        // check valid date input
        // Parse the date into day, month, year separated by '/'
        if (Date >> dd >> slash1 >> mm >> slash2 >> yyyy)
        {
            if (slash1 == '/' && slash2 == '/' && CheckDate(dd, mm, yyyy))
            {
                newDriver.dob = to_string(dd) + "/" + to_string(mm) + "/" + to_string(yyyy);
                break;
            }
            else
            {
                cout << " Invalid date. Please fill again." << endl << endl;
            }
        }
    }

    cout << " Nationality : ";
    getline(cin, newDriver.nationality);

    cout << " Contact Number : ";
    getline(cin, newDriver.phone);

    cout << " Address : ";
    getline(cin, newDriver.address);

    // driving license number
    while (true)
    {
        string license;
        cout << " Driving License Number : ";
        getline(cin, license);

        // check valid driving license input format
        if (ValidLicense(license))
        {
            newDriver.D_licenseNum = license;
            break;
        }
        else
        {
            cout << " Invalid license format. Please fill again." << endl << endl;
        }
    }

    cout << " Driving License Version : ";
    getline(cin, newDriver.D_licenseVersion);

    // license expire date check
    while(true)
    {
        string date;
        cout << " Driving License Expiry Date (dd/mm/yyyy) : ";
        getline(cin, date);

        // Create an istringstream object for parsing the date
        istringstream Date(date);
        char slash1, slash2;

        // Parse the date into day, month, year separated by '/'
        if (Date >> newDriver.Ldd >> slash1 >> newDriver.Lmm >> slash2 >> newDriver.Lyyyy)
        {
            if (slash1 == '/' && slash2 == '/' && CheckDate(newDriver.Ldd, newDriver.Lmm, newDriver.Lyyyy))
            {
                break;
            }
            else
            {
                cout << " Invalid date. Please fill again." << endl << endl;
            }
        }
    }
    
    // check if the license is expired
    if (newDriver.Lyyyy < 2023)
    {
        cout << " Sorry. Your driving license is expired. You cannot drive for Cabify." << endl;
        // cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;     // go back to main menu  
    }
    else
    {
        newDriver.licenseExpireDate = to_string(newDriver.Ldd) + "/" + to_string(newDriver.Lmm) + "/" + to_string(newDriver.Lyyyy);
    }

    cout << " Bank Account Number : ";
    getline(cin, newDriver.bankAcc);

    cout << " Bank Name : ";
    getline(cin, newDriver.bankName);

    
    // car registration
    ClearScreen();
    cout << "\n Vehicle Registration Page" << endl;
    cout << " ---------------------------" << endl;

    cout << " Model of the car (E.g - Toyota Prius) : ";
    getline(cin, newDriver.carModel);

    cout << " License Plate Number : ";
    getline(cin, newDriver.licensePlate);

    cout << " Car Production Year : ";
    cin >> newDriver.carYear;
    if (newDriver.carYear < 1990 || newDriver.carYear > 2024)
    {
        cout << " Sorry. Your car is unfit for driving. You cannot drive for Cabify with car production year older than 1990." << endl;
        cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;     // go back to main menu 
    }

    cin.ignore();
    // WOF date check
    while (true)
    {
        string date;
        cout << " Warrant of Fitness (WOF) Expiry Date (dd/mm/yyyy) : ";
        getline(cin, date);

        istringstream Date(date);
        char slash1, slash2;

        if (Date >> newDriver.WOFdd >> slash1 >> newDriver.WOFmm >> slash2 >> newDriver.WOFyyyy)
        {
            if (slash1 == '/' && slash2 == '/' && CheckDate(newDriver.WOFdd, newDriver.WOFmm, newDriver.WOFyyyy))
            {
                break;
            }
            else
            {
                cout << " Invalid date. Please fill again." << endl << endl;
            }
        }
    }
    // check if the WOF is expired
    if (newDriver.WOFyyyy < 2023)
    {
        cout << " Sorry. Your car is unfit for driving. Please get updated warrrent of fitness(WOF) check." << endl;
        // cin.ignore();
        cout << "\n Press Enter to go back." << endl;
        cin.get();
        ClearScreen();
        return;     // go back to main menu  
    }
    else
    {
        newDriver.WOFexpire = to_string(newDriver.WOFdd) + "/" + to_string(newDriver.WOFmm) + "/" + to_string(newDriver.WOFyyyy);
    }


    // Driver ID
    static int IDnum = 1;  // initialize driver ID count start from 1
    int driverID = IDnum++; // increase if 1 already exist
    newDriver.driverID = to_string(driverID); // convert to string to convert to 01
    newDriver.driverID.insert(newDriver.driverID.begin(), 2 - newDriver.driverID.length(), '0');  // convert to 01

    drivers.push_back(newDriver);  // register new driver data to vector

    DriverFile(newDriver);         // register new driver data to driver.txt file

    cout << "\n Thank you for registering with Cabify. Press Enter to go back." << endl;
    cin.get();

    ClearScreen();
    cout << "\n Thank you for driving with Cabify. Please login to proceed." << endl;
}

void ExistingDriverAcc()
{
    cin.ignore();

    // find driver account by email
    string email,password;
    cout << "\n Email : ";
    getline(cin, email);

    bool found = 0;       // boolean for account found
    bool incorrectPW = 0; // for wrong password attempts
    int attempt = 0;      // num of attempts
    int maxAttempt = 10;  // maximum number of attempt = 10

    while(attempt < maxAttempt)
    {
        cout << " Password : ";
        getline(cin, password);

        for (const auto& driver : drivers) // find in customers vector using struct
        {
            if (driver.email == email)
            {
                if(driver.password == password)
                {
                    found = 1; // acc found
                    while (true)
                    {
                        ClearScreen();
                        cout << "\n Kia Ora " << driver.firstName << " .";
                        cout << " What would you like to do? " << endl << endl;
                        cout << " 1. Drive now" << endl;
                        cout << " 2. View my Profile" << endl;
                        cout << " 3. View my Vehicle Profile" << endl;
                        cout << " 4. My Driving History" << endl;
                        cout << " 0. Back" << endl;
                        cout << " 9. Exit" << endl;
                        int choice;
                        cout << "\n Choice : ";
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                            ClearScreen();
                            // drive now
                            DriverDriveNow(&email);
                            break;

                        case 2:
                            ClearScreen();
                            // View my profile
                            cout << "\n Profile Details" << endl;
                            cout << " -----------------------------" << endl;
                            cout << " Cabify ID       : " << driver.driverID << endl;
                            cout << " Name            : " << driver.fullName << endl;
                            cout << " Date of birth   : " << driver.dob << endl;

                            if (driver.gender == 1)
                                cout << " Gender          : Male " << endl;
                            else if (driver.gender == 2)
                                cout << " Gender          : Female " << endl;
                            else if (driver.gender == 3)
                                cout << " Gender          : Gender Diverse " << endl;
                            else
                                cout << " Gender          : Nil " << endl;

                            cout << " Nationality     : " << driver.nationality << endl;
                            cout << " Email           : " << driver.email << endl;
                            cout << " Contact Number  : " << driver.phone << endl;
                            cout << " Address         : " << driver.address << endl << endl;
                            cout << " Driver License  : " << driver.D_licenseNum << endl;
                            cout << " License Version : " << driver.D_licenseVersion << endl;
                            cout << " License Expiry  : " << driver.licenseExpireDate << endl << endl;
                            cout << " Bank Account    : " << driver.bankAcc << " (" << driver.bankName << " Bank)" << endl << endl;

                            cin.ignore();
                            cout << "\n Press Enter to go back." << endl;
                            cin.get();
                            break;

                        case 3:
                            ClearScreen();
                            // view vehicle profile
                            cout << "\n Vehicle Details" << endl;
                            cout << " -----------------------------" << endl;
                            cout << " Car Model           : " << driver.carModel << endl;
                            cout << " Car Licence Plate   : " << driver.licensePlate << endl;
                            cout << " Car Production Year : " << driver.carYear << endl;
                            cout << " WOF Expiry Date     : " << driver.WOFexpire << endl << endl;

                            cin.ignore();
                            cout << "\n Press Enter to go back." << endl;
                            cin.get();
                            break;

                        case 4:
                            ClearScreen();
                            // view driving history
                            cout << "\n Driving history" << endl;
                            cout << " -----------------------------" << endl;
                            {
                                bool found = 0;
                                for (const auto& trip : journey)
                                {
                                    if (driver.firstName == trip.driverName)
                                    {
                                        cout << " Trip ID              : " << trip.tripID << endl;
                                        cout << " Customer Name        : " << trip.customerName << endl;
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
                                    }
                                }
                            }

                            cin.ignore();
                            cout << "\n Press Enter to go back." << endl;
                            cin.get();
                            break;

                        case 0:
                            // return menu
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
                else
                {
                    incorrectPW = 1;
                }
            }
        }
       
        if (found) // if email address is found
        {
            break;
        }
        // if the input password is incorrect
        else if (incorrectPW)
        {
            cout << "\n Incorrect password. Please try again." << endl;
            incorrectPW = 0;
            attempt++;
        }
        // if the email address is not found
        else
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

void DriverMainMenu()
{
    while (true)
    {
        cout << "\n Kia Ora. Please choose from following options to proceed." << endl << endl;
        cout << " 1. Register (I'm new driver)" << endl;
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
            NewDriverAcc();
            break;

        case 2:
            ClearScreen();
            ExistingDriverAcc();
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