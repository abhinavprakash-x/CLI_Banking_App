//Include all required Headers
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

#include"customer.h"
#include"admin.h"

//Functions needed in this program
void about_menu(const AppConfig& config);
int main_menu();
int admin_menu();
void customer_login(std::vector <customer> &all_customers, const AppConfig& config);
void customer_menu(customer &logged_in_customer, std::vector <customer> &all_customers, const AppConfig& config);
int option_input();
void save_all_customers(const std::vector<customer>& customers, const std::string& filename);
std::vector<customer> load_all_customers(const std::string& filename);
AppConfig load_config(const std::string& filename);


int main(){

    //load data from csv file
    const AppConfig config = load_config("config1.txt");
    const std::string FILENAME = "customers.csv";
    std::vector <customer> all_customers = load_all_customers(FILENAME);

    
    //CLI
    int user_choice_main=0;
    while(user_choice_main!=3){
        user_choice_main = main_menu();

        if(user_choice_main == 1){

            admin Admin_user;
            if (Admin_user.login(config.admin_password)) {

                int user_choice_admin = 0;
                while(user_choice_admin!=11){
                    user_choice_admin = admin_menu();
    
                    switch(user_choice_admin){
                        case 1: Admin_user.create_account(all_customers); break;
                        case 2: Admin_user.delete_account(all_customers); break;
                        case 3: Admin_user.withdraw(all_customers, config); break;
                        case 4: Admin_user.deposit(all_customers); break;
                        case 5: Admin_user.transfer(all_customers, config); break;
                        case 6: Admin_user.give_interest(all_customers, config.interest_rate); break;
                        case 7: Admin_user.loan_interest(all_customers, config.loan_charge, config.maintenance_charge); break;
                        case 8: Admin_user.view_customer_info(all_customers); break;
                        case 9: Admin_user.give_loan(all_customers); break;
                        case 10: Admin_user.unlock_account(all_customers); break;
                        case 11: std::cout << "Admin logging out...\n"; break;
                        default: std::cout<<"Wrong Option Selected\n"; break;
                    }
                    if (user_choice_admin != 11) {
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(1000, '\n');
                        std::cin.get();
                    }
                }
            }
        }else if(user_choice_main == 2){

            customer_login(all_customers, config);

        }else if(user_choice_main == 3){

            save_all_customers(all_customers, FILENAME);
            std::cout<< "Data Saved";
            return 0;

        }else if(user_choice_main == 4){

            about_menu(config);

        }
        else std::cout<<"Wrong Option Selected\n";
    }
    return 0;
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
        long acc_no;
        std::string name, passwd;
        double bal, loan_bal;
        int attempts, status;

        // Parse the CSV line
        getline(ss, token, ','); acc_no = std::stol(token);
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
            << cust.get_password_attempts_remaining() << ","
            << cust.get_account_status() << std::endl; // endl creates a new line
    }

    outFile.close();
    std::cout << "Data successfully saved." << std::endl;
}

//The Home Screen CLI
int main_menu(){
    system("cls");
    std::cout<<"*******************************************************\n";
    std::cout<<"\t\t CLI Banking App \n";
    std::cout<<"*******************************************************\n";
    std::cout<<"\t (1) Admin Login \n\t (2) Customer Login \n\t (3) Exit Application and Save Data \n\t (4) Important Information \n";
    std::cout<<"Please Choose Your Desired Operation: ";
    return option_input();
}

//The Admin Menu after successful login
int admin_menu(){
    system("cls");
    std::cout<<"*******************************************************\n";
    std::cout<<"\t\t CLI Banking App \n";
    std::cout<<"*******************************************************\n";
    std::cout<<"Welcome Back! Mr. Abhinav Prakash. \n";
    std::cout<<"*******************************************************\n";
    std::cout<<"\t (1) Create New Bank Account \n";
    std::cout<<"\t (2) Delete an Existing Bank Account \n";
    std::cout<<"\t (3) Withdraw From a Bank Account \n";
    std::cout<<"\t (4) Deposit to a Account \n";
    std::cout<<"\t (5) Transfer Funds From one Account to Another \n";
    std::cout<<"\t (6) Give Interest to all Bank Accounts \n";
    std::cout<<"\t (7) Add Bills to all Bank Accounts \n";
    std::cout<<"\t (8) View Bank Account Details \n";
    std::cout<<"\t (9) Add Loan to a Bank Account \n";
    std::cout<<"\t (10) Unlock a Bank Account \n";
    std::cout<<"\t (11) Logout \n";
    std::cout<<"Please Choose Your Desired Operation: ";
    return option_input();
}

//Customer Menu after successfull Login done by customer
void customer_menu(customer& logged_in_customer, std::vector<customer>& all_customers, const AppConfig& config) {
    int user_choice = 0;
    while(user_choice!=7){
        system("cls");
        std::cout<<"*******************************************************\n";
        std::cout<<"\t\t CLI Banking App \n";
        std::cout<<"*******************************************************\n";
        std::cout << "\t\t Welcome, " << logged_in_customer.get_customer_name() << "!\n";
        std::cout << "*******************************************************\n";
        std::cout << "\t (1) Withdraw Funds \n";
        std::cout << "\t (2) Deposit Funds \n";
        std::cout << "\t (3) Transfer Funds \n";
        std::cout << "\t (4) View Balance \n";
        std::cout << "\t (5) Change Password \n";
        std::cout << "\t (6) Pay Loan Dues \n";
        std::cout << "\t (7) Logout \n";
        std::cout<<"Please Choose Your Desired Operation: ";
        user_choice = option_input();

        switch (user_choice) {
            case 1: logged_in_customer.withdraw(config); break;
            case 2: logged_in_customer.deposit(); break;
            case 3: logged_in_customer.transfer(all_customers, config); break;
            case 4: logged_in_customer.view_balance(); break;
            case 5: logged_in_customer.change_password(); break;
            case 6: logged_in_customer.pay_loan(config); break;
            case 7: std::cout << "Logging out...\n"; break;
            default: std::cout<< "Wrong Option Selected.\n"; break;
        }
        if(user_choice!=7){
            std::cout << "\nPress Enter to continue...";
            std::cin.get();
        }
    }
}

// Note: We pass the vector by reference (&) so we can modify the actual customer objects
void customer_login(std::vector<customer>& all_customers, const AppConfig& config) {
    long acc_no;

    std::string passwd;
    std::cout << "Enter Account Number: ";
    std::cin >> acc_no;
     if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return;
    }
    std::cout << "Enter Password: ";
    std::cin >> passwd;

    bool found_customer = false;
    // Loop through the vector to find the matching customer
    for (customer& user : all_customers) {

        if (user.get_account_number() == acc_no) {
            found_customer = true; // Found the account

            if (user.get_account_status() == 0) { // 0 is LOCKED
                std::cout << "Your Account has been Locked. Please contact an Admin to unlock it.\n";
            } else if (user.get_password() == passwd) { // Account is Active, check password
                std::cout << "Login Successful!" << std::endl;
                user.edit_password_attempts_remaining(4); // Reset attempts on successful login
                customer_menu(user, all_customers, config);
            } else { // Wrong password
                user.edit_password_attempts_remaining(user.get_password_attempts_remaining() - 1);
                std::cout<< "Invalid Password. You have "<< user.get_password_attempts_remaining()<< " attempts remaining.\n";
                if(user.get_password_attempts_remaining() <= 0) {
                    user.edit_account_status(0); // Lock account
                    std::cout << "You have run out of attempts. Your account is now locked.\n";
                }
                std::cout << "Press Enter to continue...";
                std::cin.ignore(1000, '\n');
                std::cin.get();
                return;
            }
        }
        if (!found_customer) {
            std::cout << "Account not found." << std::endl;
            std::cout << "Press Any Key to continue...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
        }
    }
}

void about_menu(const AppConfig& config){

    system("cls");
    std::cout<<"Minimum Balance: "<< config.minimum_balance<< std::endl;
    std::cout<<"Minimum Balance Penalty: "<< config.minimum_balance_charge<< std::endl;
    std::cout<<"Interest Rate S/B Accounts: "<< config.interest_rate * 100<< "%\n";
    std::cout<<"Loan Charges: "<< config.loan_charge * 100 <<"%\n";
    std::cout<<"Maintenance Charges: "<< config.maintenance_charge<< std::endl;

    std::cout<<"------------------------------------------------------------\n";
    std::cout<<"Application Name: CLI Banking App\n";
    std::cout<<"Version: 1.1\n";
    std::cout<<"Developed By: Abhinav Prakash\n";
    std::cout<<"To Clone This Project: github.com/abhinavprakash-x/link \n";
    std::cin.ignore(1000,'\n');
    std::cin.get();
}

int option_input(){
    int user_choice;
    std::cin >> user_choice;

    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(1000, '\n'); // Discard bad input
        std::cin >> user_choice;
    }
    std::cin.ignore(1000, '\n');
    return user_choice;
}

AppConfig load_config(const std::string& filename){
    AppConfig config;
    std::ifstream configFile(filename);
    if(!configFile.is_open()){
        std::cerr<<"Error: Could not open config file: "<< filename<< std::endl;
        std::cout<<"Creating a New Config File\n";

        std::cout << "Enter a new admin password: ";
        std::cin >> config.admin_password;
        std::cout << "Enter interest rate (e.g., 0.055 for 5.5%): ";
        std::cin >> config.interest_rate;
        std::cout << "Enter loan charge rate (e.g., 0.095 for 9.5%): ";
        std::cin >> config.loan_charge;
        std::cout << "Enter maintenance charge (e.g., 100): ";
        std::cin >> config.maintenance_charge;
        std::cout << "Enter minimum balance requirement (e.g., 500): ";
        std::cin >> config.minimum_balance;
        std::cout << "Enter minimum balance charge/penalty (e.g., 100): ";
        std::cin >> config.minimum_balance_charge;
        std::cin.ignore(1000, '\n');

        std::ofstream newConfigFile(filename);
        if(newConfigFile.is_open()){
            newConfigFile << "admin_password = " << config.admin_password << "\n";
            newConfigFile << "interest_rate = " << config.interest_rate << "\n";
            newConfigFile << "loan_charge = " << config.loan_charge << "\n";
            newConfigFile << "maintenance_charge = " << config.maintenance_charge << "\n";
            newConfigFile << "minimum_balance = " << config.minimum_balance << "\n";
            newConfigFile << "minimum_balance_charge = " << config.minimum_balance_charge << "\n";
            newConfigFile.close();
            std::cout << "Configuration saved to config.txt successfully." << std::endl;
        } else {
            std::cerr << "Error: Could not create config file!" << std::endl;
            exit(1);
        }
    }else{

        std::string line;
        while(std::getline(configFile, line)){
            std::stringstream ss(line);
            std::string key, value;
            if (std::getline(ss, key, '=') && std::getline(ss, value)) {
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                if (key == "admin_password") config.admin_password = value;
                else if (key == "interest_rate") config.interest_rate = std::stod(value);
                else if (key == "loan_charge") config.loan_charge = std::stod(value);
                else if (key == "maintenance_charge") config.maintenance_charge = std::stod(value);
                else if (key == "minimum_balance") config.minimum_balance = std::stod(value);
                else if (key == "minimum_balance_charge") config.minimum_balance_charge = std::stod(value);
            }
        }
        configFile.close();
        std::cout << "Configuration loaded successfully." << std::endl;
    }

    return config;
}