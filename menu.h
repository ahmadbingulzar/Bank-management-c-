#include "create_account.h"
#include "update.h"
#include "view_customer_detail.h"
#include "view_information.h"
#include "exit.h"
#include "remove_account.h"

/*this is the menu function it displays the menu for the bank management system to user to select
any option*/
int menu()
{
    int validity_count = 0;
    string choice;
    int flag = 0;
    while (true)
    {
        cout << "CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM " << endl
             << "||||||| WELCOME TO THE MAIN MENU|||||||" << endl
             << "1:Create new account" << endl
             << "2:view information of all the accounts" << endl
             << "3:Update Address and Phone number" << endl
             << "4:View detail of a particular customer" << endl
             << "5:Delete Account" << endl
             << "6:Exit" << endl
             << endl
             << endl
             << "Enter your choice: " << endl;
        cin >> choice;
        if (choice == "1")
        {
            validity_count = 0;
            create_new_account();
        }
        else if (choice == "2")
        {
            validity_count = 0;
            view_information();
        }
        else if (choice == "3")
        {
            validity_count = 0;
            update_data();
        }
        else if (choice == "4")
        {
            validity_count = 0;
            view_customer_detail();
        }
        else if (choice == "5")
        {
            validity_count = 0;
            remove_account();
        }
        else if (choice == "6")
        {
            exit();
            return 0;
        }
        else if (choice.length() != 1)
        {
            validity_count++;
            cout << "wrong choice" << endl;
        }
        if (validity_count == 3)
        {
            cout << "Get out " << endl;
            break;
            //return 0;
        }
    }
}