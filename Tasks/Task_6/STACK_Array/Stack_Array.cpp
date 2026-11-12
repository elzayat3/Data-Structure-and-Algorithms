

#include <iostream>

#include "Stack_Array.h"


Stack_Arr::Stack_Arr()
{
    capacity=100;
    arr=new int[capacity];
    sp=0;
}


Stack_Arr::Stack_Arr(int capacity)
{
    if(capacity<=0)
    {
        capacity=100;
    }
    this->capacity=capacity;
    arr=new int[capacity];
    sp=0;
}

Stack_Arr::~Stack_Arr()
{
    delete[] arr;
}


bool Stack_Arr::IsEmpty()
{
    return sp==0;
}


bool Stack_Arr::IsFull()
{
    return sp==capacity;
}


void Stack_Arr::push(int data)
{
    if (IsFull())
    {
        std::cout<<"Stack Overflow"<<std::endl;
        return;
    }

    arr[sp++]=data;
}


int Stack_Arr::pop()
{
    if (IsEmpty())
    {
        std::cout<<"Stack Underflow"<<std::endl;
        return INT_MIN;
    }

    return arr[--sp];
}

int Stack_Arr::peek()
{
    if (IsEmpty())
    {
        std::cout<<"Stack is Empty"<<std::endl;
        return INT_MIN;
    }

    return arr[sp-1];
}


void Stack_Arr::display()
{
    if (IsEmpty())
    {
        std::cout<<"Stack is Empty"<< std::endl;
        return;
    }

    for (int i=sp-1;i>=0;i--)
    {
        std::cout<<arr[i]<<" ";
    }

    std::cout<<std::endl;
}
