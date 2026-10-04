#pragma once
#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enMethods {ByCode = 1, ByCountry};

	static short _ReadMethodChoice()
	{
		short Choice = 0;
		cout << "\n\nFind By : Code [1] or Country [2] ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "\nPlease Enter a number between 1 and 2 : ");
		return Choice;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n\n__________________________";
		cout << "\nCountry : " << Currency.Country();
		cout << "\nCode    : " << Currency.CurrencyCode();
		cout << "\nName    : " << Currency.CurrencyName();
		cout << "\nRate(1$): " << Currency.Rate();
		cout << "\n__________________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

	static void _FindByCode()
	{
		string Code = "";
		cout << "\n\nPlease Enter Currency Code : ";
		Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		
		_ShowResults(Currency);
	}

	static void _FindByCountry()
	{
		string Country = "";
		cout << "\n\nPlease Enter Country : ";
		Country = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(Country);

		_ShowResults(Currency);
	}

	static void _PerformFindMethodOption(enMethods Option)
	{
		switch (Option)
		{
		case enMethods::ByCode:
			_FindByCode();
			break;

		case enMethods::ByCountry:
			_FindByCountry();
			break;
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t    Find Currency Screen");

		_PerformFindMethodOption((enMethods)_ReadMethodChoice());
	}
};

