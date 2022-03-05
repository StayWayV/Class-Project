
#pragma once

#include <iostream>
using namespace std;

enum   TransactionType { Deposit, WithDrawl };


class Transaction
{
private:
	static int GlobalTransaction;
	int TransactionID{ 0 };
	double Amount{ 0 };
	double EndingBalance{ 0 };
	TransactionType Type{ Deposit };
public:
	Transaction() {};
	static Transaction CreateDeposit(double amount,double endingbal);
	static Transaction CreateWithdrawl(double amount, double endignbal);
	friend ostream& operator<<(ostream& os, const Transaction& trans);
	int getTransactionId() { return TransactionID;}
	double getAmount() { return Amount; }
	double getEndingBalance() { return EndingBalance; }
};
