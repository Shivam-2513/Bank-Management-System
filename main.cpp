#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;
typedef long long int ll;
string curr_time() {
    auto now = chrono::system_clock::now();
    time_t current_time = chrono::system_clock::to_time_t(now);

    string time = ctime(&current_time);

    if (!time.empty() && time.back() == '\n') {
        time.pop_back();
    }

    return time;
}
void clear_account_details_csv() {
    ofstream file("account_details.csv", ios::trunc);
    file.close();
}
void create_account(string password){
    ifstream acc("account_details.csv");
    string line, lastLine;
    lastLine = "Null";

    while (getline(acc, line)) {
        if (!line.empty())   // skip empty lines
            lastLine = line;
    }
    acc.close();

    ll acc_no = -1;
    if (lastLine == "Null"){
        acc_no = 900000;
    }else{
        stringstream ss(lastLine);
        string acc_no_str;
        getline(ss, acc_no_str, ',');
        acc_no = stoi(acc_no_str) + 1;
    }

    ofstream acc_details("account_details.csv", ios::app);
    string name; string balance;
    cout << "Enter your name: "; cin >> name; cout << '\n';
    cout << "Enter your initial balance: "; cin >> balance; cout << '\n';

    acc_details << acc_no << ","
                << name << ","
                << password << ","
                << balance << '\n';
    acc_details.close();
    return;
}
void delete_account(string target_acc_no) {
    ifstream inFile("account_details.csv");
    ofstream outFile("temp.csv");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string acc_no;

        getline(ss, acc_no, ',');

        if (acc_no == target_acc_no) {
            found = true;
            continue; // skip → delete this account
        }

        outFile << line << "\n"; // copy rest
    }

    inFile.close();
    outFile.close();

    remove("account_details.csv");
    rename("temp.csv", "account_details.csv");

    if (found) {
        cout << "Account deleted successfully.\n";
    } else {
        cout << "Account not found.\n";
    }
}
string find_account(string acc_no){
    //use binary search on account_details.txt (sorted by account number) check if user exists
    //currently, using linear search
    ifstream acc("account_details.csv");
    string curr_acc_no;
    string line;
    while (curr_acc_no != acc_no){
        bool pass = (bool)getline(acc, line);
        if (!pass) break;
        if (line.empty()) continue;

        stringstream ss(line);
        string x;
        getline(ss, x, ',');
        curr_acc_no = x;
        }
    
    if (curr_acc_no == acc_no){
        return line;
    }else{
        return "";
    }
}
void update_balance(string user_acc_no, string old_balance, string change){
    ofstream out_file("temp.csv");
    ifstream in_file("account_details.csv");

    string curr_acc_no, name, password, balance;
    string line;
    while(getline(in_file, line)){
    
        stringstream ss(line);
        
        getline(ss, curr_acc_no, ',');
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, balance, ',');

        if (user_acc_no == curr_acc_no){
            out_file << curr_acc_no << ',' << name << ',' << password << ',' << stoi(balance) + stoi(change) << '\n';
        }
        else{
            out_file << curr_acc_no << ',' << name << ',' << password << ',' << balance << '\n';
        }
    }

    in_file.close();
    out_file.close();

    remove("account_details.csv");
    rename("temp.csv", "account_details.csv");

    //update transaction history
    ofstream tr("transactions_" + user_acc_no + ".csv", ios::app);
    
    tr << curr_time() << "," << balance << "," << stoi(balance) + stoi(change) << '\n';

    return;
}
void view_transactions(string acc_no){
    //transactions_[acc_no].csv {without []}
    cout << "Transaction history for account no.: " << acc_no << '\n';
    ifstream tr("transactions_" + acc_no + ".csv");
    string line;
    while(getline(tr, line)){
        cout << line << '\n';
    }
    cout << "Operation Completed\n";
    tr.close();
}
void perform_task(string this_account, ll command){
    cout << "Enter your password: \n";
    ll entered_password; cin >> entered_password;

    string acc_no, name, password, balance;
    
    stringstream ss(this_account);
    
    getline(ss, acc_no, ',');
    getline(ss, name, ',');
    getline(ss, password, ',');
    getline(ss, balance, ',');
    
    if (entered_password != stoi(password)){
        cout << "Wrong Password!\nPlease Try Again\n";
        return;
    }

// commands:
//     deposit
//     withdraw
//     transfer
//     view account details
//     delete account
//     view transaction history
//     display all accounts (admin only feature)
//     exit

    switch (command)
    {
    case 1: {
        cout << "Enter amount: \n";
        string amount; cin >> amount;
        update_balance(acc_no, balance, amount);
        break;
    }
    case 2: {
        cout << "Enter amount: \n";
        string amount; cin >> amount;
        amount = "-" + amount;
        if (stoi(amount) > stoi(balance)) cout << "Insufficient balance\n";
        else{
            update_balance(acc_no, balance, amount);
        }
        break;
    }
    case 3: {
        cout << "Enter account number: \n";
        string dest_acc_no; cin >> dest_acc_no;
        string dest_acc;
        if ((dest_acc = find_account(dest_acc_no)) == "") cout << "Invalid account number\n";
        else{
            string dest_name, dest_password, dest_balance;
    
            stringstream ss(dest_acc);
            
            getline(ss, dest_acc_no, ',');
            getline(ss, dest_name, ',');
            getline(ss, dest_password, ',');
            getline(ss, dest_balance, ',');

            string amount;
            cout << "Enter Amount: \n";
            cin >> amount;

            if (stoi(amount) > stoi(balance)) cout << "Not enough balance\n";
            else{
                update_balance(acc_no, balance, "-" + amount);
                update_balance(dest_acc_no, dest_balance, amount);
                cout << "Successfully Transferred " << amount << "to " << dest_name << '\n'; 
            }
        } 
        break;
    }
    case 4: {
        cout << "Acc no.: " << acc_no << '\n';
        cout << "Name: " << name << '\n';
        cout << "Password: " << password << '\n';
        cout << "Balance: " << balance << '\n';
        break;
    }
    case 5: {
        cout << "Are you sure?:(Yes/No)\n";
        string response; cin >> response;
        transform(response.begin(), response.end(), response.begin(), ::tolower);
        if (response == "no") cout << "Account deletion cancelled\n";
        else{
            delete_account(acc_no);
            cout << "Account Successfully deleted!\n";
        }  
        break;  
    }
    case 6: {
        view_transactions(acc_no);
        break;
    }
    case 7: {
        break;
    }
    default:
        break;
    }

}



int main(){
    cout << "Welcome to Shivam Bank\n" << "1. Login (press 1)\n" << "2. Create Account (press 2)\n";
    ll t; cin >> t;

    if (t == 1){
        //ask account no.
        // find account no. 
        // ask for command 
        // perform that command 
        // break
        cout << "Enter Account Number:\n";
        string acc_no; cin >> acc_no;
        string this_account = find_account(acc_no);
        if (this_account.empty()){
            cout << "Account Not Found!'\n";
        }else{
            cout << "Select an option: \n"
                 << "1. deposit\n"
                 << "2. withdraw\n"
                 << "3. transfer\n"
                 << "4. view account details\n"
                 << "5. delete account\n"
                 << "6. view transactions\n"
                 << "7. display all accounts (admin only feature)\n"
                 << "8. exit\n";
            ll command; cin >> command;
            perform_task(this_account, command);
        }
        
        }

        
        //if not, give error message and re-ask account number till yes

        //if yes, proceed with the process using while (true)
    

    else if (t == 2){
        string pass1, pass2;
        cout << "Enter Your Integer Password: (Password must be atleast 4 digits)"; cin >> pass1;
        cout << "Enter Password Again: "; cin >> pass2;
        ll digits = (ll)log10(stoi(pass1)) + 1;

        if (pass1 != pass2 || digits < 4){
            cout << "fail\n";
        }else create_account(pass1);

        //if not, then add this to account_details.txt and end the program
    }
}