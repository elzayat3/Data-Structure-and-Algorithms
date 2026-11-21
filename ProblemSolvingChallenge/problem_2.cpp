

/* 11. Container With Most Water */

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& h) 
    {

        int left = 0;
        int right = h.size() - 1;

        int area=0;
        int max_area=0;
        int width=0;
        int  height=0;

        while(left<right)
        {
            width=right-left;

            height=std::min(h[left],h[right]);

            area=width*height;

            if(area>max_area)
            {
                max_area=area;
            }

            if(h[left]<h[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
        
    }
};