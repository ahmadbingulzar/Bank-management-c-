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
//this function is used to delete the account of a particular customer
int remove_account()
{
    string account_to_remove,account_number,cnic,first_name,middle_name,last_name,month,date,year,city,mobile,country;

    cout<<"Enter account number to remove :";
    cin>>account_to_remove;
    if(is_valid_entry(account_to_remove))
    {
        cout<<"NOt valid Entry"<<endl;
        return 0;
    }
    ifstream bank_data;
    bank_data.open("bankdata.txt",ios::in);
    bool flag=true;
     fstream temp;
     temp.open("temp.txt",ios::app);
     bank_data>>account_number>>cnic>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;
         
    while(!bank_data.eof())
    {
        cout<<account_number<<endl;
        if(account_to_remove==account_number)
           { 
               cout<<"Account is deleted"<<endl;
           }
        else
       {  
           temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;
       }
     bank_data>>account_number>>cnic>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;       
    }
    if(account_to_remove!=account_number)
    cout<<"No match"<<endl;
    bank_data.close();
    temp.close();
    remove("bankdata.txt");
    rename("temp.txt","bankdata.txt");
}
//this function is used to change the address and phone number of a particular customer
int update_data()
{
 
  string account_to_update,account_number,cnic,first_name,middle_name,last_name,month,date,year,city,mobile,country;
  string array[12]={"jan","feb","mar","april","may","jun","july","aug","sep","oct","nov","dec"};
  string date_array[31]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
  int i;

    cout<<"Enter account number to update :";
    cin>>account_to_update;
    if(is_valid_entry(account_to_update))
    {
        cout<<"NOt valid Entry"<<endl;
        return 0;
    }
    ifstream bank_data;
    bank_data.open("bankdata.txt",ios::in);
    bool flag=true;
     fstream temp;
     temp.open("temp.txt",ios::app);
 bank_data>>account_number>>cnic>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;
    while(!bank_data.eof())
    {
        if(account_to_update==account_number)
           { 
              cout<<"1:To change cnic"<<endl
              <<"2:TO change First name"<<endl
              <<"3:To change middle name"<<endl
              <<"4:To change last name"<<endl
              <<"5:To change birth month"<<endl
              <<"6:To change birth date"<<endl
              <<"7:To change birth year"<<endl
              <<"8:To change city name"<<endl
              <<"9:To change mobile number"<<endl
              <<"10:TO change country name"<<endl
              <<"Enter your choice :";
              string choice;
              cin>>choice;
              
              
              if(choice=="1")
              {
                cout<<"Enter cnic to change :";
                cin>>cnic;
                if(!isNumber(cnic))
              {
                cout<<"Not valid cnic "<<endl;
                return 0;
              }
                temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;
             }
             else if(choice=="2")
             {
                cout<<"Enter first name to change :";
                cin>>first_name;
                if(!is_alpha(first_name))
               { 
                    cout<<"wrong choice only alphabets allowed"<<endl;
                return 0;
               }
                temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;
             }
            else if(choice=="3")
            {
                cout<<"Enter middle name to change :";
                cin>>middle_name;
                if(!is_alpha(middle_name))
                {
                    cout<<"wrong choice only alphabets allowed"<<endl;
                    return 0;
                }
                temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;

            }
            else if(choice=="4")
            {
                cout<<"Enter last name to change :";
                cin>>last_name;
                if(!is_alpha(last_name))
                {
                    cout<<"wrong choice only alphabets allowed"<<endl;
                    return 0;
                }
            temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;
            }
            else if(choice=="5")
            {
                bool check=false;
                cout<<"Enter birth month to change :";
                while(check==false){ 
                cin>>month;
                for( i=0;i<12;i++)
                
                    if(month==array[i]){ 
                    check=true;
                    }
                    if(check==false){ 
                    cout<<"Enter right choice :";
                    }
                }
                
        temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;
        }
    else if(choice=="6"){
        bool date_check=false;
        cout<<"Enter birth date to change :";
        while(date_check==false){ 
        cin>>date;
        for(i=0;i<31;i++)
        if(date_array[i]==date){ 
        date_check=true;
        }
        if(date_check==false){
            cout<<"Enter right choice :";
        }
        }
        temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;

    }
    else if(choice=="7"){
    cout<<"Enter birth year to change :";
    while(cin>>year){
    if(is_year(year))
        break;
    else
        cout<<"Enter correct year :";
   }
    temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;

    }
    else if(choice=="8"){
    cout<<"Enter your city name to change:";
    while(cin>>city){
    if(is_alpha(city))
        break;
    else
        cout<<"Enter again :";
    }
        temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;

    }
    else if(choice=="9"){
    cout<<"Enter your mobile number :";
    while(cin>>mobile){
    if(is_phone(mobile))
        break;
    else
        cout<<"Enter again :";
    }
        temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;

    }
    else if(choice=="10"){
    cout<<"Enter country name to change :";
    while(cin>>country){
    if(is_alpha(country))
        break;
    else  
        cout<<"Enter again :";
    }
    temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;

    }
           }
           else if(account_to_update!=account_number)
          { 
            flag=false;
        
            temp<<"\t"<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<country<<endl;
       }
    bank_data>>account_number>>cnic>>first_name>>middle_name>>last_name>>month>>date>>year>>city>>mobile>>country;
       
    }
    if(flag==false)
    cout<<"No match"<<endl;
    bank_data.close();
    temp.close();
    remove("bankdata.txt");
    rename("temp.txt","bankdata.txt");
}
//this function is used to create new account
void  create_new_account()
{
    string middle_name,last_name,city,country,month, first_name, date, year ,cnic,mobile,cnic_old;
    int account_number;
    string months_array[12]={"jan","feb","march","april","may","june","july","aug","sep","oct","nov","dec"};
    string choice;
    string collect;
    fstream bank_data;
    bank_data.open("bankdata.txt",ios::in|ios::app|ios::out);
      srand(time(0));
    account_number=rand()%10000;
    while(account_number_check(account_number)==true){ 
    srand(time(0));
    account_number=rand()%10000;
    account_number_check(account_number);
    }
    cout<<"Press m for main menu :";
    cout<<"Enter your cnic without dashes and spaces :";
    cin.ignore(256,'\n');
    while(getline(cin,cnic)){ 
       if(cnic=="m")
        menu();
    if(isNumber(cnic)==false)
         cout<<"Enter right choice or Press m for main menu"<<endl;
    else if(cnic_test(cnic)==true)
        cout<<"cnic already taken enter again or Press m for main menu "<<endl;
    else
        break; 
}
 cout<<"Enter Date of birth year or Press m for main menu :";
    while(getline(cin,year)){
        if(year=="m")
            menu();
   else if(is_year(year))
        break;
    else
        cout<<"Enter correct year again or Press m for the main menu :";
   }
    cout<<"Enter Date of birth month or Press m for main menu"<<endl
    <<"select month"<<endl
    <<"jan\nfeb\nmar\napril\nmay\njune\njuly\naugust\nsep\noct\nnov\ndec"<<endl
    <<"Enter your choice :";
    bool flag=false;
    int i;
    while(flag==false){ 
        getline(cin,month);
        if(month=="m")
            menu();
    for (i=0;i<12;i++)
    if(months_array[i]==month)
    {
        flag=true;
    }
    if(flag==false)
   {  
    cout<<"Enter right choice again or Press m for the main menu"<<endl;
   }
   }
    cout<<"Enter Date of birth or Press m for main menu"<<endl;
    bool check=false;
    while(check==false){
    getline(cin,date);
    if(date=="m")
        menu();
        int num=stoi(date);
    for(i=1;i<=31;i++)
    if(i==num)
     
        if(date_check(year,month,date)==false){
            check=false;
        }
    
        else
      check=true;
    if(check==false){  
    cout<<"Enter right choice again or Press m for the main menu"<<endl;
    }
    }
    cout<<"Enter your first name without spaces (10 character allowed only) or Press m for main menu:";
    while(getline(cin,first_name)){ 
        if(first_name=="m")
            menu();
        if(is_alpha(first_name))
        break;
        else
        cout<<"Enter right choice again or press m for the main menu :";
    }
    cout<<"Do you have middle name [y/n] Press m for main menu :";
    while(getline(cin,choice)){ 
    if(choice=="m")
        menu();
    if(choice=="y"){ 
    cout<<"Enter your middle name  without spaces (10 character allowed only) or Press m for main menu:";    
    while(getline(cin,middle_name)){
        if(middle_name=="m")
            menu();
        if(is_alpha(middle_name))
            break;
    else
        cout<<"Enter right choice again or Press m for the main menu:";
    }
    cout<<"Enter your Last name without spaces (10 character allowed only) or Press m for main menu:";
    while(getline(cin,last_name)){
        if(last_name=="m")
            menu();
    if(is_alpha(last_name))
        break;
    else
        cout<<"Enter right choice again [y/n] or Press m for the main menu :";
    }
    break;
}
    else if(choice=="n"){ 
    cout<<"Enter your Last name without spaces (10 character allowed only) or Press m for main menu :";
    while(getline(cin,last_name)){
    if(last_name=="m")
        menu();
    if(is_alpha(last_name))
        break;
    else
        cout<<"Enter right choice again or Press m for the main menu:";
    }
    break;
}
    else
    cout<<"Enter right choice again or Press m for the main menu:";
}
    cout<<"Enter your City name without spaces (20 character allowed only)or Press m for main menu :";
    while(getline(cin,city)){
        if(city=="m")
            menu();
    if(is_city(city))
        break;
    else
        cout<<"Enter right choice again or Press m for the main menu:";
    }
    cout<<"Enter your mobile number or Press m for main menu :";
    while(getline(cin,mobile)){
        if(mobile=="m")
            menu();
    if(is_phone(mobile))
        break;
    else
        cout<<"Enter right choice again or Press m for the main menu :";
    }
    
  /* cout<<"Enter country name or Press m for main menu :";
    while(getline(cin,country)){
        if(country=="m")
            menu();
    if(is_alpha(country))
        break;
    else  
        cout<<"Enter again without spaces or Press m for the main menu :";
    }*/
    if(choice=="y")
    {
    bank_data<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<"Pakistan"<<endl;
    cout<<"This is your account number :"<<account_number<<endl;
    cout<<"Account created sucessfully"<<endl;
    }
    else
    {
    bank_data<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<"NULL"<<"\t"<<last_name<<"\t"<<month<<"\t"<<date<<"\t"<<year<<"\t"<<city<<"\t"<<mobile<<"\t"<<"Pakistan"<<endl;
    cout<<"This is your account number :"<<account_number<<endl;
    cout<<"Account created sucessfully"<<endl;
    }  
}
/*this is the menu function it displays the menu for the bank management system to user to select
any option*/
int menu()
{ 
   int validity_count=0;
    string choice;
    int flag=0;
    while( true){ 
        cout<<"CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM "<<endl
        <<"||||||| WELCOME TO THE MAIN MENU|||||||"<<endl
        <<"1:Create new account"<<endl
        <<"2:view information of all the accounts"<<endl
        <<"3:Update Address and Phone number"<<endl
        <<"4:View detail of a particular customer"<<endl
        <<"5:Delete Account"<<endl
        <<"6:Exit"<<endl
        <<endl
        <<endl
        <<"Enter your choice: "<<endl;
        cin>>choice;
        if(choice=="1")
        {
            validity_count=0;
            create_new_account();
        }
        else if(choice=="2")
        {
            validity_count=0;
            view_information();
        }
        else if(choice=="3")
        {
            validity_count=0;
            update_data();
        }
        else if(choice=="4")
        {
            validity_count=0;
            view_customer_detail();
        }
        else if(choice=="5")
        {
            validity_count=0;
            remove_account();
        }
        else if(choice=="6")
        {
            exit();
            return 0;
        }
        else if(choice.length()!=1)
        { 
            validity_count++;
            cout<<"wrong choice"<<endl;
        }
        if(validity_count==3)
        { 
            cout<<"Get out "<<endl;
            break;
        //return 0;
        }
    }
}
//this is the main function of the program 
int main()
{
    menu(); //Don't forget to call me 
}
