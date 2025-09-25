#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>

//Template for customer information and abilities.
class customer{

    private:

        //customer information
        std::string account_number;
        std::string customer_name;
        std::string customer_password;
        double balance;
        double loan_amount;
        int wrong_password_attempts;
        int account_status;

    public:
        //constructors
        customer();
        customer(std::string acc_no, std::string name, std::string passwd, double bal, double loan_bal, int attempts, int status);
        
        //methods
        void withdraw();
        void deposit();
        void transfer();
        void change_password();
        void view_balance();
        void pay_loan();

        //functions used to load data from csv to program
        std::string get_account_number() const;
        std::string get_customer_name() const;
        std::string get_password() const;
        double get_balance() const;
        double get_loan_amount() const;
        int get_wrong_password_attempts() const;
        int get_account_status() const;
};

#endif