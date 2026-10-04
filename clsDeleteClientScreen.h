#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDeleteClientScreen : protected clsScreen
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

public:

	static void DeleteClientScreen()
	{
		if (!_CheckAccessRight(clsUser::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis Account Number Doesn't exist, please enter another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		clsBankClient::enSaveResults SaveResult;

		clsDeleteClientScreen::_PrintClient(Client);

		cout << "\n\nAre you sure you want to delete this account ? (y / n) : ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nAcount deleted successfully : -)";

				_PrintClient(Client);
			}
			else
			{
				cout << "\nError :-(";
			}
		}
	}
};

