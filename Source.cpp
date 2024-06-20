//Реалізуйте клас BankAccount з полями для номера рахунку, балансу та
//ласника.Напишіть методи для поповнення, зняття коштів та перевірки балансу.
//Створіть об'єкти цього класу та продемонструйте їх використання.




#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:

    string accountNumber;
    double balance;
    string owner;

public:

    BankAccount(const string& accNumber, const string& accOwner, double initialBalance = 0.0)
        : accountNumber(accNumber), owner(accOwner), balance(initialBalance) {}


    void deposit(double amount) 
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accountNumber << ". New balance: " << balance << endl;
        }
        else 
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }



    void withdraw(double amount) 
    {
        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << ". New balance: " << balance << endl;
        }
        else 
        {
            cout << "Invalid withdraw amount or insufficient funds!" << endl;
        }
    }





    double getBalance() const 
    {
        return balance;
    }


    void displayAccountInfo() const 
    
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << owner << endl;
        cout << "Balance: " << balance << endl;
    }
};

void main() 
{

    BankAccount account1("123456", "Alice", 1000.0);
    BankAccount account2("654321", "Bob");


    account1.displayAccountInfo();
    account2.displayAccountInfo();

    account1.deposit(500.0);

    account1.withdraw(200.0);


    account2.deposit(1000.0);
    account2.withdraw(1500.0);


    cout << "Balance of account 1: " << account1.getBalance() << endl;
    cout << "Balance of account 2: " << account2.getBalance() << endl;


}