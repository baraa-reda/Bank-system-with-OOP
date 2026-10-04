#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUser.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenueOptions {
		eListUsres = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUsers = 4, eFindUsers = 5, eMainMeneu
	};

	static short _ReadManageUsersOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToManageUsersScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowUserListScreen()
	{
		// cout << "\nHere will be user list screen";

		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAdddNewUserScreen()
	{
		// cout << "\nHere will be add new user screen";

		clsAddNewUser::AddAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		// cout << "\nHere will be delete user screen";

		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		// cout << "\nHere will be Update user screen";

		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		// cout << "\nHere will be Find user screen";

		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersOptions(enManageUsersMenueOptions UsersOption)
	{
		switch (UsersOption)
		{
		case enManageUsersMenueOptions::eListUsres:
		{
			system("cls");
			_ShowUserListScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAdddNewUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUsers:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersMenueOptions::eFindUsers:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case enManageUsersMenueOptions::eMainMeneu:
		{
			
		}
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		system("cls");

		if (!_CheckAccessRight(clsUser::pManageUsers))
		{
			return;
		}

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show User List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] MainMenu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersOptions(enManageUsersMenueOptions(_ReadManageUsersOption()));
	}
};

