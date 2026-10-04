#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
private:

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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen");

		cout << "\nPlease Enter Account Number You Want to Deposit : ";
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
		cout << "Are you sure you want to Deposit this Amount ? (y / n) : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Deposit(Amount);
			cout << "\n\nAmount added successfully :-)\n";
			cout << "\n\nThe new balance is : " << Client1.AccountBalance;
		}
		else
		{
			cout << "\n\nDeposit Failed :-(\n";
		}
	}
};

