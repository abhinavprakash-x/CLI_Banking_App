#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

#include"customer.h"
#include"admin.h"

using namespace std;

int main(){
    const string FILENAME = "customers.csv";
    vector <customer> all_customers = load_all_customers(FILENAME);
    //load data from csv file

    

    //CLI Based Login System
    int repeat = 1, user_choice;
    do{
        cout<<"CLI Based Banking Application\n";
        cout<<"------------------------------\n";
        cout<<"Main Menu \n";
        cout<<"1. Login as Administrator \n";
        cout<<"2. Login as Customer \n";
        cout<<"3. Exit System \n";
        cout<<"Choose Your Preferred Option: ";
        cin>>user_choice;
        if(user_choice == 1) cout<<"Admin"; //call admin menu
        else if(user_choice == 2) cout<<"Customer"; //call customer menu
        else if(user_choice == 3) return 0; //exit program NB: save data before exit
        else cout<<"Wrong Option Selected";
    } while(repeat == 1);



    //save the file
}









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

std::vector<customer> load_all_customers(const std::string& filename) {
    std::vector<customer> customers;
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "No existing data file found. Starting fresh." << std::endl;
        return customers;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string token;

        // Variables to hold the parsed data
        std::string acc_no, name, passwd;
        double bal, loan_bal;
        int attempts, status;

        // Parse the CSV line
        std::getline(ss, token, ','); acc_no = token;
        std::getline(ss, token, ','); name = token;
        std::getline(ss, token, ','); passwd = token;
        std::getline(ss, token, ','); bal = std::stod(token); // stod = string to double
        std::getline(ss, token, ','); loan_bal = std::stod(token);
        std::getline(ss, token, ','); attempts = std::stoi(token); // stoi = string to integer
        std::getline(ss, token, ','); status = std::stoi(token);

        // Create a customer object and add it to the vector
        customers.emplace_back(acc_no, name, passwd, bal, loan_bal, attempts, status);
    }

    inFile.close();
    std::cout << "Customer data loaded successfully." << std::endl;
    return customers;
}