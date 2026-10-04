#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName();
		cout << "\nLastName    : " << Client.LastName();
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email();
		cout << "\nPhone       : " << Client.Phone();
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

public:

	static void ShowWithdarwScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");

		cout << "\nPlease Enter Account Number You Want to Withdarw : ";
		string AccNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccNumber))
		{
			cout << "\n\nThis Account Doesn't Exist, please enter another Account Number : ";
			AccNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter Amount : ";
		Amount = clsInputValidate::ReadDblNumber("Please Enter a Number : ");

		char Answer;
		cout << "Are you sure you want to Withdraw this Amount ? (y / n) : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\n\nAmount Withdarw Successfully :-)\n";
				cout << "\n\nThe new balance is : " << Client1.AccountBalance;
			}
			else
			{
				cout << "\n\nIncorrect Transaction :-(\n";
				cout << "Amount is : " << Amount;
				cout << "\nYour Balance is : " << Client1.AccountBalance << endl;
			}
		}
		else
		{
			cout << "\n\nWithdarw Failed :-(\n";
		}
	}
};

