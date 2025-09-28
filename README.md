🏦 CLI Banking Application
A comprehensive, command-line based banking application written in C++. This project simulates basic banking operations for both administrators and customers, featuring data persistence through CSV files and external configuration. It's a learning project designed to demonstrate core C++ and Object-Oriented Programming (OOP) principles.

✨ Key Features
🤵 Admin Functionalities
Account Management: Create new customer accounts and delete existing ones.

Transactions: Perform withdrawals, deposits, and fund transfers on behalf of any customer.

Financial Oversight: Apply interest, manage loan charges, and approve loans.

Account Utilities: View detailed customer information and unlock locked accounts.

👤 Customer Functionalities
Secure Login: Access accounts with a password. Accounts are locked after multiple failed attempts.

Core Banking: Withdraw, deposit, and transfer funds.

Account Information: View current balance, outstanding loan amounts, and pay loan dues.

Security: Change their account password.

🔧 General Features
Data Persistence: All customer data is saved to customers.csv and loaded at startup.

External Configuration: Key parameters (interest rates, charges) are managed in config.txt without needing to recompile.

Password Hashing: Passwords are not stored in plain text for security.

Password Change Utility: A separate executable to securely change the admin password.

🏛️ Project Architecture & Strengths
This project is built on a solid foundation of software design principles.

Excellent Code Organization: The code is logically separated into different files (admin.h, admin.cpp, customer.h, customer.cpp, main.cpp). This modular design makes the project easy to read, manage, and expand.

Clear Class Design: The admin and customer classes have well-defined responsibilities and methods, demonstrating a strong grasp of OOP.

Robust Security Features: Implements a password system, password hashing, and an account lockout mechanism to protect user accounts.

User-Friendly Interface: The command-line menus are clear, and the application flow is intuitive for both admin and customer users.

A Note on Security & Hashing
The current implementation uses std::hash for password hashing. While this is a great first step for a learning project, it is not cryptographically secure. For real-world applications, a dedicated password-hashing library like BCrypt, Argon2, or SHA256 should be used to provide much stronger security.

🚀 Getting Started
You will need a C++ compiler like g++ to run this project.

Main Banking Application
Navigate to the project directory.

Compile the source files:

g++ main.cpp admin.cpp customer.cpp -o bank_app.exe

Run the application:

.\bank_app.exe

Admin Password Change Utility
Navigate to the project directory.

Compile the utility:

g++ change_admin_password.cpp -o change_admin_password.exe

Run the utility:

.\change_admin_password.exe

⚙️ Configuration
The config.txt file controls the application's global parameters. Default values are listed below but can be easily adjusted in the file.

admin_password: The hashed password for the admin login.

interest_rate: The interest rate for savings accounts (e.g., 0.055 for 5.5%).

loan_charge: The interest rate applied to outstanding loans (Default: 5%).

maintenance_charge: A flat maintenance fee (Default: 50).

minimum_balance: The minimum balance required to avoid a penalty (Default: 500).

minimum_balance_charge: The penalty fee if the balance falls below the minimum (Default: 100).

📚 Learning Outcomes
While building this project, I gained practical experience in:

Object-Oriented Programming (OOP) in C++

Modular project structure (headers & implementation files)

User input and error handling

Using std::vector for dynamic data storage

File I/O with .csv and configuration files

Designing an extensible CLI-based system

📜 Project History (Changelog)
v1.3 (28-09-2025): Added password hashing and the ability to change the admin password.

v1.2 (27-09-2025): Added support for config.txt for global parameters.

v1.1 (27-09-2025): General fixes and polishing based on initial testing.

v1.0 (27-09-2025): Full basic implementation of the entire application.

v0.1 (22-09-2025): Basic Skeleton

🎯 Future Work (TODO)
Add Passbook: Create a transaction history/passbook functionality for customers.

UI Improvements: Enhance the command-line interface for a more user-friendly experience.
