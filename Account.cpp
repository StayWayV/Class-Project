#include "Account.h"


Account::Account()
{
    FirstName = "";
    LastName = "";
    AccountNumber = "";
    PinNumber = "";
    Balance = 0;
};

Account::Account(std::string FirstName, std::string LastName, std::string AccountNumber, std::string PinNumber,double balance)
{
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->AccountNumber = AccountNumber;
    this->PinNumber = PinNumber;
    this->Balance = balance;
}


//this class does not need to provide access to modify any of its data because an ATM Machine doesn't provide that capability so we don't have setters
std::string Account::getFirstName()  { return FirstName; }
std::string Account::getLastName() { return LastName; }
std::string Account::getAccountNumber()  { return AccountNumber; }
//std::string Account::getPinNumber()  { return PinNumber; }


void Account::MakeDepoist(double amt)
{
    if (amt > 0) {
        this->Balance += amt;
        this->Transactions.push_back(Transaction::CreateDeposit(amt, this->Balance));
    }
    else
        cout << endl << "deposits must be positive";
}

void Account::MakeWithdrawl(double amt)
{
    if (this->Balance >= amt) 
    {
        this->Balance -= amt;
        this->Transactions.push_back(Transaction::CreateWithdrawl(amt,this->Balance));
    }
    else
    {
        std::cout << endl << "Insufficient Funds Available";
    }
}

//formatted output of our object
ostream& operator<<(ostream& os, const Account& acct)
{
    os << "---------------------------------------------------------" << endl;
    os << "Name: " << acct.FirstName + " " + acct.LastName << endl;
    os << "Account Number: " << acct.AccountNumber<<endl;
    os << "Balance: " << acct.Balance << endl;
    os << "---------------------------------------------------------" << endl;
    return os;
}
// determine if two Account objects are equal
bool operator==(const Account& LHS, const Account& RHS)
{
   return LHS.AccountNumber == RHS.AccountNumber  && LHS.PinNumber==RHS.PinNumber;
}
