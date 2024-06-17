// Functions like macros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Demo2 Function-like Macros
#define circleArea(r) (3.1415 * r * r)

#include <iostream>
#define PI 3.1415

//macro that calculates area of circle
//and takes parameter 'r'
#define circle_area(r) (PI * r * r)

using namespace std;

int main()
{
    double radius = 2.5;

    //call the circle_area() macro
    //pass radius as an argument
    cout << "Area = " << circle_area(radius); //code circlearea(radiua); expands to 3.1415 * 2.5 * 2.5

}

// NOTE ; it is better to use functions rather than function-like macros are more error-prone