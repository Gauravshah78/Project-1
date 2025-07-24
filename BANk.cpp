#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Bank_acc
{
private:
    int entered_acc, entered_pin, pin;

public:
    string name, f_name, l_name, father, phone_str;
    int acc_num, age, withdraw, deposit, credit, balance;

    void create_acc(void);
    void deposit_money(void);
    void credit_money(void);
    void check_balance(void);
    void withdraw_money(void);
    void display_acc(void);
};

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
            cout << "❌ Invalid phone number. Please enter exactly 10 digits.\n";
        }
    } while (!valid);

    cout << "Enter your Age: ";
    cin >> age;

    cout << "Enter Initial Deposit: ";
    cin >> balance;

    cout << "Set your Account Number: ";
    cin >> acc_num;

    cout << "Set your PIN: ";
    cin >> pin;
    cout << "\n🎉 Congratulations! Your account is created on SBI Bank of India.\n\n";
}

// Deposit
void Bank_acc::deposit_money(void)
{
    cout << "Enter deposit amount: " << endl;
    cin >> deposit;
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (entered_acc == acc_num && entered_pin == pin)
    {
        // sahi hai, aage ka kaam karo
        balance += deposit;
        cout << "✅ Your money is successfully deposited to account " << acc_num << endl;
    }
    else
    {
        cout << "❌ Invalid account number or PIN.\n";
    }
}

// Credit
void Bank_acc::credit_money(void)
{
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (entered_acc == acc_num && entered_pin == pin)
    {
        cout << "Enter Credit amount: " << endl;
        cin >> credit;
        if (credit <= balance)
        {
            balance -= credit;
            cout << "✅ Amount credited successfully." << endl;
        }
        else
        {
            cout << "❌ Insufficient balance!" << endl;
        }
    }
    else
    {
        cout << "❌ Invalid account number or PIN.\n";
    }
}
// Check balance
void Bank_acc::check_balance(void)
{
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (entered_acc == acc_num && entered_pin == pin)
    {
        cout << "Your current balance is: ₹" << balance << endl;
    }
    else
    {
        cout << "❌ Invalid account number or PIN.\n";
    }
}

// withdraw
void Bank_acc::withdraw_money(void)
{

    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (entered_acc == acc_num && entered_pin == pin)
    {
        cout << "Enter withdrawal amount: " << endl;
        cin >> withdraw;
        if (withdraw <= balance)
        {
            balance -= withdraw;
            cout << "✅ Withdrawal successful!" << endl;
        }
        else
        {
            cout << "❌ Insufficient balance!" << endl;
        }
    }
    else
    {
        cout << "❌ Invalid account number or PIN.\n";
    }
}

// Display details
void Bank_acc::display_acc(void)
{
    cout << "Enter Account Number: " << endl;
    cin >> entered_acc;
    cout << "Enter PIN: " << endl;
    cin >> entered_pin;

    if (entered_acc == acc_num && entered_pin == pin)
    {
        cout << "Name: " << name << endl;
        cout << "Father's Name: " << father << endl;
        cout << "Phone: " << phone_str << endl;
        cout << "Age: " << age << endl;
        cout << "Account Number: " << acc_num << endl;
        cout << "Balance: ₹" << balance << endl;
    }
    else
    {
        cout << "❌ Invalid account number or PIN.\n";
    }
}

int main()
{
    Bank_acc user;
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
        switch (choice)
        {
        case 1:
            user.create_acc();
            break;
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
        case 0:
            cout << " Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
        cout << "-----------------------------------------------\n";
    } while (choice != 0);
    return 0;
}