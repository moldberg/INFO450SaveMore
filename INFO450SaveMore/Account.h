#pragma once
using namespace std;

class Account
{
protected:
	int accountNumber;
	double interestRate;
	double balance;

public:
	Account();
	Account(int aNum, double iRate, double bal);
	void setAccountNum();
	void setBalance();

	int deposit(double fundsIn);
	virtual int withdraw(double fundsOut);

	virtual double assessInterest();
	virtual void setTerm();
	virtual void orderChecks();
	virtual void display();
};
