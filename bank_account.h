//
// Created by Yiğit Mert on 30.11.2024.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>

class account_detail {

public:
    double total_amount = 0;
    std::string user_name = "joe";
    std::string get_account_number();
    std::string get_pin();
private:

    std::string account_number = "1234567890";
    std::string pin = "1234";

};


class bank_account {
public:
    void deposit(int,double*);
    void draw(int,double*);
    double print_total(double*);
    void display_details(double*, std::string*);
    bool check_pin(std::string,std::string);
    bool check_account_number(std::string,std::string);
    void time_limit();
};



#endif //BANK_ACCOUNT_H
