//this funciton is used to view information of all the accounts
void view_information()
{
    string file_read;
    ifstream read;
    read.open("bankdata.txt", ios::in);
    while (!read.eof())
    {
        getline(read, file_read);
        cout << file_read << endl;
    }
}
