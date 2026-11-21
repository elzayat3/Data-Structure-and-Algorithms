

/*41. First Missing Positive*/

#include <vector>


class Solution {
public:
    int firstMissingPositive(std::vector<int>& n) 
    {

        for(int i=0;i<n.size();i++) 
        {

            while(n[i]>0&&n[i]<=n.size()&&n[i]!=n[n[i]-1]) 
            {

                std::swap(n[i], n[n[i]-1]);
            }
        }

        for (int i=0;i<n.size();i++) 
        {

            if(n[i]!=i+1) 
            {
                return i+1;
            }
        }

        return n.size()+1;
    }
};