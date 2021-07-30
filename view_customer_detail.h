//this function is used to view the information of a particular account
int view_customer_detail()
{
    string middle_name, last_name, city, country, month, first_name, date, year, cnic, mobile, account_number, account_number_check;
    bool flag = false;
    ifstream check;
    check.open("bankdata.txt", ios::in);
    cout << "enter account number :";
    cin >> account_number_check;
    while (!check.eof())
    {
        check >> account_number >> cnic >> first_name >> middle_name >> last_name >> month >> date >> year >> city >> mobile >> country;
        if (account_number_check == account_number)
        {
            flag = true;
            cout << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country;
            break;
        }
    }
    if (flag == false)
        cout << "No Record Available :" << endl;
    return 0;
}