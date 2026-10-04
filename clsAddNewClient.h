#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsAddNewClient : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& C)
    {
        cout << "\nEnter FirstName : ";
        C.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName : ";
        C.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email : ";
        C.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone : ";
        C.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode : ";
        C.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance : ";
        C.SetAccountBalance(clsInputValidate::ReadDblNumber("Number is Invalid"));
    }

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
    static void AddNewClient()
    {
        if (!_CheckAccessRight(clsUser::pAddNewClient))
        {
            return;
        }

        string AccountNumber = "";

        _DrawScreenHeader("\t Add New Client");

        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is alreday exist, Choose Another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::svSucceded:
        {
            cout << "\nAccount Added Successfully \n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::svFaildEmptyObject:
        {
            cout << "\nError account was mot saved becaus tis Empty \n";
            break;
        }
        case clsBankClient::svFaildAccountNumberExsist:
        {
            cout << "\nFaild because Account is already used \n";
            break;
        }
        }
    }
};

