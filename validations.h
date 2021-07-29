#include<iostream>
#include<algorithm>
#include<regex>
#include<ctime>
using namespace std;

bool leapYear(string year);
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
	  for (int i = 0; i < year.length(); i++)
        if (isdigit(year[i]) == false)
        return false;
	int num=stoi(year);
	 time_t t = time(NULL);
 tm* tPtr = localtime(&t);

if(num>=1905 && num<(tPtr->tm_year)+1900 && (tPtr->tm_year)+1900-num>=18)
	return true;
	else
	return false;
}
bool is_alpha(string name)
{
if(regex_match(name,regex("^[A-Za-z]+$")) && name.length()<=10)
return true;
return false;
}


bool is_city(string name)
{
if(regex_match(name,regex("^[A-Za-z]+$")) && name.length()<=20)
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
	if(regex_match(account_number,regex("[1-100000000]{4}")))
	return true;
	return false;
}
int date_check(string year,string month,string date)
{
    int num=stoi(date);
	if(month=="april"&& num==31)
	{
		return false;

	}
	if(month=="june"&& num==31)
	{
		return false;
	}
	if(month=="sep"&& num==31)
	{
		return false;
	}
	if(month=="nov"&& num==31)
	{
		return false;
	}
		if(month=="jan"&& num==31)      // January, March, May, July, August, October, and December.
	{
		return true;
	}
	if(month=="mar"&&num==31)
	{
		return true;
	}
	if(month=="may"&& num==31)
	{
		return true;
	}
	if(month=="july"&& num==31)
	{
		return true;
	}
		if(month=="aug"&& num==31)
	{
		return true;
	}	
	if(month=="oct"&& num==31)
	{
		return true;
	}	
	if(month=="dec"&& num==31)
	{
		return true;
	}
	if(leapYear(year)==true&&month=="feb"&&num==29)
	{
		return true;
	}
	if(month=="feb"&& num==29||num==30||num==31)
	{
		return false;
	}
	else
	return true;
	
}
bool leapYear(string year){ 
	   //leap year condition
	   int num=stoi(year);
   if (num % 4 == 0)
   {
      if (num % 100 == 0)
      {
         if(num % 400 == 0)
            return true;
         else
            return false;
      }
      else
         return true;
   }
   else
      return false;

   
}
   
   

