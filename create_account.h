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
