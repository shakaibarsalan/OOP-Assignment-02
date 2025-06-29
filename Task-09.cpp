#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    int acc_no;
    double balance;

public:
    Account(int account_number, double balance);
    int getaccountno();
    int getbalace();
    void deposit(double amount);
    void withdraw(double amount);
    void display();
};
Account::Account(int account_number, double balance)
{
    this->acc_no = account_number;
    this->balance = balance;
}
int Account::getaccountno()
{
    return acc_no;
}
int Account::getbalace()
{
    return balance;
}
void Account::deposit(double amount)
{
    balance += amount;
}
void Account::withdraw(double amount)
{
    if (balance < amount)
    {
        cout << "======= Insufficient balance ======="
             << "\n";
        return;
    }
    balance -= amount;
}
void Account::display()
{
    cout << "   Account Number: " << acc_no << "\n";
    cout << "   Balance: $" << balance << "\n";
}

class saving_account : public Account
{
protected:
    double interest_rate;
    double interest;

public:
    saving_account(int acc_no, double balance, double interest_rate);
    double calculateInterest();
    void displaysaving();
};
saving_account::saving_account(int acc_no, double balance, double interest_rate)
    : Account(acc_no, balance)
{
    this->interest_rate = interest_rate;
}

double saving_account::calculateInterest()
{
    interest = balance * interest_rate / 100;
    balance += interest;
    return interest;
}
void saving_account::displaysaving()
{
    display();
    cout << "   Interest: " << calculateInterest() << "\n";
    cout << "   Interest Rate: " << interest_rate << "\n";
}

class checking_account : public Account
{
protected:
    int monthly_withdrawals;
    int max_withdrawals;
    double withdrawal_fee;

public:
    checking_account(int acc_no, double balance, int max_withdrawals, double withdrawal_fee, int monthly_withdrawals);
    bool withdraw_Amount();
    void displaycheck();
};
checking_account::checking_account(int acc_no, double balance, int max_withdrawals, double withdrawal_fee, int monthly_withdrawals)
    : Account(acc_no, balance)
{
    this->max_withdrawals = max_withdrawals;
    this->withdrawal_fee = withdrawal_fee;
    this->monthly_withdrawals = monthly_withdrawals;
}
bool checking_account::withdraw_Amount()
{
    if (monthly_withdrawals >= max_withdrawals)
    {
        return false;
    }
    else
    {
        balance -= withdrawal_fee;
        monthly_withdrawals++;
    }
}
void checking_account::displaycheck()
{
    display();
    cout << "   Monthly Withdrawals Balance: " << monthly_withdrawals << "\n";
    cout << "   Maximun Withdrawals: " << max_withdrawals << "\n";
    cout << "   Withdrawal Fee: " << withdrawal_fee << "\n";
}
class fixed_deposit_account : public Account
{
protected:
    double interest_rate;
    int term; // In months
    int monthsPassed;
    double interest;

public:
    fixed_deposit_account(int acc_no, double balance, double interest_rate, int term);
    bool withdraw();
    double cal_interest();
    void displayfix();
};
fixed_deposit_account::fixed_deposit_account(int acc_no, double balance, double interest_rate, int term)
    : Account(acc_no, balance)
{
    this->interest_rate = interest_rate;
    this->term = term;
}

bool fixed_deposit_account::withdraw()
{
    if (monthsPassed < term)
        return false;
}

double fixed_deposit_account::cal_interest()
{

    interest = balance * interest_rate / 100;
    balance += interest;
    return interest;
}
void fixed_deposit_account::displayfix()
{
    display();
    cout << "   Interest: " << cal_interest() << "\n";
    cout << "   Interest Rate: " << interest_rate << "\n";
    cout << "   Term in Month: " << term << "\n";
}
int main()
{
    int option;
    int acc_no;
    double balance;
    double interest_rate;
    int max_withdrawals;
    double withdrawal_fee;
    int term;
    int monthly_withdrawals;

    cout << "===== Welcome to the Banking System! =====\n\n";
    cout << "   Please choose an account type:\n";
    cout << "     1. Savings Account\n";
    cout << "     2. Checking Account\n";
    cout << "     3. Fixed Deposit Account\n";
    cout << "   Enter your choice (1-3): ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        cout << "   Enter Account Number: ";
        cin >> acc_no;
        cout << "   Enter Initial Balance: ";
        cin >> balance;
        cout << "   Enter Interest Rate: ";
        cin >> interest_rate;

        saving_account savingsAccount(acc_no, balance, interest_rate);
        savingsAccount.displaysaving();

        double depositAmount;
        cout << "   Enter the amount to deposit: ";
        cin >> depositAmount;
        savingsAccount.deposit(depositAmount);

        double withdrawAmount;
        cout << "   Enter the amount to withdraw: ";
        cin >> withdrawAmount;
        savingsAccount.withdraw(withdrawAmount);

        savingsAccount.calculateInterest();
        savingsAccount.displaysaving();
        break;
    }

    case 2:
    {
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Enter Max Withdrawals: ";
        cin >> max_withdrawals;
        cout << "Enter Withdrawal Fee: ";
        cin >> withdrawal_fee;
        cout << "Enter Monthly Withdrawals: ";
        cin >> monthly_withdrawals;

        checking_account checkingAccount(acc_no, balance, max_withdrawals, withdrawal_fee, monthly_withdrawals);
        checkingAccount.displaycheck();

        double depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        checkingAccount.deposit(depositAmount);

        checkingAccount.withdraw_Amount();

        checkingAccount.displaycheck();
        break;
    }

    case 3:
    {
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Enter Interest Rate: ";
        cin >> interest_rate;
        cout << "Enter Term (in months): ";
        cin >> term;

        fixed_deposit_account fixedDepositAccount(acc_no, balance, interest_rate, term);
        fixedDepositAccount.displayfix();

        double depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        fixedDepositAccount.deposit(depositAmount);

        fixedDepositAccount.cal_interest();
        fixedDepositAccount.displayfix();
        break;
    }

    default:
        cout << "Invalid choice. Exiting the program."
             << "\n";
        return 0;
    }

    return 0;
}
