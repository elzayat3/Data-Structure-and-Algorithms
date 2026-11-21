

/* 238. Product of Array Except Self */
#include <vector>


class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) 
    {
        std::vector<int> ans(nums.size());

        int right=1;

        int left=1;

        for(int i=0;i<nums.size();i++)
        {
            ans[i] = left;
            left*=nums[i];
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] *=right;
            right*=nums[i];
        }
        return ans;
        
    }
};