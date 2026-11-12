#ifndef STACK_ARR
#define STACK_ARR


class Stack_Arr
{
private:
    int *arr;
    int capacity;
    int sp;

public:
    Stack_Arr();
    Stack_Arr(int capacity);
    ~Stack_Arr();
    bool IsEmpty();
    bool IsFull();
    int pop();
    int peek();
    void push(int data);
    void display();
};


#endif /* STACK_ARR */
