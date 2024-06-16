#include <iostream>
#include"Dc.h"
using namespace std;


void eligibility_check() {
    driver dr;
    general_register gr; // instance created for struct data type

    //driver information 
    cout << "Welcome to the elgibility check" << endl;
    cout << "*******************************" << endl;

    cout << "\nNote: To apply for this job you must be aged between 26 - 60!, Thank you." << endl;
    cout << "\nBelow are the details you will have to provide answers for:" << endl;
    cout << "\n1. Full license no" << endl;
    cout << "2. Full license version (3 num)" << endl;
    cout << "3. Age" << endl;
    cout << "4. Driving experience" << endl;
    cout << "5. Taxi model\n";
    //driver full license number
    cout << "\nPlease, enter your full licnese no.";
    cin >> gr.fulllicense;

    //drivers' full license version
    cout << "Please, enter your full license version(3 numbers only)";
    cin >> gr.full_license_version;
    //age check 
    cout << "Enter age";
    cin >> gr.age;
    cout << "Enter your driving experience";
    cin >> gr.driving_exp;
    if (gr.age > 25 && gr.age < 60 && gr.driving_exp > 9)
    {
        cout << "Excellent, you can apply for this job!";
        cout << "\nEnter taxi model:";
        cin >> gr.taxi_model;
        //display drivers eligibility requirements below 
        cout << "\nFull license no.:" << gr.fulllicense << endl; // full license no.
        cout << "Full license version:" << gr.full_license_version << endl; // full licenser version number
        cout << "Driving experience:" << gr.driving_exp << endl; // driving experience
        cout << "Taxi model:" << gr.taxi_model << endl; // taxi model // need to fix error = not printing out user input
        cout << "Drivers' age: " << gr.age << endl; // drivers age
    }
    else if (gr.age > 60 && gr.driving_exp < 9) {
        cout << "sorry, but your cannot apply for this job";
    }
    else {
        cout << "Sorry, but you are not eligible";
    }
}


void driver_register()
{
    driver dr;
    cout << "Enter your first name";
    cin >> dr.first_name;

    cout << "Enter your last name";
    cin >> dr.last_name;

    dr.full_name = dr.first_name + " " + dr.last_name;

    cout << "Enter your gender";
    cin >> dr.gender;

    cout << "Enter your date of birth:";
    cin >> dr.Date_of_birth;

    cout << "Enter your nationality";
    cin >> dr.nationality;

    cout << "Enter your contact no:";
    cin >> dr.contact_no;

    cout << "Enter your address:";
    cin >> dr.email_address;

    //printing out user input enterd above

    cout << "Displaying driver details....    ";
    cout << "\n******************************" << endl;

    cout << "\nFull Name: " << dr.full_name << endl;
    cout << "\nAge: " << dr.gender;
    cout << "\nDate of birth: " << dr.Date_of_birth;
    cout << "\nNationality: " << dr.nationality;
    cout << "\nContact no: " << dr.contact_no;
    cout << "\nEmail address: " << dr.email_address;

    cout << "\n******************************" << endl;
}
//void driver_login)(){}
