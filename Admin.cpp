#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <ctime>

#include "Cabify.h"

using namespace std;

extern Admin adm;

void adminLogin()
{
	cout << "\n Welcome to Admin Panel. Please login to proceed." << endl;

	string username, password;
	int times = 0;

	cout << "\n Username : ";
	cin >> username;

	cout << " Password : ";
	cin >> password;

	while ((username != adm.username || password != adm.password) && times < 2)
	{
		cout << "\n Wrong username and password! Try again." << endl;

		times++;
		adm.failedAttempts++;
		cout << "\n Username : ";
		cin >> username;

		cout << " Password : ";
		cin >> password;
	}

	if (username == adm.username && password == adm.password)
	{
		ClearScreen();
		adminMenu();
	}
	else
	{
		cout << "\n Login attempt failed. Press Enter to go back to main menu." << endl;
		cin.ignore();
		cin.get();
		ClearScreen();
		adm.attemptFailed = true;
	}
}

void adminMenu()
{
	while(true)
	{
		cout << "\n Please choose from following options to proceed." << endl;
		cout << "\n 1. Customer information" << endl;
		cout << " 2. Driver Information" << endl;
		cout << " 3. Trip Information" << endl;
		cout << " 4. Back" << endl;
		cout << " 5. Exit" << endl;
		int choice;
		cout << "\n Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			// customer information
			ClearScreen();
			customerInformation();
			break;

		case 2:
			// driver information
			ClearScreen();
			break;

		case 3:
			// trip information
			ClearScreen();
			break;

		case 4:
			// back to main menu
			ClearScreen();
			return;

		case 5:
			// exit
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


// Customer information
void customerInformation()
{
	string firstName, lastName, fullName, email;
	while (true)
	{
		cout << "\n Search Customer by " << endl;
		cout << "\n 1. Name" << endl;
		cout << " 2. Email" << endl;
		cout << " 3. Back" << endl;
		int choice;
		cout << "\n Choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			ClearScreen();

			// search by name
			cout << "\n Customer Details" << endl;
			cout << " -----------------" << endl;
			cout << " Enter Customer First Name : ";
			getline(cin, firstName);
			cout << " Enter Customer Last Name : ";
			getline(cin, lastName);
			fullName = firstName + " " + lastName;
			{
				bool found = false;
				for (const auto& cus : customers)
				{
					if (fullName == cus.fullName)
					{
						ClearScreen();
						cout << "\n Customer Details" << endl;
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
						}
						cout << " Visa Card      : " << cus.visaCard << "(" << cus.visaExp << ")" << endl;


						cout << "\n Press Enter to go back." << endl;
						cin.get();
						found = true;
						ClearScreen();
					}
				}
				if (!found)
				{
					cout << "\n Customer information not found. Press Enter to go back." << endl;
					cin.get();
					ClearScreen();
				}
			}
			break;

		case 2:
			ClearScreen();

			// search by email
			cout << "\n Customer Details" << endl;
			cout << " -----------------" << endl;
			cout << " Enter Customer Email : ";
			getline(cin, email);
			{
				bool found = false;
				for (const auto& cus : customers)
				{
					if (email == cus.email)
					{
						ClearScreen();
						cout << "\n Customer Details" << endl;
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
						}
						cout << " Visa Card      : " << cus.visaCard << "(" << cus.visaExp << ")" << endl;


						cout << "\n Press Enter to go back." << endl;
						cin.get();
						found = true;
						ClearScreen();
					}
				}
				if (!found)
				{
					cout << "\n Customer information not found. Press Enter to go back." << endl;
					cin.get();
					ClearScreen();
				}
			}
			break;

		case 3:
			// back to previous menu
			ClearScreen();
			return;

		default:
			ClearScreen();
			cout << "Invalid choice. Please choose again : " << endl;
			break;
			
		}



	}
}