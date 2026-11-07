

/*remove duplicates elements from unsorted vector*/

#include <vector>
#include <algorithm>

#include <iostream>

void fun(std::vector<int>& v);

void print_vector(std::vector<int> v);


int main()
{
    std::vector<int> v = {4, 2, 4, 1, 2, 3, 1};
    print_vector(v);
    fun(v);
    print_vector(v);


}

void fun(std::vector<int>& v)
{
    std::vector<int>::iterator pmax=std::max_element(v.begin(), v.end());
    std::vector<int>::iterator pmin=std::min_element(v.begin(), v.end());

    if(pmax==v.end() || pmin==v.end())
    {
        return;
    }

    int max=*pmax;

    int min=*pmin;

    int size=max-min+1;

    int*freq=new int[size]();  // init with zero 

    for(int i=0;i<(int)v.size();i++)
    {
        if(freq[v[i]-min]==1)
        {
            v.erase(v.begin()+i);
            i--;
        }
        else
        {
            freq[v[i]-min]=1;
            
        }
    }

    delete [] freq ;
}

void print_vector(std::vector<int> v)
{
   for(int num : v)
    {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}