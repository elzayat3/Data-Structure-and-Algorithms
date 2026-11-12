


#include "Circular_Queue.h"

#include <iostream>




Circular_Queue::Circular_Queue()
{
    capacity=Default_Capacity;
    arr=new int[capacity];
    size=0;
    front=0;
    rear=0;
}

Circular_Queue::Circular_Queue(int capacity)
{
    if (capacity <= 0)
    {
        capacity=Default_Capacity;
    }
        
    this->capacity=capacity;
    arr=new int[capacity];
    size=0;
    front=0;
    rear=0;
}


Circular_Queue::~Circular_Queue()
{
    delete[] arr;
}


int Circular_Queue::Get_Capacity() const
{
    return capacity;
}


bool Circular_Queue::IsEmpty() const
{
    return size==0;
}


bool Circular_Queue::IsFull() const
{
    return size==capacity;
}


int Circular_Queue::Increment_Index(int index)
{
    return (index+1)%capacity;
}


void Circular_Queue::Enqueue(int data)
{
    if (IsFull())
    {
        std::cout<<"Queue Overflow"<<std::endl;
        return;
    }

    arr[rear]=data;
    rear=Increment_Index(rear);
    size++;
}


int Circular_Queue::dequeue()
{
    if (IsEmpty())
    {
        std::cout<<"Queue Underflow"<<std::endl;
        return INT_MIN;
    }

    int value=arr[front];
    front=Increment_Index(front);
    size--;

    return value;
}


void Circular_Queue::display()
{
    if (IsEmpty())
    {
        std::cout<<"Queue is Empty"<<std::endl;
        return;
    }

    int index=front;

    for (int i=0;i<size;i++)
    {
        std::cout<<arr[index]<<" ";
        index=Increment_Index(index);
    }

    std::cout<<std::endl;
}

int Circular_Queue::Get_Size() const
{
    return size;
}


int Circular_Queue::Get_Front() const
{
    if (IsEmpty())
    {
        std::cout<<"Queue is Empty"<<std::endl;
        return INT_MIN;
    }

    return arr[front];
}


int Circular_Queue::Get_Rear() const
{
    if (IsEmpty())
    {
        std::cout<<"Queue is Empty"<<std::endl;
        return INT_MIN;
    }

    int index=(rear-1+capacity)%capacity;
    return arr[index];
}
