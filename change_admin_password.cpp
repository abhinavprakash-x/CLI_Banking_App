#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>

struct AppConfig {
    std::string admin_password;
    double interest_rate;
    double loan_charge;
    double maintenance_charge;
    double minimum_balance;
    double minimum_balance_charge;
};

std::string hash_password(const std::string& password) {
    return std::to_string(std::hash<std::string>{}(password));
}

AppConfig load_config(const std::string& filename) {
    AppConfig config;
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        std::cerr << "Error: config.txt not found. Please run the main banking app first to create it." << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(configFile, line)) {
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
    return config;
}

void save_config(const AppConfig& config, const std::string& filename) {
    std::ofstream configFile(filename);
    if (!configFile.is_open()) {
        std::cerr << "Error: Could not open config file for writing!" << std::endl;
        return;
    }
    configFile << "admin_password = " << config.admin_password << "\n";
    configFile << "interest_rate = " << config.interest_rate << "\n";
    configFile << "loan_charge = " << config.loan_charge << "\n";
    configFile << "maintenance_charge = " << config.maintenance_charge << "\n";
    configFile << "minimum_balance = " << config.minimum_balance << "\n";
    configFile << "minimum_balance_charge = " << config.minimum_balance_charge << "\n";
    configFile.close();
}

int main() {
    const std::string CONFIG_FILE = "config.txt";
    AppConfig config = load_config(CONFIG_FILE);

    std::cout << "--- Admin Password Change Utility ---" << std::endl;

    // 1. Verify current password
    std::string current_pass_input;
    std::cout << "Enter your CURRENT admin password: ";
    std::cin >> current_pass_input;

    if (hash_password(current_pass_input) != config.admin_password) {
        std::cerr << "Error: Incorrect password." << std::endl;
        return 1; // Exit with an error code
    }

    // 2. Get and confirm new password
    std::string new_pass;
    std::string confirm_pass;
    std::cout << "Enter your NEW password: ";
    std::cin >> new_pass;
    std::cout << "Confirm your NEW password: ";
    std::cin >> confirm_pass;

    if (new_pass != confirm_pass) {
        std::cerr << "Error: New passwords do not match. Password not changed." << std::endl;
        return 1;
    }

    // 3. Update config object and save to file
    config.admin_password = hash_password(new_pass);
    save_config(config, CONFIG_FILE);

    std::cout << "\nAdmin password has been changed successfully!" << std::endl;
    return 0; // Success
}