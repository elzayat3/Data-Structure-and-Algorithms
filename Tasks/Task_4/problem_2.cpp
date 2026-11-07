

#include <iostream>
#include <vector>


int shortestSubarray(std::vector<int>& v, int k)
{
    int left = 0;
    int sum = 0;
    int minLength=v.size()+1;

    for (int right=0;right<v.size();right++)
    {
        sum+=v[right];

        while(sum>=k)
        {
            int length=right-left+1;

            if (length<minLength)
            {
                minLength=length;
            }

            sum-=v[left];
            left++;
        }
    }

    if (minLength==v.size()+1)
    {
        return -1;
    }

    return minLength;
}

int main()
{
    std::vector<int> v={2, 3, 1, 2, 4, 3};
    int k=7;

    std::cout<<shortestSubarray(v, k);

    return 0;
}