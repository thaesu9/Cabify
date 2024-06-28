
#include <iostream>
#include"FDC.h"
#include<string>
#include<cstdlib>
#include<conio.h> //console input and ouput header - used to clear screen
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


//driver warrant of fitness details 
void WOF() {
    driver_WOF dw;

    //Warrant of fitness check 
    cout << "\nWarrent of Fitness check";
    cout << "\nEnter date of expiry (DD/MM/YY)" << endl;

    cout << "\nEnter day: ";
    cin >> dw.day;
    while (true) {
        if (dw.day > 0 && dw.day < 32)
        { // if day is less than 0 and day is less than 32 will be accepted and pass check
            break;
        }
        else if (dw.day > 31)
        {// if day is less than 0 and day is more than 32 will not pass check
            cout << "Not valid" << endl;//error message 
            break;
        }
        else {//otherwise show error message and allow user to re-enter day 
            cout << "Invalid input";
            cout << "\nEnter day: ";
            cin >> dw.day;
            break;
        }
    }
    cout << "Enter month: ";
    cin >> dw.month;

    while (true) {
        if (dw.month > 0 || dw.month < 12)
        { // if month is less than 0 and is less than 13 input will be accepted and pass check
            break;
        }

        else {//otherwise print error message and ask user to re-enter input
            cout << "Valid";
            break;
        }
    }



    cout << "Enter year: ";
    cin >> dw.year;

    while (true) {
        if (dw.year >= 2024)
        {// if user input is more than / equal to 2024 input will be pass check
            break;
        }
        else if (dw.year < 2024) //if year is less than 2024 will not pass check
        {
            cout << "Not valid" << endl;
            break;
        }
        else {//otherwie display error message and allow user to re-enter year
            cout << "Invalid input";
            cout << "\nEnter year: ";
            cin >> dw.year;
        }

    }
}

//driver payment details
void driver_payment() {

    //instance created for driver payment struct data types
    //which contains data members same as "normal variables"
    driver_pay driver_payment;

    cout << "\nBank account number: "; //display user input
    cin >> driver_payment.account_no; //store user input with data member named account_no inside 
    //driver_payment struct data type 

    cout << "\n**Your details have been saved**";
    cout << "\nAccount no: " << driver_payment.account_no;
};


//driver register function 
void driver_register() {

    //instance created for driver struct data type
      //in order to be able store all data members within this registration 

    int vehicle_year;

    //Driver registration banner
    cout << "\n*********************" << endl;
    cout << " DRIVER REGISTRATION " << endl;
    cout << "*********************" << endl;

    vector<driver> Driver;

    driver user_input;


    int randomID = rand();//used to generate random ID no.

    cout << "Your details have been saved " << endl;
    cout << "Your UNIQUE ID ref: " << randomID << endl;

    //driver first name
    cout << "\nEnter your first name" << endl;
    cin >> user_input.first_name;

    //driver last name
    cout << "\nEnter your last name" << endl;
    cin >> user_input.last_name;

    //gender of driver
    cout << "\nEnter your gender (format below) : " << endl;
    cout << "Female / female" << "\t" << "Male / male" << "\t" << "Diverse / diverse" << endl;
    cin >> user_input.gender;

    while (true) { // if user enters 
        if (user_input.gender == "Female" || user_input.gender == "female")
        {
            break;
        }
        else if (user_input.gender == "Male" || user_input.gender == "male")
        {

        }
        else if (user_input.gender == "Diverse" || user_input.gender == "diverse")
        {

        }
        else {
            cout << "Please, try again!";
            cout << "\nEnter your gender: ";
            cout << "Female / female" << "\t" << "Male / male" << "\t" << "Diverse / diverse" << endl;
            cin >> user_input.gender;
        }
    }

    //date of birth of driver
    cout << "\nEnter your date of birth" << endl;
    cin >> user_input.Date_of_birth;

    //Driver's nationality
    cout << "\nEnter your Nationality: " << endl;
    cin >> user_input.nationality;

    //Driver's contact number
    cout << "\nEnter your contact number (10 numbers): " << endl;
    cin >> user_input.contact_no;

    //Driver email 
    cout << "\nEnter your email address: " << endl;
    cin >> user_input.email_address;
    //if loop to check existing email/driver id condition check 



    int key4;
    cout << "\nEnter any number + enter for next page";
    cin >> key4;

    system("cls");


    //Driver vechile details banner
    cout << "******************************************" << endl;
    cout << "          DRIVER VEHICLE DETAILS          " << endl;
    cout << "******************************************" << endl;

    //Driver's full driver's license number
    cout << "\nEnter your drivers license number " << endl;

    cout << "\nEnter 2 letters: ";
    cin >> user_input.vechicle_license_letters;

    cout << "Enter 6 numbers: ";
    cin >> user_input.vehicle_license_number;

    cout << "Drivers license number: " << user_input.vechicle_license_letters << " " << user_input.vehicle_license_number << endl;

    //Drivers full license version number
    cout << "\nEnter your drivers license version no: (3 numbers) " << endl; //use a specific format
    cin >> user_input.version_number;

    cout << "Enter date of expiry : ";

    cout << "\nEnter day: ";
    cin >> user_input.day;
    while (true)
    {
        if (user_input.day > 0 || user_input.day < 32)
        {//if day is less more than 0 and less than 32 uinput will be accepted and pass check
            break;
        }
        else if (user_input.day > 31)
        {//if day user input is more than 31
            cout << "Not valid" << endl;
            break;
        }
        else {//otherwise display error message and allow user to re-enter day input
            cout << "Invalid input";
            cout << "\nEnter day: ";
            cin >> user_input.day;
            break;
        }
    }

    cout << "Enter month: ";
    cin >> user_input.month;

    while (true)
    {
        if (user_input.month > 0 || user_input.month < 32)
        {//if month is less than 0 and more than 32 user input will pass check
            break;
        }
        else if (user_input.month > 12)
        {//if month is more than 12 : user input will not pass
            cout << "Not valid" << endl;
            break;
        }
        else {//otherwise display error message and allow user to re-enter input
            cout << "Invalid input";
            cout << "\nEnter month: ";
            cin >> user_input.month;
            break;
        }
    }

    cout << "\nEnter year: ";
    cin >> user_input.year;

    while (true) {
        if (user_input.year > 2024)//if year is more than 2024 user input will pass check
        {
            break;
        }
        else if (user_input.year < 2024) // if year is less than 2024 will not pass check
        {
            cout << "Not valid" << endl;
            cout << "\nEnter year: ";
            cin >> user_input.year;
            break;
        }
        else {//otherwise display error message and allow user to re-enter year 
            cout << "Invalid input";
            cout << "\nEnter year: ";
            cin >> user_input.year;
            break;
        }

    }
    //WOF details 
    WOF();

    //Vehicle_model
    cout << "\nEnter your vehicle model: " << endl;
    cin >> user_input.vehicle_model;

    //Car production year
    cout << "\nEnter your vehicle year: ";
    cin >> vehicle_year;

    while (true) {//if vehicle year is more than 
        if (vehicle_year > 1989)
        {
            cout << "Your vehicle can be used!" << endl;
            break;
        } //if vehicle year is less than 1990 valid vehicle model
        else if (vehicle_year < 1989)
        {
            cout << "Your vehicle is too old" << endl;
            cout << "Enter your vehicle year: ";
            cin >> vehicle_year;
            break;
        }
        else {
            cout << "Invalid input!";
            cout << "\nEnter your vehicle year: ";
            cin >> vehicle_year;
            break;
        }
    }

    driver_payment();//driver_payment function 

    Driver.push_back(user_input);

    cin.ignore();//used to ignore a
    cout << "\nPress enter to save your details!" << endl;
    cin.get();

    cout << "Your details have been saved" << endl;

    int key5;

    cout << "Enter any number + enter for next page";
    cin >> key5;

    system("cls");


    //Driver Menu banner
    cout << "*********************" << endl;
    cout << "      DRIVER MENU    " << endl;
    cout << "*********************" << endl;

    int choice;

    cout << "\n1. Login" << endl;
    cout << "\n2. Register";
    cout << "\nChoose from the above options: ^";
    cin >> choice;

    while (true) {
        switch (choice)
        {
            {
        case 1:
            string email;

            cout << "\nLOGIN** : ";
            cout << "\nEnter email:";
            cin >> email;

            if (email == user_input.email_address)
            {
                cout << "checking...";
                cout << "Correct!";

                cout << "\nName: " << user_input.first_name;
                cout << "\nGender: " << user_input.gender;
                cout << "\nNationality: " << user_input.nationality << endl;
                break;
            }
            else
            {

                cout << "\n1.Login";
                cout << "\n2. Register";
                cout << "\nsChoose from the above options: ^";
                cin >> choice;

            }


            }

            {
        case 2:
            driver Driver;
            cout << "\nRegister (NEW)";
            driver_register();
            break;

            }
        default:
            cout << "Invalid input!";

            break;
        }
    }
}


//driver eligibility check 
void eligibility_check() {
    driver dr;
    general_register gr; // instance created for struct data type

    //driver banner

    cout << "\n\nEligibility Check! " << endl;
    cout << "********************" << endl;

    //driver eligibility check
    cout << "\nEnter age: ";
    cin >> gr.age;

    cout << "Enter your driving experience: ";
    cin >> gr.driving_exp;

    //if age is less than 16 and age is bigger than 80 and driving experience is bigger than 0
    if (gr.age > 16 && gr.age < 80 && gr.driving_exp > 0)
    {
        cout << "Excellent, you can apply for this job!" << endl;
        driver_register();//driver register function

    }//if age is bigger than 80 and driving experience is 
    else if (gr.age > 80 && gr.driving_exp < 9) {
        cout << "sorry, but your cannot apply for this job";
        cin.ignore();
    }
    else {
        cout << "Sorry, but you are not eligible";
    }
}

