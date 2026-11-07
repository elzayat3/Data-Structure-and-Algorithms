


#include <iostream>


int countSubarrays(int*v,int n,int k)
{
    int left=0;
    int sum=0;
    int count=0;

    for (int right=0;right<n;right++)
    {
        sum+=v[right];

        while(sum>k)
        {
            sum-=v[left];
            left++;
        }

        if(sum==k)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int v[]={1, 2, 1, 2, 1};
    int n=5;
    int k=3;

    std::cout<<countSubarrays(v, n, k);

    return 0;
}