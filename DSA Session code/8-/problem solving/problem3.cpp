#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int low=0,high=s.size()-1;

        while(low<high)
        {

            if (isalnum(s[low])==0) 
            {
                low++;
                continue;
            }
            if (isalnum(s[high])==0) 
            {
                high--;
                continue;
            }

            if (tolower(s[low])!=tolower(s[high]))
            {
                return false;

            }
            low++;
            high--;
                
        }

        return true; 
    }
};