//this function is used to delete the account of a particular customer
int remove_account()
{
    string account_to_remove, account_number, cnic, first_name, middle_name, last_name, month, date, year, city, mobile, country;

    cout << "Enter account number to remove or Press m for the main menu:";
    while (cin >> account_to_remove)
    {
        if (account_to_remove == "m")
            menu();  
        if (is_valid_entry(account_to_remove))
        {
            cout << "Not valid Entry enter again or Press m for main menu:";
            continue;
        }
        ifstream bank_data;
        bank_data.open("bankdata.txt", ios::in);
        bool flag = true;
        fstream temp;
        temp.open("temp.txt", ios::app);
        bank_data >> account_number >> cnic >> first_name >> middle_name >> last_name >> month >> date >> year >> city >> mobile >> country;

        while (!bank_data.eof())
        {
            if (account_to_remove == account_number)
            {
                cout << "Account is deleted" << endl;
                flag = false;
            }
            else
            {
                temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
            }
            bank_data >> account_number >> cnic >> first_name >> middle_name >> last_name >> month >> date >> year >> city >> mobile >> country;
        }

        if (account_to_remove != account_number || flag == false)
        {
            cout << "enter again or Press m for the main menu:";
        }
        bank_data.close();
        temp.close();
        remove("bankdata.txt");
        rename("temp.txt", "bankdata.txt");
    }
}