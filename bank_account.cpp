//
// Created by Yiğit Mert on 30.11.2024.
//

#include "bank_account.h"
#include <iostream>
#include <unistd.h>
#include <fstream>
void bank_account::deposit(const int deposit_amount,double* total_amount_adress) {
    *total_amount_adress += deposit_amount;
}
void bank_account::draw(const int draw_amount, double *total_amount_adress) {
    *total_amount_adress -= draw_amount;
}
double bank_account::print_total(const double* total_amount_adress){
    return *total_amount_adress ;
}
void bank_account::display_details(const double* total_amount, const std::string* holder_name) {
    std::cout <<"the total amount is "<< *total_amount<<" and the account holders name is " << *holder_name<<std::endl;
}
account_detail detail;
bool bank_account::check_pin(const std::string& pin_input,const std::string& account_pin_adress = detail.get_pin()) {
    if (pin_input == account_pin_adress) {
        std::cout << "the pin number is correct "<<std::endl;
        return  1;
    }
    else {
        std::cout << "the pin number is not correct "<<std::endl;
        return 0;
    }
}

bool bank_account::check_account_number(const std::string& account_number_input,const std::string& account_number = detail.get_account_number()) {
    if (account_number_input == account_number) {
        std::cout << "the account number is correct "<<std::endl;
        return 1;
    }
    else {
        std::cout << "the account number is not correct "<<std::endl;
        return 0;
    }
}
std::string account_detail::get_account_number() {
    return account_number;
}

std::string account_detail::get_pin() {
    return pin;
}

void bank_account::time_limit() {
    sleep(50);
    std::cout << "you have exceeded your time limit";
    exit(0);
}

void bank_account::receipt(const double* total_amount, const std::string* user_name_adress,const std::string& account_number = detail.get_account_number()) {
    std::ofstream account_receipt;
    account_receipt.open("receipt.txt");
    account_receipt.is_open() ? std::cout<<"did open"<<std::endl : std::cout<<"didnt open"<<std::endl;
    account_receipt <<"The users name is : "<<*user_name_adress<<std::endl;
    account_receipt << "The users account number is : "<< account_number << std::endl;
    account_receipt <<"Total amount in your bank account is : "<< print_total(total_amount) << std::endl;
    account_receipt.close();
}




