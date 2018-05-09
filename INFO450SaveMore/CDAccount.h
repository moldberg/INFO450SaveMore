#pragma once
#include "Account.h"

class CDAccount : public Account
{
private:
	int term; //Double value in months
public:
	CDAccount();
	double assessInterest();
	void display();
	void setTerm();
};