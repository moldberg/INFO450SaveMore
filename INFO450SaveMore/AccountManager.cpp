#include "stdafx.h"
#include "CheckingAccount.h"
#include "CDAccount.h"
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

const int DBSIZE = 100; //Max number of bank accounts

void displayIntro();
int optionsMenu(int accountType, Account *bankAccount);

int main()
{
	int i, selection, goAgain = 1;
	Account **ptr = NULL; //Double pointer list for accounts
	ptr = new Account*[DBSIZE];
	for (i = 0; i < DBSIZE; i++)
	{
		ptr[i] = NULL;
	}

	displayIntro();

	//Account creation and manipulation loop
	for (i = 0; i < DBSIZE && goAgain == 1; i++)
	{
		cout << "Select the type of new account you are creating:\n";
		cout << "1) Savings account (enter '1')\n";
		cout << "2) Checking account (enter '2')\n";
		cout << "3) Certificate of Deposit (enter '3')\n";
		cout << "   (Or '9' if you have no more accounts to create)\n>";

		cin >> selection;
		switch (selection)
		{
		case 1: //Savings case
			ptr[i] = new SavingsAccount();
			break;
		case 2: //Checking case
			ptr[i] = new CheckingAccount();
			break;
		case 3: //CD case
			ptr[i] = new CDAccount();
			break;
		case 9: //Exit the account creation menu
			goAgain = -99;
			i--; //Don't count this iteration towards the account count
			continue;
		default: //Unexpected numeric response
			i--; //
			continue; //Rewind i and return to condition/top of for loop
		}
		//Setters
		ptr[i]->setAccountNum();
		ptr[i]->setBalance();
		ptr[i]->setTerm(); //For CD; not to be changed after defining

		//Options menu loop
		while (optionsMenu(selection, ptr[i]) == 0);

		cout << "Keep going?\n";
		cout << "1) Enter '1' to create an account\n";
		cout << "2) Enter '2' to end and view account summaries.\n>";
		cin >> goAgain; //Entering any int but 1 will end the for loop
	}

	int accountsMade = i;

	cout << "   [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n";
	cout << " [ ] [ ] [ ] RESULTS [ ] [ ] [ ] \n";
	cout << "   [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n\n";
	cout << "You successfully opened " << accountsMade << " bank accounts.\n";
	cout << "See for yourself: \n\n";
	for (i = 0; i < accountsMade; i++)
	{
		ptr[i]->display();
		delete ptr[i];
	}
	delete [] ptr;
	return 0;

}

void displayIntro()
{
	cout << "           [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n";
	cout << "         [ ] [ ] [ ] WELCOME SAVE MORE USER! [ ] [ ] [ ]\n";
	cout << "           [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n\n";
	cout << "     \"Save More, where you save money and we save on memory\n";
	cout << "                costs through dynamic allocation!\" \n";
	cout << "         [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n";
	cout << "  (Note we also save by using a numeric-keypad only terminal.\n";
	cout << "   Our other Save More slogan is 'no chars, no exceptions.')\n";
	cout << "           [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] \n";
	cout << "         [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n";
	cout << "\nTo begin, instantiate your first bank account.\n\n";
}

int optionsMenu(int accountType, Account * bankAccount)
{
	//Account options menu
	bool inOptions = true;
	int option = 1;
	double dollars = 0;

	cout << "\nOptions Menu (" << typeid(*bankAccount).name() << "):\n";
	cout << "1) Display current account summary\n";
	cout << "2) Deposit funds\n";
	cout << "3) Withdraw funds\n";
	if (accountType == 2) //Checking case only
		cout << "4) Order check book\n";
	cout << "9) Save account details and close the options menu\n";
	cin >> option;
	switch (option)
	{
		case 1:
			bankAccount->display();
			break;
		case 2:
			cout << "\nEnter amount to be deposited into the account: $";
			cin >> dollars;
			if (bankAccount->deposit(dollars) != 0)
			{
				cout << "Error: Bad deposit input.\n";
			}
			break;
		case 3:
			cout << "\nEnter amount to be withdrawn from the account: $";
			cin >> dollars;
			if (bankAccount->withdraw(dollars) != 0)
				cout << "Error: Balance is not allowed to go negative.\n";
			break;
		case 4:
			if (accountType == 2)
			{
				bankAccount->orderChecks();
			}
			break;
		case 9:
			return 9;
		default:
			break;
	}
	return 0;
}
