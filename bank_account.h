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

    std::string account_number = "123";
    std::string pin = "123";

};
class bank_account {
public:
    static void deposit(int, double*);

    static void draw(int,double*);
    static double print_total(const double*);
    static void display_details(const double*, const std::string*);
    static bool check_pin(const std::string&,const std::string&);
    static bool check_account_number(const std::string&,const std::string&);

    static void time_limit();

    static void receipt(const double* , const std::string*, const std::string&);
};



#endif //BANK_ACCOUNT_H
