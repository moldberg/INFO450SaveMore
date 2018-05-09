#include "stdafx.h"
#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount()
{
}

int SavingsAccount::withdraw(double fundsOut)
{
	if (fundsOut + S_DEDUCTION > balance)
	{
		return -1; //User error: Balance is not allowed to go negative
	}
	balance -= fundsOut + S_DEDUCTION;
	assessInterest();
	cout << "\nTransaction OK, with withdraw fee of $" << S_DEDUCTION << endl;
	return 0;
}

double SavingsAccount::assessInterest()
{
	if (balance < 10000.00)
	{
		interestRate = 1.0/12;
	}
	else
	{
		interestRate = 2.0/12;
	}
	return balance * 0.01 * interestRate;
}

void SavingsAccount::display()
{
	cout << "Savings Account #" << accountNumber << endl;
	cout << "\tBalance: $" << balance << endl;
	cout << "\tExpected balance in 1 month: ";
		cout << balance + assessInterest() << endl;
	cout << "\tMonthly Interest: " << interestRate << "\n\n";
}