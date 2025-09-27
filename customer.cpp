#include"customer.h"

customer::customer(){
    account_number = 0;
    customer_name = "";
    customer_password = "";
    balance = 0.0;
    loan_amount = 0.0;
    password_attempts_remaining = 0;
    account_status = 0;
}

customer::customer(long acc_no, std::string name, std::string passwd, double bal, double loan_bal, int attempts, int status){
    account_number = acc_no;
    customer_name = name;
    customer_password = passwd;
    balance = bal;
    loan_amount = loan_bal;
    password_attempts_remaining = attempts;
    account_status = status;
}

void customer::withdraw(const AppConfig& config){
    float amount;
    std::cout<< "Enter The Amount of Money to Withdraw: ";
    std::cin>> amount;
    this->withdraw(amount, config, false);
}

bool customer::withdraw(double amount, const AppConfig& config, bool silent){

    if(amount<0) {std::cout<<"Negative Money !!"; return false;}

    if(balance >= amount){
        balance -= amount;
        if(!silent) std::cout << "Transaction Successful.\n";

        if(balance < config.minimum_balance){
            balance -= config.minimum_balance_charge;
            if(!silent) std::cout << "Balance is below minimum. A charge of " << config.minimum_balance_charge << " has been deducted.\n";
        }
        return true;

    } else {
        if(!silent) std::cout << "Transaction Failed: Insufficient Funds.\n";
        return false;
    }
}

void customer::deposit(){
    float amount;
    std::cout<< "Enter The Amount of Money to Deposit: ";
    std::cin>> amount;
    this->deposit(amount,false);
}

bool customer::deposit(double amount, bool silent){
    if(amount<0) {std::cout<<"Negative Money !!"; return false;}
    balance += amount;
    if(!silent) std::cout << "Transaction Successful.\n";
    return true;
}

void customer::transfer(std::vector<customer>& all_customers, const AppConfig& config){

    long receiver_account_no;
    float amount;
    std::cout<<"Enter the Account Number to Transfer Funds: ";
    std::cin>> receiver_account_no;
    std::cout<< "Enter The Amount of Money to Transfer: ";
    std::cin>> amount;

    customer *receiver = nullptr;
    for(customer &user: all_customers){
        if(user.get_account_number() == receiver_account_no){
            receiver = &user;
            break;
        }
    }

    if(receiver != nullptr){
        // Only deposit if the withdrawal from this account succeeds
        if(this->withdraw(amount, config, false)){
            receiver->deposit(amount, false);
            std::cout << "Transfer to account " << receiver_account_no << " was successful.\n";
        }
    } else {
        std::cout << "Error: Receiver account not found.\n";
    }
}

void customer::change_password(){
    std::cout<<"Choose a New Password: \n";
    std::cout<<"NOTE: CHOOSE A STRONG PASSWORD!!!\n";
    std::cin>>customer_password;
    std::cout<< "Password Updated Successfully.\n";

}

void customer::view_balance(){
    std::cout<<"Your Current Balance is: "<< balance<< std::endl;
    std::cout<<"You Have Loan Due of: "<< loan_amount;
}

void customer::pay_loan(const AppConfig& config){
    std::cout<<"The Amount Will be Deducted from your Account.\n";
    float amount;
    std::cout<< "Enter The Amount of Money to Pay Loan: ";
    std::cin>> amount;
    if(amount<0) {std::cout<<"Negative Money !!"; return;}
    if(amount>loan_amount) {std::cout<<"You Don't have that much Due"; return;}
    if (this->withdraw(amount, config, true)) {
        this->edit_loan_amount(this->get_loan_amount() - amount);
        std::cout << "Loan payment of Rs." << amount << " was successful.\n";
        std::cout << "Remaining Loan Due: Rs." << this->get_loan_amount() << std::endl;
    }
}

long customer::get_account_number() const { return account_number; }
std::string customer::get_customer_name() const { return customer_name; }
std::string customer::get_password() const { return customer_password; }
double customer::get_balance() const { return balance; }
double customer::get_loan_amount() const { return loan_amount; }
int customer::get_password_attempts_remaining() const { return password_attempts_remaining; }
int customer::get_account_status() const { return account_status; }

void customer::edit_account_status(int status) { account_status = status; }
void customer::edit_password_attempts_remaining(int attempts) { password_attempts_remaining = attempts; }
void customer::edit_loan_amount(float loan) { loan_amount = loan; }