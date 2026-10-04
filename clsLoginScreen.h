#pragma once
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool IsLoginFailed = false;

		short Trials = 3;

		string Username, Password;

		do
		{
			if (IsLoginFailed)
			{
				cout << "\nInvalid Username / Password :-(\n";
				Trials--;
				cout << "\nYou Have " << Trials << " Trials to login\n";
			}

			if (Trials == 0)
			{
				cout << "\n\nThe system has Locked :-(\n\n";
				return false;
			}
				

			cout << "\nEnter Username : ";
			cin >> Username;

			cout << "\n\nEnter Passowrd : ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			IsLoginFailed = CurrentUser.IsEmpty();

			

		} while (IsLoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen ");
		return _Login();
	}
};

