#ifndef HTREE_H
#define HTREE_H


class MaxHeap
{
private:
    int heap[100];
    int size;

public:
    MaxHeap();

    void insert(int value);
    void deleteRoot();
    void display();
};

#endif /* HTREE */
