#include "Transaction.h"
#include <iostream>
#include <iomanip>
using namespace std;

//global transaction number (since we don't have a built in date type this will suffice for identifying transactions)
int Transaction::GlobalTransaction = 1000000;

Transaction  Transaction::CreateDeposit(double Amount,double endingBalance) 
{
	Transaction T;
	T.Type = Deposit;
	T.TransactionID = GlobalTransaction++;
	T.Amount = Amount;
	T.EndingBalance = endingBalance;
	return T;
}
 Transaction Transaction::CreateWithdrawl(double Amount,double endingBalance) {
		
	Transaction T;
	T.Type = WithDrawl;
	T.TransactionID = GlobalTransaction++;
	T.Amount = Amount;
	T.EndingBalance = endingBalance;
	return T;

}
//formatted output of our object
ostream& operator<<(ostream& os, const Transaction& Trans)
{
	string transtype = Trans.Type == Deposit ? "Deposit" : "Withdrawl";
	os << endl << std::setw(12) << "Transaction: ";
	os << std::setw(13) << Trans.TransactionID << endl;
	os << std::right << transtype << ":";
	os << std::right << fixed << std::setw(12) << setprecision(2) << "$" << Trans.Amount << endl;
	os << "Ending Balance:";
	os << right << fixed << std::setw(5) << setprecision(2) << "$" << Trans.EndingBalance << endl;
	
	return os;
}