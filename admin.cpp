#include"admin.h"

//define functions of admin header file
bool admin::login(){
    std::string passwd;
    std::cout<<"Welcome Admin !!\nEnter Your Password to Continue: ";
    std::cin>> passwd;
    if(passwd == admin_password) return true;
    else return false;
}

void admin::create_account(){
    //todo
}

void admin::delete_account(){
    //todo
}

void admin::withdraw(){
    //todo
}

void admin::deposit(){
    //todo
}

void admin::transfer(){
    //todo
}

void admin::give_interest(){
    //todo
}

void admin::deduct_bills(){
    //todo
}

void admin::unlock_account(){
    //todo
}

void admin::give_loan(){
    //todo
}

void admin::view_customer_info(){
    //todo
}