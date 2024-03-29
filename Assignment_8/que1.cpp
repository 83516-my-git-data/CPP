// Q1. Write a class to store Account information of Bank customer by using following class diagram.
// Use enum to store information of account type.
// Create an array of 5 Accounts in main() and accept their details from user.
// Write Menu driven program to deposit/withdraw amount from the account.
// After each transaction display updated account balance.
// Throw exceptions for invalid values.
// Also implement an exception class InsufficientFundsException.
// In withdraw if sufficient balance is not available in account or while deposit the entered amount is
// negative then throw this exception.

#include <iostream>
using namespace std;

enum EAccountType
{
    SAVING = 1,
    CURRENT,
    DMAT
};

class InsufficientFundsException
{
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    InsufficientFundsException(int accno, double currentBalance, double withdrawAmount)
    {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;
    }
    void display()
    {
        cout << "Account Number - " << accno << endl;
        cout << "Account Balance - " << currentBalance << endl;
        cout << "Amount want to withdraw - " << withdrawAmount << endl;
        cout << "Your account balance is insufficient ..." << endl;
    }
};

class Account
{
private:
    int accno;
    EAccountType type;
    double balance;

public:
    Account()
    {
        accno = 10001;
        type = SAVING;
        balance = 5000;
    }

    Account(int accno, EAccountType type, double balance)
    {
        this->accno = accno;
        this->type = type;
        this->balance = balance;
    }

    void accept()
    {
        int choice;
        cout << endl
             << "1) SAVING" << endl
             << "2) CURRENT" << endl
             << "3) DMAT" << endl
             << "ENTER YOUR ACCOUNT TYPE TO CREATE : ";
        cin >> choice;
        if (choice <= 0 || choice > 3)
            throw 'a';
        type = EAccountType(choice);
        cout << "ENTER YOUR ACCOUNT NUMBER : ";
        cin >> accno;

        if (accno < 0)
            throw 1;

        cout << "ENTER YOUR ACCOUNT AMOUNT : ";
        cin >> balance;
        if (balance < 0 || balance < 500)
            throw 2.5;
        cout << "ACCOUT IS CREATED..." << endl;
    }

    void display()
    {
        cout << "ACCOUNT TYPE : " << type << endl;
        cout << "ACCOUNT NUMBER  : " << accno << endl;
        cout << "ACCOUNT BALANCE : " << balance << endl;
    }
    int getAccountNo()
    {
        return accno;
    }
    int getType()
    {
        return type;
    }
    double getBalance()
    {
        return balance;
    }

    void deposite(double amount)
    {
        if (amount < 0)
            throw 2;
        cout << "YOUR CURRENT BALANCE : " << balance << endl;
        this->balance = this->balance + amount;
        cout << "AFTER DEPOSITE BALANCE = " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (getBalance() < amount)
            throw InsufficientFundsException(getAccountNo(), getBalance(), amount);
        cout << "YOUR CURRENT BALANCE : " << balance << endl;
        this->balance = this->balance - amount;
        cout << "AFTER WITHDRAW BALANCE = " << balance << endl;
    }
};

int main()
{
    Account *arr[5];
    int index = 0;
    int choice;

    do
    {
        cout << endl;
        cout << "0. EXIT " << endl;
        cout << "1. CREATE AN ACCOUNT " << endl;
        cout << "2. TO DISPLAY ALL ACCOUNT NUMBERS " << endl;
        cout << "3. TO WITHDRAW OR DEPOSITE" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "THANK YOU...." << endl;
            break;

        case 1:
            try
            {
                if (index < 5)
                {
                    arr[index] = new Account;
                    arr[index]->accept();
                    index++;
                }
                else
                    cout << "NO SUCH ACCOUNT EXIST..." << endl;
            }
            catch (int error)
            {
                cout << "ACCOUNT NO. SHOULD NOT BE NEGATIVE...." << endl;
            }
            catch (char error)
            {
                cout << "INVALID -> SELECT YOUR ACCOUNT TYPE AGAIN..." << endl;
            }
            catch (double error)
            {
                cout << "MINIMUM RS.500/- REQUIRED TO CREATE AN ACCOUNT " << endl;
            }
            catch (...)
            {
                cout << "SOMETHING WENT WRONG..." << endl;
            }
            break;

        case 2:
            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getType() == 1)
                {
                    cout << "SAVING ACCOUNTS :" << endl;
                    cout << arr[i]->getAccountNo() << endl;
                }
                else if (arr[i]->getType() == 2)
                {
                    cout << "CURRENT ACCOUNTS :" << endl;
                    cout << arr[i]->getAccountNo() << endl;
                }
                else if (arr[i]->getType() == 3)
                {
                    cout << "DMAT ACCOUNTS :" << endl;
                    cout << arr[i]->getAccountNo() << endl;
                }
            }
            break;
        case 3:
        {
            int acno;
            cout << "ENTER YOUR ACCOUNT NUMBER: ";
            cin >> acno;
            for (int i = 0; i < index; i++)
            {
                int a;
                double wamount;
                double damount;
                cout << "0] GO BACK" << endl
                     << "1] TO WITHDRAW" << endl
                     << "2] TO DEPOSITE" << endl
                     << "SELECT YOUR CHOICE : ";
                cin >> a;
                if (a == 1)
                {
                    cout << "ENTER WITHDRAW AMMOUNT : ";
                    cin >> wamount;
                    try
                    {
                        arr[i]->withdraw(wamount);
                    }
                    catch (InsufficientFundsException e)
                    {
                        e.display();
                    }
                }
                else if (a == 2)
                {
                    try
                    {
                        cout << "ENTER DEPOSITE AMMOUNT : ";
                        cin >> damount;
                        arr[i]->deposite(damount);
                    }
                    catch (int error)
                    {
                        cout << "SOMETHING WENT WRONG PLEASE CHECK AMOUNT..." << endl;
                    }
                }
                else
                    break;
            }
        }
        break;
        }

    } while (choice != 0);

    for (int i = 0; i < index; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }

    return 0;
}
