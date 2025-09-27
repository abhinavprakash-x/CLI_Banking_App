#ifndef ADMIN_H
#define ADMIN_H

static constexpr float INTEREST_RATE = 0.055; //5.5% interest on savings account
static constexpr float LOAN_CHARGE = 0.095; //9.5% interest to be paid for loans
static constexpr int MAINTENANCE_CHARGE = 0; //Because My bank is a good bank but if you want you can charge it :)

#include<iostream>
#include<vector>
#include"customer.h"

//Template to define admin info and behaviours.
class admin{
    public:
        std::string admin_password = "Admin@123"; //password is hardcoded need to change this.
        //admin();
        bool login();
        void create_account(std::vector<customer>& all_customers);
        void delete_account(std::vector<customer>& all_customers);
        void withdraw(std::vector<customer>& all_customers);
        void deposit(std::vector<customer>& all_customers);
        void transfer(std::vector<customer>& all_customers);

        //these two functions should be execute automatically every month/year but I dont know how to do that so Admin will manually do this
        void give_interest(std::vector<customer>& all_customers);
        void loan_interest(std::vector<customer>& all_customers);

        void unlock_account(std::vector<customer>& all_customers);
        void give_loan(std::vector<customer>& all_customers);
        void view_customer_info(const std::vector<customer>& all_customers);
};

#endif