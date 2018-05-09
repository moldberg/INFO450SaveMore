#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
private:
	const double CH_DEDUCTION = 5.00;
	const double CH_PRICE = 15;
	bool eligibleForDeduction = false;
public:
	CheckingAccount();

	int withdraw(double fundsOut);
	void orderChecks();
	void display();
};