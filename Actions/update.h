
//this function is used to change the address and phone number of a particular customer
int update_data()
{
    string account_to_update, account_number, cnic, first_name, middle_name, last_name, month, date, year, city, mobile, country, choice;
    string months_array[12] = {"jan", "feb", "mar", "april", "may", "jun", "july", "aug", "sep", "oct", "nov", "dec"};
    int i;
    bool flag = true;
    cin.ignore(256, '\n');
    cout << "Enter account number to update or Press m for main menu :";
    while (getline(cin, account_to_update))
    {
        if (account_to_update == "m")
            menu();
        if (is_valid_entry(account_to_update) == false)
        {
            flag = false;
        }

        ifstream bank_data;
        bank_data.open("bankdata.txt", ios::in);
        bool flag = true;
        fstream temp;
        temp.open("temp.txt", ios::app);
        bank_data >> account_number >> cnic >> first_name >> middle_name >> last_name >> month >> date >> year >> city >> mobile >> country;
        while (!bank_data.eof())
        {
            if (account_to_update == account_number)
            {
                cout << "1:To change cnic" << endl
                     << "2:TO change First name" << endl
                     << "3:To change middle name" << endl
                     << "4:To change last name" << endl
                     << "5:To change birth month" << endl
                     << "6:To change birth date" << endl
                     << "7:To change birth year" << endl
                     << "8:To change city name" << endl
                     << "9:To change mobile number" << endl
                     << "Enter your choice or Press m for the main menu :";
                string choice;
                while (cin >> choice)
                {
                    if (choice == "m")
                        menu();
                    if (choice == "1")
                    {
                        cout << "Enter cnic to change without dashes and spaces :";
                        cin.ignore(256, '\n');
                        while (getline(cin, cnic))
                        {
                            if (cnic == "m")
                                menu();
                            if (isNumber(cnic) == false)
                                cout << "Enter right choice or Press m for main menu" << endl;
                            else if (cnic_test(cnic) == true)
                                cout << "cnic already taken enter again or Press m for main menu " << endl;
                            else
                                break;
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "2")
                    {
                        cout << "Enter your first name to change without spaces (10 character allowed only) or Press m for main menu:";
                        cin.ignore(256, '\n');
                        while (getline(cin, first_name))
                        {
                            if (first_name == "m")
                                menu();
                            if (is_alpha(first_name))
                                break;
                            else
                                cout << "Enter right choice again or press m for the main menu :";
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "3")
                    {
                        cout << "Enter your middle name to change without spaces (10 character allowed only) or Press m for main menu:";
                        cin.ignore(256, '\n');
                        while (getline(cin, middle_name))
                        {
                            if (middle_name == "m")
                                menu();
                            if (is_alpha(middle_name))
                                break;
                            else
                                cout << "Enter right choice again or Press m for the main menu:";
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "4")
                    {
                        cout << "Enter your Last name to change without spaces (10 character allowed only) or Press m for main menu:";
                        cin.ignore(256, '\n');
                        while (getline(cin, last_name))
                        {
                            if (last_name == "m")
                                menu();
                            if (is_alpha(last_name))
                                break;
                        }

                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "5")
                    {
                        cout << "Enter Date of birth month to change or Press m for main menu" << endl
                             << "select month" << endl
                             << "jan\nfeb\nmar\napril\nmay\njune\njuly\naugust\nsep\noct\nnov\ndec" << endl
                             << "Enter your choice :";
                        bool flag = false;
                        int i;
                        cin.ignore(256, '\n');
                        while (flag == false)
                        {
                            getline(cin, month);
                            if (month == "m")
                                menu();
                            for (i = 0; i < 12; i++)
                                if (months_array[i] == month)
                                {
                                    flag = true;
                                }
                            if (flag == false)
                            {
                                cout << "Enter right choice again or Press m for the main menu" << endl;
                            }
                        }

                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "6")
                    {
                        cout << "Enter Date of birth to change or Press m for main menu" << endl;
                        bool check = false;
                        cin.ignore(256, '\n');
                        while (check == false)
                        {
                            getline(cin, date);
                            if (date == "m")
                                menu();
                            int num = stoi(date);
                            for (i = 1; i <= 31; i++)
                                if (i == num)

                                    if (date_check(year, month, date) == false)
                                    {
                                        check = false;
                                    }

                                    else
                                        check = true;
                            if (check == false)
                            {
                                cout << "Enter right choice again or Press m for the main menu" << endl;
                            }
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "7")
                    {
                        cout << "Enter Date of birth year to change or Press m for main menu :";
                        cin.ignore(256, '\n');
                        while (getline(cin, year))
                        {
                            if (year == "m")
                                menu();
                            else if (is_year(year))
                                break;
                            else
                                cout << "Enter correct year again or Press m for the main menu :";
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "8")
                    {
                        cout << "Enter your City name to change without spaces (20 character allowed only)or Press m for main menu :";
                        cin.ignore(256, '\n');
                        while (getline(cin, city))
                        {
                            if (city == "m")
                                menu();
                            if (is_city(city))
                                break;
                            else
                                cout << "Enter right choice again or Press m for the main menu:";
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }
                    else if (choice == "9")
                    {
                        cout << "Enter your mobile number to change or Press m for main menu :";
                        cin.ignore(256, '\n');
                        while (getline(cin, mobile))
                        {
                            if (mobile == "m")
                                menu();
                            if (is_phone(mobile))
                                break;
                            else
                                cout << "Enter right choice again or Press m for the main menu :";
                        }
                        temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
                        break;
                    }

                    else
                        cout << "Enter right choice again:";
                }
            }
            else if (account_to_update != account_number)
            {
                flag = false;

                temp << "\t" << account_number << "\t" << cnic << "\t" << first_name << "\t" << middle_name << "\t" << last_name << "\t" << month << "\t" << date << "\t" << year << "\t" << city << "\t" << mobile << "\t" << country << endl;
            }
            bank_data >> account_number >> cnic >> first_name >> middle_name >> last_name >> month >> date >> year >> city >> mobile >> country;
        }
        if (flag == false)
            cout << "Enter account number to change or Press m for the main menu:";
        bank_data.close();
        temp.close();
        remove("bankdata.txt");
        rename("temp.txt", "bankdata.txt");
    }
}
