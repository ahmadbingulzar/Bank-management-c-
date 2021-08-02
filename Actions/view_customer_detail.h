bool entry_check(string account_number_check)
{
    ifstream check;
    check.open("bankdata.txt", ios::in);

    string middle_name, last_name, city, country, month, first_name, date, year, cnic, mobile, account_number;

    while (!check.eof())
    {
        check >> account_number >> cnic >> first_name >> middle_name >> last_name >> month >> date >> year >> city >> mobile >> country;
        if (account_number_check == account_number)
        {
            cout << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country;
            return true;
        }
    }
}
//this function is used to view the information of a particular account
int view_customer_detail()
{
    string account_number_check;
    cin.ignore(256, '\n');
    cout << "Enter account number or Press m for main menu without spaces :";
    while (true)
    {
        
        getline(cin,account_number_check);
        if (account_number_check == "m")
            menu();
        if (entry_check(account_number_check) == true)
            cout << "search again or Press m for main menu without spaces :";

        else
            cout << "No Record Available enter again or Press m for main menu without spaces :";
    }
}