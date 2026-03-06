#include <iostream>
#include <fstream>
using namespace std;
typedef long long int ll;
#define loop(i, start, end) for(long long int i = start; i <= end; ++i)

int main(){
    cout << "Welcome to Shivam Bank\n" << "1. Login (press 1)\n" << "2. Create Account (press 2)\n";
    ll t; cin >> t;

    if (t == 1){
        cout << "Enter Account Number:\n";

        //use binary search on account_details.txt (sorted by account number) check if user exists
        
        //if not, give error message and re-ask account number till yes

        //if yes, proceed with the process using while (true)
    }

    else if (t == 2){
        cout << "Your Account Number will be: "; //generate the account number here
        
        cout << "Enter Your Integer Password: (Password must be atleast 4 digits)";
        cout << "Enter Password Again: ";

        //if the 2 don't match or password is < 4 digits or password has non integral char, cout << Fail, end program

        //if not, then add this to account_details.txt and end the program
    }
}