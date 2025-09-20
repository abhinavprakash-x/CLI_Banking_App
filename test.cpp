#include"customer.h"
#include<iostream>
using namespace std;

int main(){
    customer temp_user = {"BKIS123","Abhinav","Abhi123",5000,0,0,0};
    temp_user.deposit(2000);
    temp_user.withdraw(1000);
    temp_user.view_balance();
    temp_user.change_password();
    return 0;
}