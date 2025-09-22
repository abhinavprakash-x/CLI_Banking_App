#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>

//Template for customer information and abilities.
class customer{
    private:
        std::string account_number;
        std::string customer_name;
        std::string customer_password;
        double balance;
        double loan_amount;
        int wrong_password_attempts;
        int account_status;
    public:
        customer();
        customer(std::string acc_no, std::string name, std::string passwd, double bal, double loan_bal, int attempts, int status);
        void withdraw(double amount);
        void deposit(double amount);
        void transfer(std::string receiver_account_number, double amount);
        void change_password();
        void view_balance();
};

#endif