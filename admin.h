#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>
#include<vector>
#include"customer.h"

//Template to define admin info and behaviours.
class admin{
    public:

        bool login(const std::string& correct_password);
        void create_account(std::vector<customer>& all_customers);
        void delete_account(std::vector<customer>& all_customers);
        void withdraw(std::vector<customer>& all_customers, const AppConfig& config);
        void deposit(std::vector<customer>& all_customers);
        void transfer(std::vector<customer>& all_customers, const AppConfig& config);

        //these two functions should be execute automatically every month/year but I dont know how to do that so Admin will manually do this
        void give_interest(std::vector<customer>& all_customers, double interest_rate);
        void loan_interest(std::vector<customer>& all_customers, double loan_charge, double maintenance_charge);

        void unlock_account(std::vector<customer>& all_customers);
        void give_loan(std::vector<customer>& all_customers);
        void view_customer_info(const std::vector<customer>& all_customers);
};

#endif