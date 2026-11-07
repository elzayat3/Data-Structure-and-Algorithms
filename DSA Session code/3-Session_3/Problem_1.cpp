
#include <iostream>
/*find single missing element in sorted array */


// diff=arr[0]-0 ---> diff=arr[i]-i ---> arr[i]=diff+i

int find_missing(int*arr,int size)
{
    int diff=arr[0]-0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]-i != diff)
        {
            return diff+i;
        }
    }

    return -1;
}




int find_missing2(int*arr,int size)
{
    int diff=0;
    int diff1=0;
    int diff2=0;

    if(size>=3)
    {
        diff1=arr[1]-arr[0];
        diff2=arr[2]-arr[1];
        diff=(diff1<diff2)?diff1:diff2;

        for(int i=0;i<size-1;i++)
        {
            if(arr[i+1]-arr[i] != diff)
            {
                return arr[i]+diff;
            }
        }
    }
    return -1;
}



/*


إWe won’t move to the right, because we know that the missing number—15—is greater than 12; 
however, within the algorithm itself, we don’t actually know what the missing number is yet.

Since arr[mid] is equal to the expected value,
 the pattern remains intact up to the mid position; therefore, 
 the missing element must be located after it.


 arr[i]=arr[0]+(i*diff)
*/


int find_missingbin(int*arr,int size)
{
    int low=0;
    int high=size-1;
    int mid=0;
    int diff=0;
    int diff1=0;
    int diff2=0;
    if(size>=3)
    {
        diff1=arr[1]-arr[0];
        diff2=arr[2]-arr[1];
        diff=(diff1<diff2)?diff1:diff2;
        while(low<=high)
        {
            mid=(high+low)/2;

            int exp=arr[0]+(mid*diff);

            if(exp==arr[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        if(low<size)
        {
            return arr[0]+(low*diff);
        }
    }
    return -1;
}
int main()
{

    int arr[10]={5,7,9,11,13,15,17,21,23,25};
    int k=find_missingbin(arr, 10);
    std::cout<<k;
}


