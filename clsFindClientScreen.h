#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
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

	static void ShowFindClientScreen()
	{

		if (!_CheckAccessRight(clsUser::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("Find Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (Client.IsEmpty())
		{
			cout << "\nClient Was not found :-( ";
		}
		else
		{
			cout << "\nClient was found :-) \n";

			_PrintClient(Client);
		}
	}
};

