#pragma once
#include<string>
//eligibility check for driver age + driving exp
struct general_register {
    int driving_exp;
    int age;
};

//full driver registration
struct driver {
    std::string d_email;
    std::string first_name;
    std::string last_name;
    //std::string full_name;
    std::string gender;
    std::string Date_of_birth;
    std::string nationality;
    std::string contact_no;
    std::string email_address;
    //vechicle details
    std::string vehicle_model;
    std::string vechicle_license_letters;
    int vehicle_license_number;
    int version_number;
    int vehicle_year;
    int age;
    int full_drivers_license_no;
    int full_drivers_exp;
    int day;
    int month;
    int year;
    int driving_exp;
};


//struct data type to store user information
struct driver_pay {
    int account_no;
};

//union datat type stores Warrant of fitness details 
union driver_WOF {
    int day;
    int month;//4 no
    int year;//2 no
};

//union data type to store full drivers license details
union driver_LIC {
    int bank_account_no;
};

//store driver warrant of fitness details
void WOF();

//store driver payment details
void driver_payment();

//driver eligibility check first before registration
void eligibility_check();

//driver registration function
void driver_register();


