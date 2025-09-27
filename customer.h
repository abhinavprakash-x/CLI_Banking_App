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
        int password_attempts_remaining;
        int account_status;
        
        public:

        //constructors
        customer();
        customer(long acc_no, std::string name, std::string passwd, double bal, double loan_bal, int attempts, int status);
        
        //methods
        void withdraw();
        bool withdraw(double amount, bool silent = false);
        void deposit();
        bool deposit(double amount, bool silent = false);
        void transfer(std::vector<customer>& all_customers);
        void change_password();
        void view_balance();
        void pay_loan();

        void edit_loan_amount(int loan);
        void edit_password_attempts_remaining(int attempts);
        void edit_account_status(int status);

        //functions used to load data from csv to program
        long get_account_number() const;
        std::string get_customer_name() const;
        std::string get_password() const;
        double get_balance() const;
        double get_loan_amount() const;
        int get_password_attempts_remaining() const;
        int get_account_status() const;
};

#endif