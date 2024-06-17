#include <iostream>
#include <cstdlib>
#include "Cabify.h"

using namespace std;

// Clear console and print logo
void ClearScreen()
{
    system("cls");  // to clear the screen
    CabifyLogo();
}

// Main Menu
void MainMenu(int* choice)
{
    cout << "\n Kia Ora. Please choose ONE option from below." << endl;
    cout << " (By making a choice, you agree to our terms and conditions.)" << endl << endl;
    cout << " 1. Book a Cab. (Customer)" << endl;
    cout << " 2. Drive for Cabify. (Driver)" << endl;
    cout << " 3. Check Terms and Conditions." << endl;
    cout << " 9. Exit." << endl;
    // cout << " 6. Login as Admin" << endl;

    cout << "\n Choice: ";
    cin >> *choice;
}

// Terms and Conditions
void TermsConditions()
{
    cout << "\033[1m"; // Bold text
    cout << "\n                            Terms and Conditions" << endl;
    cout << "\033[0m"; // Reset
    cout << "                           ======================" << endl << endl;
    cout << "1. Introduction\n";
    cout << "---------------\n";
    cout << "Welcome to Cabify! These terms and conditions outline the rules and regulations for the use of Cabify's taxi booking services.\n\n";

    cout << "2. Definitions\n";
    cout << "----------------\n";
    cout << "Service: The taxi booking service provided by Cabify.\n";
    cout << "User: Any individual who uses the Service.\n";
    cout << "Driver: Any individual who operates a taxi and provides transportation services to Users.\n";
    cout << "Booking: A request made by a User for a taxi through the Service.\n\n";

    cout << "3. User Responsibilities\n";
    cout << "------------------------\n";
    cout << "Users must provide accurate and complete information when creating an account and making a booking.\n";
    cout << "Users are responsible for maintaining the confidentiality of their account information.\n";
    cout << "Users must ensure timely payment for the Service, either by cash or an accepted payment method.\n";
    cout << "Users must behave respectfully and responsibly towards drivers.\n\n";

    cout << "4. Driver Responsibilities\n";
    cout << "--------------------------\n";
    cout << "Drivers must provide accurate and complete information when registering with the Service.\n";
    cout << "Drivers must maintain valid licenses, insurance, and permits as required by law.\n";
    cout << "Drivers must ensure their vehicle is safe, clean, and in good working condition.\n";
    cout << "Drivers must behave respectfully and responsibly towards Users.\n\n";

    cout << "5. Booking and Cancellation\n";
    cout << "---------------------------\n";
    cout << "Users can book a taxi through the Cabify application or website.\n";
    cout << "Users must provide accurate pickup and drop-off locations and any special requirements.\n";
    cout << "Users may cancel a booking up to a specified time before the scheduled pickup without penalty. Cancellations made after this time may incur a fee.\n\n";

    cout << "6. Payment\n";
    cout << "----------------\n";
    cout << "Users must pay the fare as calculated by the Service at the end of the journey.\n";
    cout << "Accepted payment methods include cash and specified credit/debit cards.\n";
    cout << "In case of payment disputes, Cabify reserves the right to investigate and resolve the issue.\n\n";

    cout << "7. Liability\n";
    cout << "------------\n";
    cout << "Cabify is not liable for any personal injury, property damage, or other losses arising from the use of the Service, except where such liability is mandated by law.\n";
    cout << "Users and Drivers are responsible for their conduct and any consequences arising from their actions during the use of the Service.\n\n";

    cout << "8. Privacy\n";
    cout << "----------\n";
    cout << "Cabify collects and uses personal information as described in its Privacy Policy.\n";
    cout << "Users agree to the collection, use, and sharing of their personal information as outlined in the Privacy Policy.\n\n";

    cout << "9. Termination\n";
    cout << "Cabify reserves the right to terminate or suspend access to the Service for any User or Driver who violates these terms and conditions or engages in misconduct.\n";
    cout << "Users may terminate their account at any time by contacting Cabify customer support.\n\n";

    cout << "10. Changes to Terms and Conditions\n";
    cout << "-----------------------------------\n";
    cout << "Cabify reserves the right to modify these terms and conditions at any time. Changes will be effective upon posting on the Cabify website or application.\n";
    cout << "Continued use of the Service after changes are posted constitutes acceptance of the revised terms and conditions.\n\n";

    cout << "11. Governing Law\n";
    cout << "-----------------\n";
    cout << "These terms and conditions are governed by the laws of the country in which Cabify operates. Any disputes arising from the use of the Service shall be resolved in the courts of that country.\n\n";

    cout << "12. Contact Information\n";
    cout << "-----------------------\n";
    cout << "For any questions or concerns regarding these terms and conditions, please contact Cabify customer support at [email address] or [phone number].\n\n";

    cout << "13. Acceptance of Terms\n";
    cout << "-----------------------\n";
    cout << "By using the Service, Users and Drivers agree to comply with these terms and conditions.\n";

    cout << "\n\nPress Enter to return to main menu." << endl;
    cin.ignore();
    cin.get();

    ClearScreen();

}
