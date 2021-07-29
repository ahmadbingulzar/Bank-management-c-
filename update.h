
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
