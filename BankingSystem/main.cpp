#include <iostream>
// Declaration of All the variables to be used in  all functions
using namespace std;
double balance = 300;
double DepositAmount;
double WithdrawalAmount;
int AccountNumber, RecepientAccountNumber, ATM_Pin;
int CellphoneNumber, BranchCode, RecepientPhone;
string fullname, RecepientName;

void UserInput()    // function of allowing the user to input thier credentials for card transactions
{
    cout << "------------------Card Details---------------------"<< endl;
    cout << "Insert Your Card"<< endl;
    cout << endl;
    cout << "Enter 10-Digit Account Number: ";
    cin >> AccountNumber;
    cout << "Enter Your 5-Digit Card PIN: ";
    cin >> ATM_Pin;
    cout << endl;
    cout << "Card Verified successfully!!!" << endl;
    cout << "---------------------------------------------------"<< endl;
}

void Showbalance()   // function for checking bank balance
{
    UserInput();
    cout << "Your Current Balance: R"<< balance<< endl;
}
void deposit()      // deposit interface for making deposits
{
    int DepositOption;
    cout << "---------------------------Deposit Menu----------------------------------" << endl;
    cout << "1. Card Deposit"<< endl;
    cout << "2. Cardless Deposit"<< endl;
    cin >> DepositOption;
    cout << "-------------------------------------------------------------------------" << endl;
    switch (DepositOption)
    {
        case 1: // case for card deposit
            UserInput();
            cout << "Enter Deposit Amount: ";
            cin >> DepositAmount;
            while (DepositAmount <=0)
            {
                cout << "Invalid Amount!, Please Enter a Valid Deposit Amount: ";
                cin >> DepositAmount;
            }
            balance = balance + DepositAmount;
            cout << "You Have Deposited R"<< DepositAmount<<" into your account"<<endl;
            cout << "New Balance: R"<< balance<< endl;
            break;
        case 2: // case for cardless deposits
            cin.ignore();
            cout << "Enter Recepient's Name: ";
            getline(cin, RecepientName);
            cout << "Enter Recepient's  10-Digit Account Number: ";
            cin >> RecepientAccountNumber;
            cout << "Enter Recepient's CellPhone Number: ";
            cin >> RecepientPhone;
            cout << "Enter Deposit Amount: ";
            cin >> DepositAmount;
            cout << endl;
            while (DepositAmount <=0)
            {
                cout << "Invalid Amount!, Please Enter a Valid Deposit Amount" << endl;
                cin >> DepositAmount;
            }
            cout << "Recepient Name: "<<RecepientName<<endl;
            cout << "Recepient Account Number: "<< RecepientAccountNumber<<endl;
            cout << "Phone Number: "<<RecepientPhone<<endl;
            cout << "Deposit Amount: R"<<DepositAmount<<endl;
            break;
        default:
             while (DepositOption)
             {
                 cout << "Invalid Deposit Option!, Try again" << endl;
                 cin >> DepositOption;
             }
            break;
    }


}
void Withdraw()     // Withdrawal Interface for making withdrawals
{
    int Withdrawal_Option;
    int OTP;
    int TransactionOption;
    cout << "----------------Withdrawals-----------------------" << endl;
    cout << "1. Card Withdrawal" << endl;
    cout << "2. Cardless Withdrawal" << endl;
    cin >> Withdrawal_Option;
    cout << "--------------------------------------------------" << endl;
    cout << endl;
    switch (Withdrawal_Option)
    {
        case 1:
            UserInput();
            cout << " Enter Withdrawal Amount: ";
            cin >> WithdrawalAmount;
            while ( WithdrawalAmount > balance || WithdrawalAmount <= 0 )
            {
                cout << "Invaild Withdrawal Amount, Enter a valid amount!!!"<< endl;
                cin >> WithdrawalAmount;
            }
                balance = balance - WithdrawalAmount;
                cout << "You Withdrew R"<<WithdrawalAmount<<" From Your Account"<<endl;
                cout << "New Balance: R"<< balance << endl;
            break;
        case 2:
            cout << "Enter 10-Digit Phone Number: ";
            cin >> CellphoneNumber;
            cout << "Enter The 4-Digit OTP Sent To The Entered Number: ";
            cin >> OTP;
            cout << endl;
            cout << "Enter Withdrawal Amount: ";
            cin >> WithdrawalAmount;
            if ( WithdrawalAmount <= 0)
            {
                cout << "Invaild Withdrawal Amount, Enter a valid amount!!!"<< endl;
            }
            else
            {
                cout << "1. Confirm Transaction" << endl;
                cout << "2. Cancel Transaction" << endl;
                cin >> TransactionOption;
            }
                switch (TransactionOption)
                {
                    case 1:
                        cout << "A Cardless Withdrawal Of R"<<WithdrawalAmount<< " Has Been Made Successfully, Thank You For Banking With Us!"<< endl;
                        break;
                    case 2:
                        cout << "Process Cancelled" << endl;
                        break;
                    default:
                        while (TransactionOption)
                        {
                          cout << "Invalid input!!!, Try Again" << endl;
                          cin >> TransactionOption;
                        }
                        break;
                }
            break;
        default:
            while (Withdrawal_Option)
            {
                cout << "Invalid Option!!!, Try Again"<< endl;
                cin >> Withdrawal_Option;
            }
            break;
    }


}

void SendMoney ()
{
    int sendOption;
    double sendAmount;
    int ewalletPin;
    int transactionOption;
    string bankName;
    cout << "------------------------Send Money--------------------------"<< endl;
    cout << "1. eWallet (Send to Cellphone)" << endl;
    cout << "2. EFT (Bank-to-Bank Transfer)" << endl;
    cout << "Select Transfer Type: ";
    cin >> sendOption;
    cout << endl;
    cout << "------------------------------------------------------------"<< endl;
    switch (sendOption)
    {
        case 1: // eWallet Transfer
            cout << "Enter Recipient 10-Digit Cellphone Number: ";
            cin >> RecepientPhone;
            cout << "Create a 4-Digit eWallet PIN for Recipient: ";
            cin >> ewalletPin;
            cout << "Enter Amount to Send: R";
            cin >> sendAmount;
            cout << endl;

            while (sendAmount <= 0 || sendAmount > balance)
            {
                cout << "Invalid Amount! Please enter a valid amount: " << endl;
                cin >> sendAmount;
            }
            cout << "1. Confirm eWallet transaction"<< endl;
            cout << "2. Cancel Transaction"<< endl;
            cin >> transactionOption;
             switch (transactionOption)
                {
                    case 1:
                        balance -= sendAmount;
                        cout << "eWallet of R" << sendAmount << " sent to " << RecepientPhone << " successfully!" << endl;

                        break;
                    case 2:
                        cout << "eWallet Transaction Cancelled." << endl;
                        break;
                    default:
                        while (transactionOption)
                        {
                          cout << "Invalid Input!!, try again" << endl;
                          cin >> transactionOption;
                        }
                        break;
                }
                break;
            case 2: // EFT Transfer
            cin.ignore(); // Clears leftover newline before getline
            UserInput();
            cout << endl;
            cout << "Enter Recipient Full Name: ";
            getline(cin, RecepientName);
            cout << "Enter Recipient Bank Name (e.g., FNB, Capitec, Standard Bank, Nedbank, Absa): ";
            getline(cin, bankName);
            cout << "Enter Recipient 10-Digit Account Number: ";
            cin >> RecepientAccountNumber;
            cout << "Enter Amount to Send: R";
            cin >> sendAmount;
            cout << endl;

                while (sendAmount <= 0 || sendAmount > balance)
                {
                    cout << "Invalid Amount! Please enter a valid amount." << endl;
                    cin >> sendAmount;
                }
                cout << "1. Confirm EFT transaction"<< endl;
                cout << "2. Cancel Transaction"<< endl;
                cin >> transactionOption;
                  switch (transactionOption)
                    {
                        case 1:
                            balance -= sendAmount;
                            cout << "EFT of R" << sendAmount << " to " << RecepientName << " processed successfully!" << endl;
                            break;
                        case 2:
                            cout << "EFT Transaction Cancelled." << endl;
                            break;
                        default:
                            cout << "Invalid Input!!" << endl;
                            break;
                }
                break;
            default:
            cout << "Invalid Transfer Option! Please select 1 or 2." << endl;
            break;
            }

}

void Exit()    // function ending the whole program
{
    cout << "Thank you For Banking With Us, Have A Good Day!" << endl;
}
void Menu()     // the main menu that the user can interact with to make a transaction
{
    int option;
    do
    {
        cout << "Enter 1 To Check Your Balance"<< endl;
        cout << endl;
        cout << "Enter 2 To Deposit Money"<< endl;
        cout << endl;
        cout << "Enter 3 To Withdraw Money"<< endl;
        cout << endl;
        cout << "Enter 4 To Send Money"<< endl;
        cout << endl;
        cout << "Enter 5 To Exit"<< endl;
        cout << endl;
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
            Showbalance();
            cout << endl;
            cout << "======================================================================================" << endl;
            cout << endl;
            break;
        case 2:
            deposit();
            cout << endl;
            cout << "======================================================================================" << endl;
            cout << endl;
            break;
        case 3:
            Withdraw();
            cout << endl;
            cout << "======================================================================================" << endl;
            cout << endl;
            break;
        case 4:
            SendMoney();
            cout << endl;
            cout << "======================================================================================" << endl;
            cout << endl;
            break;
        case 5:
            Exit();
            break;
        default:
            cout << "Invalid Input!!!, Try Again" << endl;
            break;
        }
    } while (option != 5);

}
int main()
{
    // the interface of the banking system
    cout << "==================================FIRST NATIONAL BANK Ltd===============================" << endl;
    cout << "Welcome To FIRST NATIONAL BANK Ltd, How can we help?"<<endl;
    cout << endl;
    Menu ();
    cout << endl;
    cout << "======================================================================================" << endl;
    return 0;
}
