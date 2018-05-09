#include "stdafx.h"
#include "CDAccount.h"
#include <iostream>

CDAccount::CDAccount()
{
}

double CDAccount::assessInterest()
{
	if (term < 60)
	{
		interestRate = 5.0/12;
	}
	else
	{
		interestRate = 10.0/12;
	}
	return balance * 0.01 * interestRate;
}

void CDAccount::display()
{
	cout << "Certificate of Deposit Account #" << accountNumber << endl;
	cout << "\tTerm: " << term << " months\n";
	cout << "\tBalance: $" << balance << endl;
	cout << "\tExpected balance in 1 month: ";
		cout << balance + assessInterest() << endl;
	cout << "\tMonthly Interest: " << interestRate << "\n\n";
}

void CDAccount::setTerm()
{
	cout << "\nEnter the term of the CD (as a whole number of months): ";
	cin >> term;
}

