#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Account.h"
#include <string>

using namespace std;


class ATM
{
	private:
		static int GlobalAccountNumber;
		static int GlobalPinNumber;
		std::vector<Account> CustomerAccounts;
		std::string getNextAccount() 
		{
			return std::to_string(GlobalAccountNumber++);
		};
		std::string getNextPIN()
		{
			return std::to_string(GlobalPinNumber++);
		};
		void CreateAccounts();
		int PrintWithdrawlMenu();
		int PrintDepositMenu();
		void GetUserDetais();
		void PrintMainMenu();
		int getMenuChoiceIntRange(int low, int high);
		Account* currentUser;  //current user using the system selected from customer accounts

	public:
		ATM() 
		{ this->CreateAccounts(); 
		  currentUser = nullptr;
		}
		//search ATM accounts by account number and pin
		void  FindAccountByNumberAndPin(std::string acct, std::string pin);
		void RunSystem(); //Run the ATM
		
};

