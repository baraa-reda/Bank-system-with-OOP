#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsUpdateClientScreen : protected clsScreen
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

    static void ShowUpdateClientScreen()
    {

        if (!_CheckAccessRight(clsUser::pUpdateClient))
        {
            return;
        }

        _DrawScreenHeader("Update Client Screen");

        string AccountNumber = "";

        cout << "\nPlease enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        
        _PrintClient(Client1);

        cout << "\n\nUpdate Client Info : ";
        cout << "\n________________________\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResults;

        SaveResults = Client1.Save();

        switch (SaveResults)
        {
        case clsBankClient::enSaveResults::svSucceded:
        {
            cout << "\nAccount Updated Successfully \n";
            _PrintClient(Client1);
            break;
        }
        case clsBankClient::svFaildEmptyObject:
        {
            cout << "\nError account was not saved its Empty \n";
            break;
        }
        }
    }
};

