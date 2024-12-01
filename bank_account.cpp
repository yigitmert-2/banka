//
// Created by Yiğit Mert on 30.11.2024.
//

#include "bank_account.h"
#include <iostream>
#include <unordered_map>
#include <unistd.h>

void bank_account::deposit(int deposit_amount,double* total_amount_adress) {
    *total_amount_adress += deposit_amount;
}
void bank_account::draw(int draw_amount, double *total_amount_adress) {
    *total_amount_adress -= draw_amount;
}
double bank_account::print_total(double* total_amount_adress){
    return *total_amount_adress ;
}
void bank_account::display_details(double* total_amount, std::string* holder_name) {
    std::cout <<"the total amount is "<< *total_amount<<" and the account holders name is " << *holder_name;
}
account_detail detail;
bool bank_account::check_pin(std::string pin_input,std::string account_pin_adress = detail.get_pin()) {
    if (pin_input == account_pin_adress) {
        std::cout << "the pin number is correct ";
        return  1;
    }
    else {
        std::cout << "the pin number is not correct ";
        return 0;
    }
}

bool bank_account::check_account_number(std::string account_number_input,std::string account_number = detail.get_account_number()) {
    if (account_number_input == account_number) {
        std::cout << "the account number is correct ";
        return 1;
    }
    else {
        std::cout << "the account number is not correct ";
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
    sleep(30);
    std::cout << "you have exceeded your time limit";
    exit(0);
}




