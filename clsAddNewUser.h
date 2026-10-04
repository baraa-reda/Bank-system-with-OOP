#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsAddNewUser : protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName : ";
        User.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName : ";
        User.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email : ";
        User.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone : ";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password : ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permissions : ";
        User.Permissions = _ReadPermissions();

    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nAcc. Number : " << User.GetUserName();
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << to_string(User.Permissions);
        cout << "\n___________________\n";
    }

    static short _ReadPermissions()
    {
        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register Screen ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        return Permissions;

    }

public:
    static void AddAddNewUserScreen()
    {
        string Username = "";

        _DrawScreenHeader("\t Add New User");

        cout << "\nPlease Enter Username : ";
        Username = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is alreday exist, Choose Another one : ";
            Username = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(Username);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::svSucceeded:
        {
            cout << "\nUser Added Successfully \n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::svFaildEmptyObject:
        {
            cout << "\nError User was mot saved becaus tis Empty \n";
            break;
        }
        case clsUser::svFaildUserExists:
        {
            cout << "\nFaild because Account is already used \n";
            break;
        }
        }
    }
};

