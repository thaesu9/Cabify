// Final_Driver code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<iostream>
#include<string>
#include"FDC.h"
using namespace std;

int main() {
    driver dr;//instance created for struct data type

    //Welcome screen 
    cout << "********************" << endl;
    cout << " WELCOME TO CABIFY! " << endl;
    cout << "********************" << endl;

    eligibility_check(); //function for eligibility check


    return 0;
}