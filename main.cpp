#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long int ll;
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)

void create_account(ll password){
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

    ofstream acc_details("account_details.csv");
    string name; ll password; double balance;
    cout << "Enter your name: "; cin >> name; cout << '\n';
    cout << "Enter your initial balance: "; cin >> balance; cout << '\n';

    acc_details << acc_no << ","
                << name << ","
                << password << ","
                << balance << '\n';
    acc_details.close();
    return;
}
void perform_task(string this_account, ll command){
    cout << "Enter your password: \n";
    ll entered_password; cin >> entered_password;
    stringstream ss(this_account);
    string acc_no;
    getline(ss, acc_no, ',');
    string name;
    getline(ss, name, ',');
    string password;
    getline(ss, password, ',');
    string balance;
    getline(ss, balance, ',');
    if (entered_password != stoi(password)) return;



}
string find_account(ll acc_no){
    //use binary search on account_details.txt (sorted by account number) check if user exists
    //currently, using linear search
    ifstream acc("account_details.csv");
    ll curr_acc_no = 0;
    string line;
    while (curr_acc_no != acc_no){
        bool pass = (bool)getline(acc, line);
        if (!pass) break;
        if (line.empty()) continue;

        stringstream ss(line);
        string x;
        getline(ss, x, ',');
        curr_acc_no = stoi(x);
        }
    
    if (curr_acc_no = acc_no){
        return line;
    }else{
        return "";
    }
}
void view_transactions(string this_account){
    
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
        ll acc_no = -1; cin >> acc_no;
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
                 << "6. display all accounts (admin only feature)\n"
                 << "7. exit\n";
            ll command; cin >> command;
            perform_task(this_account, command);
        }
        
        }

        
        //if not, give error message and re-ask account number till yes

        //if yes, proceed with the process using while (true)
    

    else if (t == 2){
        ll pass1 = 0, pass2 = 0;
        cout << "Enter Your Integer Password: (Password must be atleast 4 digits)"; cin >> pass1;
        cout << "Enter Password Again: "; cin >> pass2;
        ll digits = (ll)log10(pass1) + 1;

        if (pass1 != pass2 || digits < 4){
            cout << "fail\n";
        }else create_account(pass1);

        //if not, then add this to account_details.txt and end the program
    }
}