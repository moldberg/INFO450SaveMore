#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:
	const double S_DEDUCTION = 2.00;
public:
	SavingsAccount();
	int withdraw(double fundsOut);
	double assessInterest();
	void display();
};