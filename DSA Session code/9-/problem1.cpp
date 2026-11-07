
#include <vector>
#include <numeric>
class Solution {
public:
    int findMiddleIndex(std::vector<int>& v) 
    {
        int temp=0;
        int ret=-1;
        int lvalue=0;


        if(v.size()<3)
        {
            return ret;

        }
        else
        {
         int sum = std::accumulate(v.begin(), v.end(), 0);

         for(int i=0;i<=v.size();i++)
         {
            temp=sum-v[i];

            temp/=2;
            if(temp/2==lvalue)
            {
                return i;
            }
            else{
                lvalue+=v[i];
            }
         }
        }
        return -1;
        
    }
};