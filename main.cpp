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
void customer_login(std::vector <customer> &all_customers);
void customer_menu(customer &logged_in_customer);
void save_all_customers(const std::vector<customer>& customers, const std::string& filename);
std::vector<customer> load_all_customers(const std::string& filename);



int main(){

    //load data from csv file
    const std::string FILENAME = "customers.csv";
    std::vector <customer> all_customers = load_all_customers(FILENAME);

    
    //CLI
    int repeat = 1, user_choice_main, user_choice_admin;
    do{
        start:
        user_choice_main = main_menu();

        if(user_choice_main == 1){

            user_choice_main = 0;
            admin Admin_user;
            bool login = Admin_user.login();
            admin_start:
            user_choice_admin = admin_menu(login);

            switch(user_choice_admin){
                case -1: goto start;
                case 1: Admin_user.create_account(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 2: Admin_user.delete_account(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 3: Admin_user.withdraw(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 4: Admin_user.deposit(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 5: Admin_user.transfer(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 6: Admin_user.give_interest(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 7: Admin_user.deduct_bills(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 8: Admin_user.view_customer_info(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 9: Admin_user.give_loan(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 10: Admin_user.unlock_account(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
                case 11: goto start;
                default: std::cout<<"Wrong Option Selected\n";
                         std::cout << "Press Any Key to continue...";
                         std::cin.ignore(1000, '\n');
                         std::cin.get();
            }
            goto admin_start;

        }else if(user_choice_main == 2){

            user_choice_main = 0;
            customer_login(all_customers);

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

//The Home Screen CLI
int main_menu(){
    system("cls");
    int user_choice;
    std::cout<<"*******************************************************\n";
    std::cout<<"\t\t CLI Banking App \n";
    std::cout<<"*******************************************************\n";
    std::cout<<"\t (1) Admin Login \n\t (2) Customer Login \n\t (3) Exit Application\n";
    std::cout<<"Please Choose Your Desired Operation: ";
    std::cin>> user_choice;
    return user_choice;
}

//The Admin Menu after successful login
int admin_menu(bool login){
    if(login){
        int user_choice;
        system("cls");
        std::cout<<"*******************************************************\n";
        std::cout<<"\t\t CLI Banking App \n";
        std::cout<<"*******************************************************\n";
        std::cout<<"Welcome Back! Admin User. \n";
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
        std::cout<<"\t (11) Logout \n";
        std::cout<<"Please Choose Your Desired Operation: ";
        std::cin>> user_choice;
        return user_choice;
    }else{
        std::cout<<"Invalid Credentials \n";
        std::cout << "Press Any Key to continue...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
        return -1;
    }
}

//Customer Menu after successfull Login done by customer
void customer_menu(customer& logged_in_customer, std::vector<customer>& all_customers) {
    int user_choice;
    customer_start:
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
    std::cin>> user_choice;

    // Now you can call methods on the specific logged_in_customer object
    switch (user_choice) {
        case 1: logged_in_customer.withdraw(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
        case 2: logged_in_customer.deposit(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
        case 3: logged_in_customer.transfer(all_customers); std::cin.ignore(1000, '\n'); std::cin.get(); break;
        case 4: logged_in_customer.view_balance(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
        case 5: logged_in_customer.change_password(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
        case 6: logged_in_customer.pay_loan(); std::cin.ignore(1000, '\n'); std::cin.get(); break;
        case 7: return;
        default: std::cout<< "Wrong Option Selected.\n";
                 std::cout << "Press Any Key to continue...";
                 std::cin.ignore(1000, '\n');
                 std::cin.get();
    }
    goto customer_start;
}

// Note: We pass the vector by reference (&) so we can modify the actual customer objects
void customer_login(std::vector<customer>& all_customers) {

    std::string acc_no, passwd;
    std::cout << "Enter Account Number: ";
    std::cin >> acc_no;
    std::cout << "Enter Password: ";
    std::cin >> passwd;

    bool found_customer = false;
    // Loop through the vector to find the matching customer
    for (customer& user : all_customers) {

        if (user.get_account_number() == acc_no) {
            found_customer = true; // Found the account

            //check if account is locked TODO
            if (user.get_password() == passwd && user.account_status == 0) {
                std::cout << "Login Successful!" << std::endl;
                user.wrong_password_attempts = 0;
                // Now that we've found the correct user, show them their menu
                customer_menu(user, all_customers);
            } else {
                std::cout<< "Invalid Password or Account Locked.\n";
                user.wrong_password_attempts++;
                if(user.wrong_password_attempts >= 3) user.account_status = 1;
                std::cout << "Press Any Key to continue...";
                std::cin.ignore(1000, '\n');
                std::cin.get();
            }
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