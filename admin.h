#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>

//Template to define admin info and behaviours.
class admin{
    public:
        std::string admin_password = "Admin@123"; //password is hardcoded need to change this.
        //admin();
        void create_account();
        void delete_account();
        void give_interest();
        void deduct_bills();
        void unlock_account();
        void give_loan();
        void view_customer_info();
};

#endif