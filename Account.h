#pragma once
#include <string>
#include <iostream>
#include "Transaction.h"
#include <vector>

using namespace std;

class Account
{
	private:
      	std::string FirstName{""};
		std::string LastName{ "" };
		std::string AccountNumber{ "" };
		std::string PinNumber{ "" };
        std::vector<Transaction> Transactions;
        double Balance{ 0 };
public:
    Account();
    Account(std::string FirstName, std::string LastName, std::string AccountNumber, std::string PinNumbger,double balance);
    std::string getFirstName();
    std::string getLastName();
    std::string getAccountNumber();
    //std::string getPinNumber();
    void MakeDepoist(double amt);
    void MakeWithdrawl(double amt);

    friend ostream& operator<<(ostream& os, const Account& acct);  //formatted output

    friend bool operator==(const Account& LHS, const Account& RHS); //equality comparison for sorting and searching

    //return a copy of transactions for external users so they can do what they will but not modify our data
    std::vector<Transaction> GetTransactions() 
    {
        std::vector<Transaction> v(Transactions.size());
        std::copy(Transactions.begin(), Transactions.end(), v.begin());
        return v;
    }
   

};

