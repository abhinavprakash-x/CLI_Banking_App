//Include all required Headers
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

#include"customer.h"
#include"admin.h"


//Functions needed in this program
int main_menu();
int admin_menu(bool login);
int customer_menu(bool login);
void save_all_customers(const std::vector<customer>& customers, const std::string& filename);
std::vector<customer> load_all_customers(const std::string& filename);



int main(){
    //load data from csv file
    const std::string FILENAME = "customers.csv";
    std::vector <customer> all_customers = load_all_customers(FILENAME);

    
    //CLI
    int repeat = 1, user_choice_main, user_choice_admin, user_choice_customer;
    do{
        start:
        user_choice_main = main_menu();

        if(user_choice_main == 1){

            admin Admin_user;
            bool login = Admin_user.login();
            admin_start:
            user_choice_admin = admin_menu(login);

            switch(user_choice_admin){
                case -1: goto start;
                case 1: Admin_user.create_account(); break;
                case 2: Admin_user.delete_account(); break;
                case 3: Admin_user.withdraw(); break;
                case 4: Admin_user.deposit(); break;
                case 5: Admin_user.transfer(); break;
                case 6: Admin_user.give_interest(); break;
                case 7: Admin_user.deduct_bills(); break;
                case 8: Admin_user.view_customer_info(); break;
                case 9: Admin_user.give_loan(); break;
                case 10: Admin_user.unlock_account(); break;
                case 11: goto start;
                default: std::cout<<"Wrong Option Selected\n";
            }
            goto admin_start;

        }else if(user_choice_main == 2){

            customer Customer_user;
            bool login = Customer_user.login();
            user_choice_customer = customer_menu(login);

        }else if(user_choice_main == 3){

            save_all_customers(all_customers, FILENAME);
            std::cout<< "Data Saved";
            return 0;

        }
        else std::cout<<"Wrong Option Selected\n";
    } while(repeat == 1);
}







//Load values from csv to program memory
std::vector<customer> load_all_customers(const std::string& filename) {
    std::vector<customer> customers;
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "No existing data file found. Starting fresh." << std::endl;
        return customers;
    }
    std::string line;
    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string token;

        // Variables to hold the parsed data
        std::string acc_no, name, passwd;
        double bal, loan_bal;
        int attempts, status;

        // Parse the CSV line
        getline(ss, token, ','); acc_no = token;
        getline(ss, token, ','); name = token;
        getline(ss, token, ','); passwd = token;
        getline(ss, token, ','); bal = std::stod(token); // stod = string to double
        getline(ss, token, ','); loan_bal = std::stod(token);
        getline(ss, token, ','); attempts = std::stoi(token); // stoi = string to integer
        getline(ss, token, ','); status = std::stoi(token);

        // Create a customer object and add it to the vector
        customers.emplace_back(acc_no, name, passwd, bal, loan_bal, attempts, status);
    }

    inFile.close();
    std::cout << "Customer data loaded successfully." << std::endl;
    return customers;
}

//Save values back to the CSV files
void save_all_customers(const std::vector<customer>& customers, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
        return;
    }

    // Loop through each customer in the vector
    for (const auto& cust : customers) {
        // Write the data to the file, separated by commas
        outFile << cust.get_account_number() << ","
            << cust.get_customer_name() << ","
            << cust.get_password() << ","
            << cust.get_balance() << ","
            << cust.get_loan_amount() << ","
            << cust.get_wrong_password_attempts() << ","
            << cust.get_account_status() << std::endl; // endl creates a new line
    }

    outFile.close();
    std::cout << "Data successfully saved." << std::endl;
}

int main_menu(){
    system("cls");
    int user_choice;
    std::cout<<"*******************************************************\n";
    std::cout<<"\t\t CLI Banking App \n";
    std::cout<<"*******************************************************\n";
    std::cout<<"\t (1) Admin Login \n\t (2) Customer Login \n\t (3) Exit Application\n";
    std::cin>> user_choice;
    return user_choice;
}

int admin_menu(bool login){
    if(login){
        int user_choice;
        system("cls");
        std::cout<<"*******************************************************\n";
        std::cout<<"\t\t CLI Banking App \n";
        std::cout<<"*******************************************************\n";
        std::cout<<"\t (1) Create New Bank Account \n";
        std::cout<<"\t (2) Delete an Existing Bank Account \n";
        std::cout<<"\t (3) Withdraw From a Bank Account \n";
        std::cout<<"\t (4) Deposit to a Account \n";
        std::cout<<"\t (5) Transfer Funds From one Account to Another \n";
        std::cout<<"\t (6) Give Interest to all Bank Accounts \n";
        std::cout<<"\t (7) Deduct Bills from all Bank Accounts \n";
        std::cout<<"\t (8) View Bank Account Details \n";
        std::cout<<"\t (9) Add Loan to a Bank Account \n";
        std::cout<<"\t (10) Unlock a Bank Account \n";
        std::cout<<"\t (11) Go Back To Main Menu \n";
        std::cin>> user_choice;
        return user_choice;
    }else{
        int temp;
        std::cout<<"Invalid Credentials";
        std::cin>> temp;
        return -1;
    }
}

int customer_menu(bool login){
    int user_choice;
    system("cls");
    std::cout<<"*******************************************************\n";
    std::cout<<"\t\t CLI Banking App \n";
    std::cout<<"*******************************************************\n";
    std::cout<<"\t (1) Withdraw Funds \n";
    std::cout<<"\t (2) Deposit Funds \n";
    std::cout<<"\t (3) Transfer Funds \n";
    std::cout<<"\t (4) View Balance \n";
    std::cout<<"\t (5) Change Password \n";
    std::cin>> user_choice;
    return user_choice;
}