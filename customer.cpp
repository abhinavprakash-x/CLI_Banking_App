#include"customer.h"

customer::customer(){
    account_number = "";
    customer_name = "";
    customer_password = "";
    balance = 0.0;
    loan_amount = 0.0;
    wrong_password_attempts = 0;
    account_status = 0;
}

customer::customer(std::string acc_no, std::string name, std::string passwd, double bal, double loan_bal, int attempts, int status){
    account_number = acc_no;
    customer_name = name;
    customer_password = passwd;
    balance = bal;
    loan_amount = loan_bal;
    wrong_password_attempts = attempts;
    account_status = status;
}

void customer::withdraw(double amount){
    if(balance > amount){
        balance -= amount;
        if(balance < 500){
            std::cout<<"Balance Below Minimum Amount ₹100 deucted. \n";
            balance -= 100;
        }
    } else std::cout<<"Insufficient Funds\n";
}

void customer::deposit(double amount){
    balance += amount;
}

void customer::transfer(std::string receiver_account_number, double amount){
    //to do
}

void customer::change_password(){
    std::cout<<"Choose a New Password: \n";
    std::cout<<"NOTE: CHOOSE A STRONG PASSWORD!!!\n";
    std::cin>>customer_password;
}

void customer::view_balance(){
    std::cout<<"Your Current Balance is: "<< balance<< std::endl;
}

std::string customer::get_account_number() const { return account_number; }
std::string customer::get_customer_name() const { return customer_name; }
std::string customer::get_password() const { return customer_password; }
double customer::get_balance() const { return balance; }
double customer::get_loan_amount() const { return loan_amount; }
int customer::get_wrong_password_attempts() const { return wrong_password_attempts; }
int customer::get_account_status() const { return account_status; }

bool customer::login(){
    //todo
}