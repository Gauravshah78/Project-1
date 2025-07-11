#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//----- Welcome to ABC Bank -----
// 1. Create Account
// 2. Deposit Money
// 3. Withdraw Money
// 4. Check Balance
// 5. Display Account Details
// 6. Exit
// Enter your choice:

class Bank_acc
{
private:
    int pin;
    string name, f_name, l_name, father, phone_str;
    int acc_num, age, withdraw, deposit, credit, balance = 0;

public:
    void create_acc(void);     // hogya
    void deposit_money(void);  // hogya
    void credit_money(void);   // hogya
    void check_balance(void);  // hogya
    void withdraw_money(void); // hogya
    void display_acc(void);    // hogya
    int getAccNum();
    bool verify(int entered_acc, int entered_pin);
};

int Bank_acc::getAccNum()
{
    return acc_num;
}

bool Bank_acc::verify(int entered_acc, int entered_pin)
{
    return (entered_acc == acc_num && entered_pin == pin);
}

// Create account function
void Bank_acc::create_acc(void)
{

    cin.ignore(); // clear buffer before any getline()

    cout << "Enter Account Holder Name: ";
    getline(cin, name); // full name including spaces

    cout << "Enter First name: ";
    getline(cin, f_name);

    cout << "Enter Last name: ";
    getline(cin, l_name);

    cout << "Enter your Father's Name: ";
    getline(cin, father);

    // Phone number validation
    bool valid = false;
    do
    {
        cout << "Enter your Phone number (10 digits): ";
        getline(cin, phone_str);

        if (phone_str.length() == 10 && all_of(phone_str.begin(), phone_str.end(), ::isdigit))
        {
            valid = true;
        }
        else
        {
            cout << "Invalid phone number. Please enter exactly 10 digits.\n";
        }
    } while (!valid);

    cout << "Enter your Age: ";
    cin >> age;

    cout << "Enter Initial Deposit: ";
    cin >> balance;

    cout << "Set your Account Number: ";
    cin >> acc_num;

    cout << "Set 4-digit PIN: ";
    cin >> pin;

    cout << "\nCongratulations! Your account is created on SBI Bank of India.\n\n";
}

// Deposit
void Bank_acc::deposit_money(void)
{
    int entered_acc, entered_pin, amount;
    cout << "Enter deposit amount: " << endl;
    cin >> deposit;
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (verify(entered_acc, entered_pin))
    {
        cout << "Enter Amount to Deposit: ";
        cin >> amount;
        balance += amount;
        cout << "₹" << amount << " deposited successfully.\n";
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }
}

// Credit
void Bank_acc::credit_money(void)
{
    int entered_acc, entered_pin, amount;
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (verify(entered_acc, entered_pin))
    {
        cout << "Enter Amount to Credit: ";
        cin >> amount;
        if (amount <= balance)
        {
            balance -= amount;
            cout << "₹" << amount << " credited successfully.\n";
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }
}
// Check balance
void Bank_acc::check_balance(void)
{
    int entered_acc, entered_pin;
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (verify(entered_acc, entered_pin))
    {
        cout << "Current Balance: ₹" << balance << endl;
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }
}

// withdraw
void Bank_acc::withdraw_money(void)
{
    int entered_acc, entered_pin, amount;
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (verify(entered_acc, entered_pin))
    {
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;
        if (amount <= balance)
        {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }
}

// Display details
void Bank_acc::display_acc(void)
{
    int entered_acc, entered_pin;
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (verify(entered_acc, entered_pin))
    {
        cout << "\n👤 Account Details:\n";
        cout << "Full Name: " << name << endl;
        cout << "Father's Name: " << father << endl;
        cout << "Phone Number: " << phone_str << endl;
        cout << "Age: " << age << endl;
        cout << "Account Number: " << acc_num << endl;
        cout << "Balance: ₹" << balance << endl;
    }
    else
    {
        cout << "Invalid account number or PIN.\n";
    }
}

int main()
{
    vector<Bank_acc> users;
    int n;
    int choice;

    do
    {
        cout << "----Welcome to SBI BANK OF INIDA----" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Credit Money" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Display Account Details" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            Bank_acc newUser;
            newUser.create_acc();
            users.push_back(newUser);
        }
        else if (choice >= 2 && choice <= 6)
        {
            int acc_num;
            cout << "Enter your Account Number: ";
            cin >> acc_num;
            bool found = false;
            for (Bank_acc &user : users)
            {
                if (user.getAccNum() == acc_num)
                {
                    found = true;
                    switch (choice)
                    {

                    case 2:
                        user.deposit_money();
                        break;
                    case 3:
                        user.withdraw_money();
                        break;
                    case 4:
                        user.credit_money();
                        break;
                    case 5:
                        user.check_balance();
                        break;
                    case 6:
                        user.display_acc();
                        break;
                    }
                    break;
                }
            }
            if (!found)
            {
                cout << "Account not found.\n";
            }
        }
        else if (choice == 0)
        {
            cout << "Thank you for using SBI Bank. Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}