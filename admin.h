#ifndef ADMIN_H
#define ADMIN_H

#include<iostream>

//Template to define admin info and behaviours.
class admin{
    private:
        std::string admin_user_name;
        std::string admin_password = "Admin@123";
    public:
        admin();
        admin(std::string name, std::string passwd);
        void create_account();
        void delete_account();
        void give_interest();
        void deduct_bills();
        void unlock_account();
        void give_loan();
        void view_customer_info();
};


#endif