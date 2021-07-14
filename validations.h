#include<iostream>
#include<algorithm>
#include<regex>
#include<ctime>

using namespace std;
bool isNumber(string cnic)
{
	if(cnic.length()==13){ 
    for (int i = 0; i < cnic.length(); i++)
        if (isdigit(cnic[i]) == false)
        return false;
        return true;
	}
	else
	return false;
}
bool is_year(string year)
{
	int num=stoi(year);
	 time_t t = time(NULL);
 tm* tPtr = localtime(&t);

if(num>=1000&&num<=(tPtr->tm_year)+1900)
	return true;
	else
	return false;
}
bool is_alpha(string first_name)
{
if(regex_match(first_name,regex("^[A-Za-z]+$")))
return true;
return false;
	
}
bool is_phone(string phone)
{
	if(regex_match(phone,regex("(0|91)?[3][0-9]{9}")))
	return true;
	return false;

}
bool is_valid_entry(string account_number)
{
	if(regex_match(account_number,regex("[1-1000]{4}")))
	return true;
	return false;
}

