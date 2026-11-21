
#include <iostream>
#include <algorithm>
#include "Htree.h"

using namespace std;

MaxHeap::MaxHeap()
{
    size=0;
}

void MaxHeap::insert(int value)
{
    if (size==100)
    {
        cout<<"Heap is full"<<endl;
        return;
    }

    int i=size;

    heap[i]=value;
    size++;

    while(i>0)
    {
        int parent=(i-1)/2;

        if(heap[parent]>=heap[i])
        {
            break;
        }

        swap(heap[parent],heap[i]);

        i=parent;
    }
}

void MaxHeap::deleteRoot()
{
    if(size==0)
    {
        cout<<"Heap is empty"<<endl;
        return;
    }

    heap[0]=heap[size-1];
    size--;

    int i=0;

    while(true)
    {
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;

        if(left<size && heap[left]>heap[largest])
        {
            largest=left;
        }

        if(right<size && heap[right]>heap[largest])
        {
            largest=right;
        }

        if(largest==i)
        {
            break;
        }

        swap(heap[i],heap[largest]);

        i=largest;
    }
}

void MaxHeap::display()
{
    for(int i=0;i<size;i++)
    {
        cout<<heap[i]<<" ";
    }

    cout<<endl;
}
