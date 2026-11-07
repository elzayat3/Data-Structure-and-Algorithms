



#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max=0,temp=0,buy=prices[0];

        for(int num : prices)
        {
            if(num>buy)
            {
                temp=num-buy;
                if(temp>max)
                {
                    max=temp;
                }
            }
            else if(num<buy)
            {
                buy=num;
            }

        }

        return max;
    }
};