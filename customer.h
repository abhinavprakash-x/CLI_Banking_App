#ifndef CUSTOMER_H
#define CUSTOMER_H

static constexpr double MINIMUM_BALANCE = 500.0;
static constexpr double MINIMUM_BALANCE_CHARGE = 100.0;

#include<iostream>
#include<vector>

//Template for customer information and abilities.
class customer{

    private:

        //customer information
        long account_number;
        std::string customer_name;
        std::string customer_password;
        double balance;
        double loan_amount;
        
        public:

        //These infomation are stored in public so they can be accessed and modified directly while program is executing
        int wrong_password_attempts;
        int account_status;

        //constructors
        customer();
        customer(long acc_no, std::string name, std::string passwd, double bal, double loan_bal, int attempts, int status);
        
        //methods
        void withdraw();
        void withdraw(double amount);
        void deposit();
        void deposit(double amount);
        void transfer(std::vector<customer>& all_customers);
        void change_password();
        void view_balance();
        void pay_loan();

        //functions used to load data from csv to program
        long get_account_number() const;
        std::string get_customer_name() const;
        std::string get_password() const;
        double get_balance() const;
        double get_loan_amount() const;
        int get_wrong_password_attempts() const;
        int get_account_status() const;
};

#endif