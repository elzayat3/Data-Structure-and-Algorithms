

#include "Double_Ended_Queue.h"

#include <iostream>



Double_Ended_Queue::Double_Ended_Queue()
{
    capacity=Default_Capacity_2;
    arr=new int[capacity];
    size=0;
    front=0;
    rear=0;
}

Double_Ended_Queue::Double_Ended_Queue(int capacity)
{
    if(capacity<=0)
    {
        capacity=Default_Capacity_2;
    }
        
    this->capacity=capacity;
    arr=new int[capacity];
    size=0;
    front=0;
    rear=0;
}

Double_Ended_Queue::~Double_Ended_Queue()
{
    delete[] arr;
}


int Double_Ended_Queue::Get_Capacity() const
{
    return capacity;
}


bool Double_Ended_Queue::IsEmpty() const
{
    return size==0;
}

bool Double_Ended_Queue::IsFull() const
{
    return size==capacity;
}


int Double_Ended_Queue::Increment_Index(int index)
{
    return (index+1)%capacity;
}


int Double_Ended_Queue::Decrement_Index(int index)
{
    return (index-1+capacity)%capacity;
}

void Double_Ended_Queue::Enqueue_Rear(int data)
{
    if(IsFull())
    {
        std::cout<<"Queue Overflow"<<std::endl;
        return;
    }

    arr[rear]=data;
    rear=Increment_Index(rear);
    size++;
}

void Double_Ended_Queue::Enqueue_Front(int data)
{
    if(IsFull())
    {
        std::cout<<"Queue Overflow"<<std::endl;
        return;
    }

    front=Decrement_Index(front);
    arr[front]=data;
    size++;
}


int Double_Ended_Queue::Dequeue_Front()
{
    if(IsEmpty())
    {
        std::cout<<"Queue Underflow"<<std::endl;
        return INT_MIN;
    }

    int value=arr[front];
    front = Increment_Index(front);
    size--;

    return value;
}


int Double_Ended_Queue::Dequeue_Rear()
{
    if (IsEmpty())
    {
        std::cout<<"Queue Underflow"<<std::endl;
        return INT_MIN;
    }

    rear=Decrement_Index(rear);
    int value=arr[rear];
    size--;

    return value;
}


void Double_Ended_Queue::display()
{
    if(IsEmpty())
    {
        std::cout<<"Queue is Empty"<<std::endl;
        return;
    }

    int index=front;

    for(int i=0;i<size;i++)
    {
        std::cout<<arr[index]<<" ";
        index=Increment_Index(index);
    }

    std::cout<<std::endl;
}


int Double_Ended_Queue::Get_Size() const
{
    return size;
}

int Double_Ended_Queue::Get_Front() const
{
    if(IsEmpty())
    {
        std::cout<<"Queue is Empty"<<std::endl;
        return INT_MIN;
    }

    return arr[front];
}

// Get Rear
int Double_Ended_Queue::Get_Rear() const
{
    if(IsEmpty())
    {
        std::cout<<"Queue is Empty"<<std::endl;
        return INT_MIN;
    }

    int index=(rear-1+capacity)%capacity;
    return arr[index];
}
