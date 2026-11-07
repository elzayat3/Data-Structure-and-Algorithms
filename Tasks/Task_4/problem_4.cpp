#include <iostream>

double maxAverage(int*arr,int n,int k)
{
    if (k<=0 || k>n)
    {
        return 0;

    }
    long long sum=0;

    for (int i=0;i<k;i++)
    {
        sum +=arr[i];
    }

    long long maxSum=sum;

    for (int i=k;i<n;i++)
    {
        sum +=arr[i];       
        sum -=arr[i-k];   

        if (sum>maxSum)
        {
            maxSum =sum;
        }
    }

    return (double)maxSum/k;
}

int main()
{
    int arr[] ={1, 12, -5, -6, 50, 3};
    int n =sizeof(arr)/sizeof(arr[0]);
    int k =4;

    std::cout<<maxAverage(arr, n, k);

    return 0;
}
