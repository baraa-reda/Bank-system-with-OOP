#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;

		return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;

		return false;
	}

	static bool IsDateBetween(clsDate Date1, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
			clsDate::SwapDates(DateFrom, DateTo);

		if (clsDate::IsDate1AfterDate2(Date1, DateTo))
			return false;
		if (clsDate::IsDate1BeforeDate2(Date1, DateFrom))
			return false;

		return true;
	}

	static int ReadIntNumber(string Message)
	{
		int Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}


	static double ReadDblNumber(string Message)
	{
		double Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static float ReadFloatNumber(string Message)
	{
		float Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Message)
	{
		int Number = 0;

		cin >> Number;

		while (Number < From || Number > To)
		{
			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static short ReadShortNumberBetween(int From, int To, string Message)
	{
		short Number = 0;

		cin >> Number;

		while (Number < From || Number > To)
		{
			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Message)
	{
		double Number = 0;

		cin >> Number;

		while (Number < From || Number > To)
		{
			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};

