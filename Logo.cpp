#include <iostream>
#include "Cabify.h"

using namespace std;

// function to print logo
void CabifyLogo()
{
    cout << "\033[1;33m"; // Set text color to bright yellow
    cout << " " << endl;
    cout << "                                ========                                     " << endl;
    cout << "                            ___/________\\___                                 " << endl;
    cout << "                           /                \\                                " << endl;
    cout << "                 _________/                  \\________                " << endl;
    cout << "                /       __   _   __  ___  __ _  _     \\               " << endl;
    cout << "               /      //    /_\\ |__|  |  |__ \\\\//      \\              " << endl;
    cout << "              /       \\\\__ /   \\|__| _|_ |    ||        \\             " << endl;
    cout << "             /     ______                      ______    \\            " << endl;
    cout << "            /_____|      |____________________|      |____\\           " << endl;
    cout << "                  |______|                    |______|                 " << endl;
    cout << "=============================================================================" << endl << endl;

    cout << "                            Welcome to CABIFY!                          " << endl;

    cout << "   This is Cabify, your Taxi service to make your journey pleasurable..." << endl;
  
    cout << "\n_____________________________________________________________________________" << endl;
    cout << "\033[0m"; // Reset text color to default
    
}
