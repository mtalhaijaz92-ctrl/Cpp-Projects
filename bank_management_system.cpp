#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNo;
    string name;
    double balance;

public:
    Account(int acc, string n, double b)
    {
        accountNo = acc;
        name = n;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance.\n";
        }
        else
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    virtual void showDetails()
    {
        cout << "\nAccount No: " << accountNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};


class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int acc, string n, double b, double rate)
        : Account(acc, n, b)
    {
        interestRate = rate;
    }

    void showDetails() override
    {
        Account::showDetails();
        cout << "Account Type: Savings" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};


class CurrentAccount : public Account
{
private:
    double overdraftLimit;

public:
    CurrentAccount(int acc, string n, double b, double limit)
        : Account(acc, n, b)
    {
        overdraftLimit = limit;
    }

    void showDetails() override
    {
        Account::showDetails();
        cout << "Account Type: Current" << endl;
        cout << "Overdraft Limit: Rs. "
             << overdraftLimit << endl;
    }
};


int main()
{
    SavingsAccount s1(1001, "Ali", 50000, 7);

    CurrentAccount c1(1002, "Ahmed", 80000, 20000);

    cout << "===== SAVINGS ACCOUNT =====" << endl;

    s1.deposit(10000);
    s1.withdraw(5000);
    s1.showDetails();

    cout << "\n===== CURRENT ACCOUNT =====" << endl;

    c1.withdraw(10000);
    c1.showDetails();

    return 0;
}