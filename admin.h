#ifndef ADMIN_H
#define ADMIN_H

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
        void give_interest(std::vector<customer>& all_customers);
        void deduct_bills(std::vector<customer>& all_customers);
        void unlock_account(std::vector<customer>& all_customers);
        void give_loan(std::vector<customer>& all_customers);
        void view_customer_info(const std::vector<customer>& all_customers);
};

#endif