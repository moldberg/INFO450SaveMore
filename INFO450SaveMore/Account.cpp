#include "stdafx.h"
#include "Account.h"
#include <iostream>

Account::Account()
{
	accountNumber = 0;
	double interestRate = 0;
	double balance = 0;
}

//Overloaded constructor, unused currently
Account::Account(int aNum, double iRate, double bal)
{
	accountNumber = aNum;
	interestRate = iRate;
	balance = bal;
}

void Account::setAccountNum()
{
	cout << "\nEnter account number: ";
	cin >> accountNumber;
}

void Account::setBalance()
{
	cout << "\nEnter opening balance: ";
	cin >> balance;
	assessInterest();
}

int Account::deposit(double fundsIn)
{
	if (fundsIn < 0.0)
		return -1;
	balance += fundsIn;
	if (balance < 0.0)
	{
		balance -= fundsIn; //Reverse transaction if something bizarre happens
		return -1;
	}
	assessInterest();
	cout << "\nTransaction OK.\n";
	return 0;
}

int Account::withdraw(double fundsOut)
{
	if (fundsOut > balance)
	{
		return -1; //User error: Balance is not allowed to go negative
	}
	balance -= fundsOut;
	cout << "\nTransaction OK.\n";
	return 0;
}

double Account::assessInterest()
{
	return 0;
}

void Account::setTerm()
{
}

void Account::orderChecks()
{

}

void Account::display()
{
}