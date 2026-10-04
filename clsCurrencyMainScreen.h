#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>
#include "Global.h"

class clsCurrencyMainScreen : protected clsScreen
{
private:

	enum enCurrencyOptions {eListCurrencies = 1, FindCurrency, UpdateCurrency, CurrencyCalac, MainMenu};

	static short _ReadCurrencyOption()
	{
		short Option = 0;

		cout << "\nChoose what do you want to do ? [1 to 5] : ";
		Option = clsInputValidate::ReadShortNumberBetween(1, 5, "\nPlease enter number between [1 to 5]");

		return Option;
	}

	static void _GoBackToCurrencyMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Main Menue...\n";
		system("pause>0");
		ShowCurrencyMainMenu();
	}

	static void _ShowListCurrencies()
	{
		//cout << "\nHere will be List Currencies Screen \n";

		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrency()
	{
		//cout << "\nHere will be Find Currency Screen \n";

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrency()
	{
		//cout << "\nHere Will Be Update Currency Screen \n";

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalc()
	{
		//cout << "\nHere will be currency calaculator screen \n";

		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyMenuOption(enCurrencyOptions CurrecnyOption)
	{
		switch (CurrecnyOption)
		{
		case enCurrencyOptions::eListCurrencies:
			system("cls");
			_ShowListCurrencies();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOptions::FindCurrency:
			system("cls");
			_ShowFindCurrency();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOptions::UpdateCurrency:
			system("cls");
			_ShowUpdateCurrency();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOptions::CurrencyCalac:
			system("cls");
			_ShowCurrencyCalc();
			_GoBackToCurrencyMenu();
			break;

		case enCurrencyOptions::MainMenu:
		{

		}

		}
	}

public:

	static void ShowCurrencyMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tCurrency Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Main Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies\n";
		cout << setw(37) << left << "" << "\t[2] Find CUrrency..\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenuOption((enCurrencyOptions)_ReadCurrencyOption());
	}
};

