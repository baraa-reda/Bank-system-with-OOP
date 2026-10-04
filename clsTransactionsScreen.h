#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <iomanip>

class clsTransactionsScreen : protected clsScreen
{
private:

    enum enTransactonsMenueOptions {eDeposit = 1, eWithDraw, eTotalBalances, eTransfer, eTransferLog, eMainMenu};

    static  void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

        system("pause>0");
        ShowTransactionsMenueScreen();
    }

    static void _ShowDepositScreen()
    {
       // cout << "\nHere will be Deposit Screen";

        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen()
    {
        //cout << "\nHere will be WithDraw Screen";

        clsWithdrawScreen::ShowWithdarwScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\nHere will be Total Balances Screen";

        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerformTransactionsMenueOptions(enTransactonsMenueOptions TranactionsOption)
    {
        switch (TranactionsOption)
        {
        case enTransactonsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactonsMenueOptions::eWithDraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactonsMenueOptions::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactonsMenueOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactonsMenueOptions::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactonsMenueOptions::eMainMenu:
        {
            
        }
        }
    }

public:

	static void ShowTransactionsMenueScreen()
    {
        system("cls");

        if (!_CheckAccessRight(clsUser::pTransactions))
        {
            return;
        }

        _DrawScreenHeader("\t Transactions Screen");

        cout << "\n=============================================\n";
        cout << setw(10) << "         Transactions Menue Screen   ";
        cout << "\n=============================================\n";
        cout << setw(6) << "[1] Deposit. \n";
        cout << setw(6) << "[2] Withdraw. \n";
        cout << setw(6) << "[3] Total Balances. \n";
        cout << setw(6) << "[4] Transfer. \n";
        cout << setw(6) << "[5] Transfer Log. \n";
        cout << setw(6) << "[6] Main Menue. \n";
        cout << "\n=============================================\n";

        _PerformTransactionsMenueOptions((enTransactonsMenueOptions)
            clsInputValidate::ReadShortNumberBetween(1, 6,"Please Enter a number between 1 and 6"));
    }
};

