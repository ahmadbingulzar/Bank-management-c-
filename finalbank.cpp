/*This is a banking management system and create accountoldfile informatin of account ,make transactions,check details ,
remove account ,view total accounts list */
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include"validations.h"
#include<string>
#include<regex>
using namespace std;
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
    string middle_name,last_name,city,country,month, first_name, date, year ,cnic,mobile;
    string account_number;
    string account_number_check;
    bool flag=false;
    ifstream check;
    check.open("bankdata.txt",ios::in);
    cout<<"enter account number :";
    cin>>account_number_check;
    while(!check.eof())
    {
        check>>account_number>>cnic>>first_name>>middle_name>>last_name>>month>>city>>mobile>>country;    
        if(account_number_check==account_number)
        {
            flag=true;
            cout<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<city<<"\t""0"<<mobile<<"\t"<<country<<endl;
            break;
        }
    }
    if(flag==false)
        cout<<"No Record Available :"<<endl;    
}
//this function is used to deposit and withdraw money from particular account
int transactions()
{
  cout<<"Transactions done"<<endl;
  return 0;
} 
//this function is used to delete the account of a particular customer
int remove_account()
{
   cout<<"Account removed"<<endl;
   return 0;
}
//this function is used to change the address and phone number of a particular customer
char change_details()
{ 
  cout<<"changed";
  return 0;
}
//this function is used to create new account
char  create_new_account()
{
    string middle_name,last_name,city,country,month, first_name, date, year ,cnic,mobile,cnic_old;
    int account_number;
    string collect;
    bool flag=false;
    fstream bank_data;
    bank_data.open("bankdata.txt",ios::in|ios::app);
    srand(time(0));
    account_number=rand()%1000;
    cout<<"This is your account number"<<account_number<<endl;
    cout<<"Enter your cnic :";
    while(cin>>cnic ){ 


    while(!bank_data.eof()){ 
    
    bank_data>>account_number>>cnic_old>>first_name>>middle_name>>last_name>>month>>city>>mobile>>country;
    
    if(cnic==cnic_old)
    
    flag=  true;
    if(flag==true)
   cout<<"what is this behaviour poja :";
    }
    }

    
    
    
    

    

    //if (isNumber(cnic)&&cnic!=collect)
      //  break;
  // else   
    //   cout<<"Enter again :";
   // }
    
    
    cout<<"Enter birth month"<<endl
    <<"select month"<<endl
    <<"jan\nfeb\nmar\napril\nmay\njun\njuly\naugust\nsep\noct\nnov\ndec"<<endl
    <<"Enter your choice :";
    while(cin>>month){ 
    if(month=="jan"||month=="feb"||month=="mar"||month=="april"||month=="may"||month=="jun"||month=="july"||month=="july"||month=="aug"||month=="sep"||month=="oct"||month=="nov"||month=="dec")
    {
        break;
    }
    else
    cout<<"enter right choice"<<endl;
    }
    cout<<"Enter birth date"<<endl;
    while(cin>>date){
    
 if(date=="1"||date=="2"||date=="3"||date=="4"||date=="5"||date=="6"||date=="7"||date=="8"||date=="9"||date=="10"
 ||date=="11"||date=="12"||date=="13"||date=="14"||date=="15"||date=="16"||date=="17"||date=="18"||date=="19"||date=="20"
 ||date=="21"||date=="22"||date=="23"||date=="24"||date=="25"||date=="26"||date=="27"||date=="28"||date=="29"||date=="30"||date=="31")
    {
       break;
    }
    else
    cout<<"enter right choice"<<endl;
    }
    cout<<"Enter birth year :";
    while(cin>>year){
    if(is_year(year))
        break;
    else
        cout<<"Enter correct year :";
   }
    cout<<"Enter your first name :";
    cin.clear();
    cin.ignore();
    while(cin>>first_name){ 
        if(is_alpha(first_name))
        break;
        else
        cout<<"enter again :";
    }
    cout<<"Do you have middle name [y/n] :";
    char choice;
    cin>>choice;
    if(choice=='y'){ 
    cin.ignore(256, '\n');
    cout<<"Enter your middle name :";
    while(cin>>middle_name){
        if(is_alpha(middle_name))
            break;
    else
        cout<<"Enter again :";
    }
    }
    else
    cin.ignore(256, '\n');
    cout<<"Enter your last name :";
    while(cin>>last_name){
    if(is_alpha(last_name))
        break;
    else
        cout<<"Enter again :";
    }
    cin.ignore(256, '\n');
    cout<<"Enter your city name :";
    while(cin>>city){
    if(is_alpha(last_name))
        break;
    else
        cout<<"Enter again :";
    }
    cin.ignore(256, '\n');
    cout<<"Enter your mobile number :";
    while(cin>>mobile){
    if(is_phone(mobile))
        break;
    else
        cout<<"Enter again :";
    }
    cin.ignore(256, '\n');
    cout<<"Enter country name :";
    while(cin>>country){
    if(is_alpha(country))
        break;
    else  
        cout<<"Enter again :";
    }
    cout<<"Account created sucessfully"<<endl;
    if(choice=='y')
    {
     bank_data<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<middle_name<<"\t"<<last_name<<"\t"<<month<<"\t"<<city<<"\t""0"<<mobile<<"\t"<<country<<endl;
    }
    else
    bank_data<<account_number<<"\t"<<cnic<<"\t"<<first_name<<"\t"<<"NULL"<<"\t"<<last_name<<"\t"<<month<<"\t"<<city<<"\t""0"<<mobile<<"\t"<<country<<endl;
    return 0;
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
    <<"4:Depost or withdraw"<<endl
    <<"5:View detail of a particular customer"<<endl
    <<"6:Delete Account"<<endl
    <<"7:Exit"<<endl
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
        change_details();
    }
    else if(choice=="4")
    {
         validity_count=0;
        transactions();
    }
    else if(choice=="5")
    {
         validity_count=0;
        view_customer_detail();
    }
    else if(choice=="6")
    {
        validity_count=0;
        remove_account();
    }
    else if(choice=="7")
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