
#include <string>

using namespace std;

class Solution {
public:
    bool   is_leap_year(int y)
    {
      if( (y%400==0) || ((y%4==0) &&(y%100!=0)))
      {
        return true;
      }
      else
      {
        return false;
      }

    }
    int daysBetweenDates(string date1, string date2) 
    {

      int days=0,days1=0,days2=0,flag=0;
      unsigned int y1 = stoul(date1.substr(0, 4));
      unsigned int m1 = stoul(date1.substr(5, 2));
      unsigned int d1 = stoul(date1.substr(8, 2));
      unsigned int y2 = stoul(date2.substr(0, 4));
      unsigned int m2 = stoul(date2.substr(5, 2));
      unsigned int d2 = stoul(date2.substr(8, 2));
      
      int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      for(int i=1971;i<y1;i++)
      {
        if(is_leap_year(i)==true)
        {
          days1 += 366;
        }
        else
        {
          days1 += 365;
          
        }
      }
      for(int i=1971;i<y2;i++)
      {
        if(is_leap_year(i)==true)
        {
          days2 += 366;
        }
        else
        {
          days2 += 365;
          
        }
      }

      for(int i=0;i<m2-1;i++)
      {
        days2 +=months[i];
      }

      for(int i=0;i<m1-1;i++)
      {
        days1 +=months[i];
      }
      if (m1 > 2 && is_leap_year(y1))
      {
        days1++;

      }
      if (m2 > 2 && is_leap_year(y2))
      {
        days2++;

      }
            

      days1=days1+d1;

      days2=days2+d2;

      days=days2-days1;

      if(days<0)
      {
        days=-days;
      }

      return days;  
    }
};