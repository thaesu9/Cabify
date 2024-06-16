#pragma once
#include<string>

struct general_register {
    int fulllicense;
    int full_license_version;
    int driving_exp;
    std::string taxi_model;
    int age;
};

struct driver {
    std::string d_email;
    std::string first_name;
    std::string last_name;
    std::string full_name;
    std::string gender;
    std::string Date_of_birth;
    std::string nationality;
    std::string contact_no;
    std::string email_address;
    int age;
    int full_drivers_license_no;
    int full_drivers_version_no;
    int driving_exp;
    int wof; // use array to get user input 3 numbers
};

void basic_details();
void eligibility_check();
