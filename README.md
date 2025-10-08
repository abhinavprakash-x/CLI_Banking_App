# 🏦 CLI Banking Application

![C++](https://img.shields.io/badge/Language-C++-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Last Update](https://img.shields.io/badge/Last%20Update-28--09--2025-orange)

A comprehensive, command-line based banking application written in C++. Simulates banking operations for both administrators and customers, featuring CSV-based data persistence and external configuration. Great for learning **OOP** and **C++ fundamentals**.


## ✨ Key Features

### 🤵 Admin Functionalities
- **Account Management:** Create/delete customer accounts.  
- **Transactions:** Withdraw, deposit, or transfer funds for any customer.  
- **Financial Oversight:** Apply interest, manage loan charges, approve loans.  
- **Account Utilities:** View detailed customer info, unlock accounts.
- **Admin Password in `config.txt` is Admin@123.**

### 👤 Customer Functionalities
- **Secure Login:** Accounts lock after multiple failed attempts.  
- **Core Banking:** Withdraw, deposit, transfer funds.  
- **Account Information:** View balance, loans, and pay dues.  
- **Security:** Change account password.  

### 🔧 General Features
- **Data Persistence:** All data saved to `customers.csv`.  
- **External Configuration:** Global parameters via `config.txt`.  
- **Password Hashing:** Secure storage of passwords.  
- **Admin Password Utility:** Separate executable for changing admin password.  

---

## 🏛️ Project Architecture & Strengths
- Modular design: `admin.h`, `admin.cpp`, `customer.h`, `customer.cpp`, `main.cpp`.  
- Clear **class responsibilities** demonstrating OOP principles.  
- Password system and account lockout ensure security.  
- User-friendly command-line menus with intuitive flow.  

---

## ⚠️ Note on Security & Hashing
Currently uses `std::hash`. Suitable for learning, **not cryptographically secure**.  
For real-world applications, use **BCrypt, Argon2, or SHA256**.

---

## 🚀 Getting Started

### Main Banking Application
1. Navigate to project directory.  
2. Compile:

```
g++ main.cpp admin.cpp customer.cpp -o bank_app.exe
```

3. Run:

```
.\bank_app.exe
```

**OR:
```
make
```

### Admin Password Change Utility
1. Navigate to project directory.  
2. Compile:

```
g++ change_admin_password.cpp -o change_admin_password.exe
```

3. Run:

```
.\change_admin_password.exe
```

---

## ⚙️ Configuration

`config.txt` controls global parameters:

```text
admin_password: <hashed password> (Admin@123)
interest_rate: 0.055
loan_charge: 0.05
maintenance_charge: 50
minimum_balance: 500
minimum_balance_charge: 100
```

Adjust without recompiling.

---

## 📚 Learning Outcomes
- Object-Oriented Programming (OOP) in C++  
- Modular project structure (headers & implementation files)  
- User input and error handling  
- `std::vector` for dynamic storage  
- File I/O with `.csv` and config files  
- Extensible CLI system design  

---

## 📜 Project History (Changelog)
- **v1.3 (28-09-2025):** Password hashing & admin password change utility.  
- **v1.2 (27-09-2025):** `config.txt` support for global parameters.  
- **v1.1 (27-09-2025):** General fixes & polishing.  
- **v1.0 (27-09-2025):** Full basic implementation.  
- **v0.1 (22-09-2025):** Basic skeleton.

---

## 🎯 Future Work (TODO)
- **Add Passbook:** Transaction history functionality.  
- **UI Improvements:** More user-friendly CLI interface.
