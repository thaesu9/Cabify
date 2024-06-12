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
			driverInformation();
			break;

		case 3:
			// trip information
			ClearScreen();
			TripInformation();
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
		cout << " 3. View all customers " << endl;
		cout << " 4. Back" << endl;
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
						cout << " Visa Card      : " << cus.visaCard << " (" << cus.visaExp << ")" << endl;


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
						cout << " Visa Card      : " << cus.visaCard << " (" << cus.visaExp << ")" << endl;


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
			// view all customers
			ClearScreen();
			cout << "\n All Customers Information " << endl;
			cout << " =========================================" << endl;
			for (const auto& cus : customers)
			{
				cout << "\n Name           : " << cus.fullName << endl;
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
				cout << " Visa Card      : " << cus.visaCard << " (" << cus.visaExp << ")" << endl << endl;
				cout << " -----------------------------------------" << endl << endl;
			}
			cout << "\n Press Enter to go back." << endl;
			cin.get();

			ClearScreen();
			break;

		case 4:
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

// Driver information
void driverInformation()
{
	string firstName, lastName, fullName, ID;
	while (true)
	{
		cout << "\n Search Driver by " << endl;
		cout << "\n 1. Name" << endl;
		cout << " 2. Driver ID" << endl;
		cout << " 3. View all drivers" << endl;
		cout << " 4. Back" << endl;
		int choice;
		cout << "\n Choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			ClearScreen();

			// search by name
			cout << "\n Driver Details" << endl;
			cout << " -----------------" << endl;
			cout << " Enter Driver First Name : ";
			getline(cin, firstName);
			cout << " Enter Driver Last Name : ";
			getline(cin, lastName);
			fullName = firstName + " " + lastName;
			{
				bool found = false;
				for (const auto& driver : drivers)
				{
					if (fullName == driver.fullName)
					{
						ClearScreen();
						cout << "\n Driver Details" << endl;
						cout << " -----------------------------------------" << endl;
						cout << " Cabify ID       : " << driver.driverID << endl;
						cout << " Name            : " << driver.fullName << endl;
						cout << " Age             : " << driver.age << endl;
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
						cout << " Driving Experience : " << driver.drivingExp << endl;
						cout << " Driver License     : " << driver.D_licenseNum << endl;
						cout << " License Version    : " << driver.D_licenseVersion << endl;
						cout << " License Expiry     : " << driver.licenseExpireDate << endl << endl;
						cout << " Bank Account       : " << driver.bankAcc << " (" << driver.bankName << " Bank)" << endl << endl;

						cout << "\n Vehicle Details of Driver ID " << driver.driverID << endl;
						cout << " -----------------------------------------" << endl;
						cout << " Car Model           : " << driver.carModel << endl;
						cout << " Car Licence Plate   : " << driver.licensePlate << endl;
						cout << " Car Production Year : " << driver.carYear << endl;
						cout << " WOF Expiry Date     : " << driver.WOFexpire << endl << endl;

						cout << "\n Press Enter to go back." << endl;
						cin.get();
						found = true;
						ClearScreen();
					}
				}
				if (!found)
				{
					cout << "\n Driver information not found. Press Enter to go back." << endl;
					cin.get();
					ClearScreen();
				}
			}
			break;

		case 2:
			ClearScreen();

			// search by driver ID
			cout << "\n Driver Details" << endl;
			cout << " -----------------" << endl;
			cout << " Enter Driver ID : ";
			getline(cin, ID);
			{
				bool found = false;
				for (const auto& driver : drivers)
				{
					if (ID == driver.driverID)
					{
						ClearScreen();
						cout << "\n Driver Details" << endl;
						cout << " -----------------------------------------" << endl;
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

						cout << "\n Vehicle Details of Driver ID " << driver.driverID << endl;
						cout << " -----------------------------------------" << endl;
						cout << " Car Model           : " << driver.carModel << endl;
						cout << " Car Licence Plate   : " << driver.licensePlate << endl;
						cout << " Car Production Year : " << driver.carYear << endl;
						cout << " WOF Expiry Date     : " << driver.WOFexpire << endl << endl;


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
			// view all drivers
			ClearScreen();

			cout << "\n All Drivers Information " << endl;
			cout << " =========================================" << endl;
			for (const auto& driver : drivers)
			{
				cout << "\n Driver ID " << driver.driverID << endl;
				cout << " -----------------------------------------" << endl;
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

				cout << "\n Vehicle Details of Driver ID " << driver.driverID << endl;
				cout << " -----------------------------------------" << endl;
				cout << " Car Model           : " << driver.carModel << endl;
				cout << " Car Licence Plate   : " << driver.licensePlate << endl;
				cout << " Car Production Year : " << driver.carYear << endl;
				cout << " WOF Expiry Date     : " << driver.WOFexpire << endl << endl;
				cout << " -----------------------------------------" << endl << endl;

			}
			
			cout << "\n Press Enter to go back." << endl;
			cin.get();

			ClearScreen();
			break;

		case 4:
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

void TripInformation()
{
	long int tripID;
	while (true)
	{
		cout << "\n Trip Information " << endl;
		cout << "\n 1. View all trips" << endl;
		cout << " 2. Search by Trip ID" << endl;
		cout << " 3. Back" << endl;
		int choice;
		cout << "\n Choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			ClearScreen();
			// view all trips
			cout << "\n Trip Information " << endl;
			cout << " -------------------------------" << endl;
			for (const auto& trip : journey)
			{
				cout << " Trip ID           : " << trip.tripID << endl;
				cout << " Customer Name     : " << trip.customerName << endl;
				cout << " Driver ID         : " << trip.driverID << endl;
				cout << " Driver Name       : " << trip.driverName << endl;
				cout << " Pick up location  : " << trip.tripStart << endl;
				cout << " Drop off location : " << trip.tripEnd << endl;
				cout << " Booking Date      : " << trip.bookingDate << endl;
				cout << " Booking Time      : " << trip.bookingTime << endl;
				cout << " Total Passengers  : " << trip.passengers << endl;
				cout << " Total Luggages    : " << trip.luggage << endl;

				if (trip.specialN == 1)
					cout << " Special Request   : None " << endl;
				else if (trip.specialN == 2)
					cout << " Special Request   : I have a baby " << endl;
				else if (trip.specialN == 3)
					cout << " Special Request   : I need special aid " << endl;
				else
					cout << " Special Request   : None " << endl;

				if (trip.tripStatus == true)
					cout << " Trip Status : Completed " << endl << endl;
				else
					cout << " Trip Status : Cancelled " << endl << endl;

				
			}
			cout << "\n Press Enter to go back." << endl;
			cin.get();

			ClearScreen();
			break;

		case 2: 
			ClearScreen();
			// search by trip ID
			cout << "\n Enter Trip ID : ";
			cin >> tripID;
			cin.ignore();
			{
				bool found = 0;
				for (auto& trip : journey)
				{
					if (tripID == trip.tripID)
					{
						ClearScreen();
						cout << "\n Trip Information Details" << endl;
						cout << " -------------------------------" << endl;
						cout << " Trip ID           : " << trip.tripID << endl;
						cout << " Customer Name     : " << trip.customerName << endl;
						cout << " Driver ID         : " << trip.driverID << endl;
						cout << " Driver Name       : " << trip.driverName << endl;
						cout << " Pick up location  : " << trip.tripStart << endl;
						cout << " Drop off location : " << trip.tripEnd << endl;
						cout << " Booking Date      : " << trip.bookingDate << endl;
						cout << " Booking Time      : " << trip.bookingTime << endl;
						cout << " Total Passengers  : " << trip.passengers << endl;
						cout << " Total Luggages    : " << trip.luggage << endl;

						if (trip.specialN == 1)
							cout << " Special Request   : None " << endl;
						else if (trip.specialN == 2)
							cout << " Special Request   : I have a baby " << endl;
						else if (trip.specialN == 3)
							cout << " Special Request   : I need special aid " << endl;
						else
							cout << " Special Request   : None " << endl;

						if (trip.tripStatus == true)
							cout << " Trip Status : Completed " << endl << endl;
						else
							cout << " Trip Status : Cancelled " << endl << endl;

						cout << "\n Press Enter to go back." << endl;
						cin.get();
						found = true;
						ClearScreen();
					}
				}
				if (!found)
				{
					cout << "\n Trip information not found. Press Enter to go back." << endl;
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