/*This is a banking management system and create accountoldfile informatin of account ,make transactions,check details ,
remove account ,view total accounts list of users */
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include"validations.h"
#include<string>
#include<regex>
#include<algorithm>
using namespace std;
int menu();

int account_number_check(int account_number_generated)
{
       string middle_name,last_name,city,country,month, first_name, date, year ,mobile,cnic_old;
    int account_number;
    fstream bank_data;
    bank_data.open("bankdata.txt",ios::in);
    while(!bank_data.eof()){ 
 bank_data>>account_number>>cnic_old>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;
     if(account_number==account_number_generated)
    {
        return true;
    }
    else false;
}
}
int cnic_test(string cnic)
{
    string middle_name,last_name,city,country,month, first_name, date, year ,mobile,cnic_old;
    int account_number;
    fstream bank_data;
    bank_data.open("bankdata.txt",ios::in);
    while(!bank_data.eof()){ 
 bank_data>>account_number>>cnic_old>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;
     if(cnic==cnic_old)
    {
        return true;
    }
    else false;
}
}
//this funciton is used to view information of all the accounts
void view_information()
{
    string file_read;
    ifstream read;
    read.open("bankdata.txt",ios::in);
    while(!read.eof())
    {
        getline(read,file_read);
        cout<<file_read<<endl;
    }  
}
//this funtion is used to exit all the operations 
int exit()
{
    cout<<"Thank you for using service"<<endl;
    return 0;
}
//this function is used to view the information of a particular account
int view_customer_detail()
{
    string middle_name,last_name,city,country,month, first_name, date, year ,cnic,mobile, account_number, account_number_check;
    bool flag=false;
    ifstream check;
    check.open("bankdata.txt",ios::in);
    cout<<"enter account number :";
    cin>>account_number_check;
    while(!check.eof())
    {
        check>>account_number>>cnic>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;    
        if(account_number_check==account_number)
        {
            flag=true;
            cout<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country;
            break;
        }
    }
    if(flag==false)
        cout<<"No Record Available :"<<endl;    
        return 0;
}


//this is the main function of the program 
int main()
{
    menu(); //Don't forget to call me 
}
