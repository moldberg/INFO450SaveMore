#include "stdafx.h"
#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount()
{
	interestRate = 0;
}

int CheckingAccount::withdraw(double fundsOut)
{
	if (balance >= 500)
		eligibleForDeduction = true;
	if (fundsOut + CH_DEDUCTION > balance)
	{
		return -1; //User error: Balance is not allowed to go negative
	}
	balance -= fundsOut;
	if (balance < 500.00 && eligibleForDeduction)
		balance -= CH_DEDUCTION;
	cout << CH_DEDUCTION << " deducted from account for sub-minimum balance\n";
	cout << "\nTransaction OK.\n";
	return 0;
}

void CheckingAccount::orderChecks()
{
	if (balance >= CH_PRICE)
	{
		if (balance < 515 && balance >= 500)
			balance -= CH_DEDUCTION;
		balance -= 15;
	}
	else
	{
		cout << "Sorry, current account balance doesn't allow checks to be\n";
		cout << "ordered at this time. Account must hold at least $";
		cout << CH_PRICE << endl << endl;
	}
}

void CheckingAccount::display()
{
	cout << "Checking Account #" << accountNumber << endl;
	cout << "\tBalance: $" << balance << endl << endl;
}
