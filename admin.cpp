#include"admin.h"

//Helper function to find customer to do specific functions on like withdraw etc.
namespace { // Using an anonymous namespace keeps this function private to this file

    int find_customer(const std::vector<customer>& all_customers, const long& acc_no) {
        for (size_t i = 0; i < all_customers.size(); ++i) {
            if (all_customers[i].get_account_number() == acc_no) {
                return i; // Found the customer, return their index
            }
        }
        return -1; // Sentinel value indicating customer not found
    }

}

//define functions of admin header file
bool admin::login(const std::string& correct_password){
    std::string passwd;
    std::cout<<"Welcome Admin !!\nEnter Your Password to Continue: ";
    std::cin>> passwd;
    if(passwd == correct_password) return true;
    else return false;
}

void admin::create_account(std::vector<customer>& all_customers){

    std::string name;
    std::string password;
    double initial_deposit;

    std::cout << "\n--- Create New Customer Account ---" << std::endl;
    std::cin.ignore(1000, '\n'); 
    
    std::cout << "Enter customer's full name: ";
    std::getline(std::cin, name);
    std::cout << "Enter a temporary password for the account: ";
    std::cin >> password;

    std::cout << "Enter initial deposit amount (minimum 500): ";
    std::cin >> initial_deposit;
    if (initial_deposit < 500) {
        std::cout << "\nError: Initial deposit must be at least 500." << std::endl;
        std::cout << "Account creation failed." << std::endl;
        return;
    }

    // --- Generate a New, Unique Account Number ---
    long last_acc_num = 1000; // A starting point in case the customer list is empty
    if (!all_customers.empty()) {
        // Find the account number of the last customer in the vector
        long last_acc_no_str = all_customers.back().get_account_number();
        last_acc_num = last_acc_no_str;
    }
    long new_acc_no_str = last_acc_num + 1;

    // --- Create and Add the New Customer Object ---
    // Customer constructor: acc_no, name, passwd, bal, loan_bal, attempts, status
    customer new_customer(new_acc_no_str, name, password, initial_deposit, 0.0, 4, 1);
    all_customers.push_back(new_customer);

    // --- Provide Feedback ---
    std::cout << "\nAccount created successfully!" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "New Account Number is: " << new_acc_no_str << std::endl;
    std::cout << "Customer Name: " << name << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void admin::delete_account(std::vector<customer>& all_customers){
    long acc_no;
    std::cout << "Enter account number to DELETE: ";
    std::cin >> acc_no;

    int index = find_customer(all_customers, acc_no);
    if (index != -1) {
        // Customer found, remove them from the vector
        std::string temp;
        std::cout<<"Type DELETE to confirm Deletion: ";
        std::cin>>temp;
        if(temp == "DELETE"){
            all_customers.erase(all_customers.begin() + index);
            std::cout << "Account " << acc_no << " has been successfully deleted." << std::endl;
        }else{
            std::cout<<"Account "<< acc_no <<" was not deleted. \n";
        }
    } else {
        std::cout << "Error: Customer not found." << std::endl;
    }
}

void admin::withdraw(std::vector<customer>& all_customers, const AppConfig& config){
    long acc_no;
    double amount;
    std::cout<<"Enter Account number to withdraw from: ";
    std::cin>>acc_no;
    std::cout<<"Enter The Amount to Withdraw: ";
    std::cin>> amount;

    int index = find_customer(all_customers, acc_no);
    
    if (index != -1) {
        customer& current_customer = all_customers[index];
        current_customer.withdraw(amount, false, config); // Use the customer's own deposit method
    } else {
        std::cout << "Error: Customer not found." << std::endl;
    }
}

void admin::deposit(std::vector<customer>& all_customers){
    long acc_no;
    double amount;
    std::cout << "Enter account number to deposit into: ";
    std::cin >> acc_no;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;
    //I am not Checking for negative amounts in Admin activities because Admin must know not to put negative values also because I am lazy :)

    int index = find_customer(all_customers, acc_no);
    
    if (index != -1) {
        customer& current_customer = all_customers[index];
        current_customer.deposit(amount, false); // Use the customer's own deposit method
    } else {
        std::cout << "Error: Customer not found." << std::endl;
    }
}

void admin::transfer(std::vector<customer>& all_customers, const AppConfig& config){

    long receiver_acc_no, sender_acc_no;
    double amount;
    std::cout<<"Enter Sender's Account No: ";
    std::cin>>sender_acc_no;
    std::cout<<"Enter Receiver's Account No: ";
    std::cin>>receiver_acc_no;
    std::cout<<"Amount to be Transferred: ";
    std::cin>> amount;

    int sender_index = find_customer(all_customers, sender_acc_no);
    int receiver_index = find_customer(all_customers, receiver_acc_no);
    
    if(sender_index != -1 && receiver_index != -1){
        customer &sender = all_customers[sender_index];
        customer &receiver = all_customers[receiver_index];
        
        if(sender.withdraw(amount, true, config)){
            receiver.deposit(amount, true);
            std::cout << "Transaction Successful.\n";
        }
    }else{
        std::cout << "Transaction Failed: Invalid Sender or Receiver Account Number.\n";
    }

}

void admin::give_interest(std::vector<customer>& all_customers, double interest_rate){

    for(customer &user : all_customers){
        double interest_amount = user.get_balance() * interest_rate;
        // Deposit the interest amount silently
        user.deposit(interest_amount, true);
    }
    std::cout << "Interest of " << interest_rate * 100 << "% has been successfully applied to all accounts." << std::endl;

}

void admin::loan_interest(std::vector<customer>& all_customers, double loan_charge, double maintenance_charge) {
    for (customer& user : all_customers) {
        user.withdraw(maintenance_charge, true);
        double interest_amount = user.get_loan_amount() * loan_charge;
        user.edit_loan_amount(user.get_loan_amount() + interest_amount);
    }
    std::cout << "Maintenance Charges Deducted from all Accounts.\nLoan Interest Added to Accounts having loan.\n";
}

void admin::unlock_account(std::vector<customer>& all_customers){
    long acc_no;
    std::cout<<"Enter Account Number to Unlock: ";
    std::cin>>acc_no;
    int index = find_customer(all_customers, acc_no);

    if(index!=-1){
        customer& current_customer = all_customers[index];
        current_customer.edit_account_status(1);
        current_customer.edit_password_attempts_remaining(4);
        std::cout<<"Congrats! Account is Now ACTIVE.\n";
    }else{
        std::cout<<"Account Not Found.\n";
    }
}

void admin::give_loan(std::vector<customer>& all_customers){
    long acc_no;
    std::cout<<"Enter the Account Number of User: ";
    std::cin>>acc_no;
    int index = find_customer(all_customers, acc_no);

    if(index!=-1){
        customer& current_customer = all_customers[index];
        std::cout<<"Enter The Amount of Loan to Approve: ";
        float loan;
        std::cin>>loan;
        current_customer.edit_loan_amount(current_customer.get_loan_amount() + loan);
        std::cout<<"Transaction Successful. \n";
    }
}

void admin::view_customer_info(const std::vector<customer>& all_customers){

    long acc_no;
    std::cout<<"Enter the Account Number of User: ";
    std::cin>>acc_no;
    int index = find_customer(all_customers, acc_no);

    if(index != -1){
        const customer& current_customer = all_customers[index];
        std::cout << "\n--- Customer Details ---" << std::endl;
        std::cout << "Account Number: " << current_customer.get_account_number() << std::endl;
        std::cout << "Customer Name:  " << current_customer.get_customer_name() << std::endl;
        std::cout << "Balance:        Rs." << current_customer.get_balance() << std::endl;
        std::cout << "Loan Amount:    Rs." << current_customer.get_loan_amount() << std::endl;
        std::cout << "Account Status: ";
        if(current_customer.get_account_status() == 1) std::cout<<"Active. \n";
        else std::cout<<"Locked. \n";
        std::cout << "------------------------" << std::endl;
    } else {
        std::cout << "Error: Customer with account number '" << acc_no << "' not found." << std::endl;
    }
}