#include <iostream>

#include "bank_account.h"
#include <unordered_map>
#include <thread>
#include <unistd.h>
#include <fstream>
int main() {
    account_detail my_account_detail;
    bank_account  my_account;
    std::string account_number,pin;
    bool number_bool,pin_bool;
    std::cout << "please enter the account number of the account you are trying to access : ";
    std::cin>>account_number;
    number_bool = my_account.check_account_number(account_number,my_account_detail.get_account_number());
    std::cout << "please enter the pin : ";
    std::cin>>pin;
    pin_bool = my_account.check_pin(pin,my_account_detail.get_pin());
    if (number_bool == 1 && pin_bool == 1) {
        std::thread t1 ([&my_account]() {my_account.time_limit();});
        char loop;
        double var;
        std::unordered_map<std::string,int> string_to_case;
        string_to_case = {
        {"deposit",1}, {"draw",2}, {"details",3}, {"total",4}, {"e",5},{"receipt",6}
        };
        int answer;
        do {
            std::string ans;
            std::cout << "please type the transaction you would like to make : ";
            std::cin>>ans;

            answer = string_to_case[ans];
            switch (answer) {
                case 1:
                    std::cout << "enter the amount of the deposit : ";
                    std::cin>>var;
                    my_account.deposit(var, &my_account_detail.total_amount);
                    break;
                case 2:
                    std::cout << "enter the amount of the draw : ";
                    std::cin>>var;
                    my_account.draw(var, &my_account_detail.total_amount);
                    break;
                case 3:
                    my_account.display_details(&my_account_detail.total_amount, &my_account_detail.user_name);
                    break;
                case 4:

                    std::cout<<my_account.print_total(&my_account_detail.total_amount)<< " ";
                    break;
                case 5:
                    std::cout<<"transaction has ended. thank you.";
                    exit(0);
                case 6:
                    my_account.receipt(&my_account_detail.total_amount,&my_account_detail.user_name);
                    break;
                default:
                    std::cout << "please enter a valid option : ";
            }
        }       while(answer != 5);

        t1.join();
    }
    else {
        std::cout << "account number or pin is incorrect. Terminating session.";
    }
    return 0;
}
