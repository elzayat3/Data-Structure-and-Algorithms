#include <iostream>
#include <vector>

void findPairs(std::vector<int> arr,int k) 
{
    for (int i=0;i<arr.size();i++) 
    {
        for (int j=i+1;j<arr.size();j++) 
        {
            if (arr[i]+arr[j]==k) 
            {
                std::cout<< arr[i] <<" + "<<arr[j] <<" = "<<k<<std::endl;
            }
        }
    }
}