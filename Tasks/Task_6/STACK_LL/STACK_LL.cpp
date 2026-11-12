
#include "Stack_LL.h"

#include <iostream>




Node::Node()
{
    data=0;
    next=nullptr;
}


Node::Node(int data)
{
    this->data=data;
    next=nullptr;
}


Node::Node(int data,Node*next)
{
    this->data=data;
    this->next=next;
}


void Node::Set_data(int data)
{
    this->data=data;
}


void Node::Set_next(Node*next)
{
    this->next=next;
}


int Node::Get_data()
{
    return data;
}


Node *Node::Get_next()
{
    return next;
}


Stack_LL::Stack_LL()
{
    head=nullptr;
}


Stack_LL::Stack_LL(int data)
{
    head=new Node(data);
}


Stack_LL::~Stack_LL()
{
    while(!IsEmpty())
    {
        pop();
    }
}


bool Stack_LL::IsEmpty()
{
    return head==nullptr;
}

void Stack_LL::push(int data)
{
    Node*newNode=new Node(data, head);
    head=newNode;
}


int Stack_LL::pop()
{
    if (IsEmpty())
    {
        std::cout<<"Stack Underflow"<<std::endl;
        return INT_MIN;
    }

    Node*temp=head;
    int value=temp->Get_data();

    head=head->Get_next();
    delete temp;

    return value;
}

int Stack_LL::peek()
{
    if (IsEmpty())
    {
        std::cout<<"Stack is Empty"<<std::endl;
        return INT_MIN;
    }

    return head->Get_data();
}


void Stack_LL::display()
{
    if (IsEmpty())
    {
        std::cout<<"Stack is Empty"<<std::endl;
        return;
    }

    Node*temp=head;

    while(temp!=nullptr)
    {
        std::cout<<temp->Get_data()<<" ";
        temp=temp->Get_next();
    }

    std::cout<<std::endl;
}
