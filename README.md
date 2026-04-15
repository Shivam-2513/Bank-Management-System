# 🏦 Bank Management System (C++)

## 📌 Overview

This project is a **Bank Management System implemented in C++** using file handling.
It simulates basic banking operations such as account creation, deposits, withdrawals, transfers, and transaction history tracking.

The system stores data in **CSV files**, making it simple, lightweight, and easy to inspect.

---

## 🚀 Features

### 👤 Account Management

* Create new account
* Delete existing account
* View account details
* Login using account number and password

### 💰 Transactions

* Deposit money
* Withdraw money
* Transfer money between accounts

### 📜 Transaction History

* Stores transaction history per account
* Each account has its own file:

  ```
  transactions_<account_number>.csv
  ```

### 🗂 Data Storage

* `account_details.csv` → stores all accounts
* `transactions_<acc_no>.csv` → stores transaction history per user

---

## 🧠 Concepts Used

* Object-oriented thinking (modular functions)
* File handling (`ifstream`, `ofstream`)
* String parsing (`stringstream`)
* Data persistence
* Basic system design
* Use of temporary files for safe updates

---

## ⚙️ How It Works

### 🔹 Account Creation

* Automatically generates a new account number
* Stores:

  ```
  acc_no, name, password, balance
  ```

### 🔹 Transactions

* Updates balance using a **temp file approach**
* Ensures safe modification of records

### 🔹 Transaction Logging

* Every transaction is stored with timestamp
* Format:

  ```
  time, old_balance, new_balance
  ```

---

## 🖥️ How to Run

### 1. Compile

```bash
g++ main.cpp -o bank
```

### 2. Run

```bash
./bank
```

---

## 📁 File Structure

```
Bank-Management-System/
│
├── main.cpp
├── account_details.csv
├── transactions_<acc_no>.csv
└── README.md
```

---

## ⚠️ Important Notes

* CSV files are created automatically if not present
* Data is persistent across runs
* Do NOT manually edit files while program is running
* Password is stored in plain text (for simplicity)

---

## 🔧 Limitations

* No encryption for passwords
* No concurrency handling
* Linear search used (can be optimized)
* No GUI (CLI-based system)

---

## 🚀 Future Improvements

* Add password encryption
* Use database (SQLite/MySQL)
* Implement binary search or indexing
* Add admin panel
* Improve UI (GUI or web interface)
* Add input validation and error handling

---

## 💡 Key Learning Outcomes

* Handling real-world data using files
* Designing modular systems
* Understanding trade-offs (time vs space)
* Implementing CRUD operations

---

## 👨‍💻 Author

**Shivam Jha**

---

## 📌 One-Line Summary

A simple yet powerful **file-based banking system in C++** demonstrating core programming and system design concepts.
