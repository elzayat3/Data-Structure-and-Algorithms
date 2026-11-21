#ifndef AVL_LL_H
#define AVL_LL_H
#include <stack>

struct VNode
{
    int data;
    VNode*left;
    VNode*right;
    int height;
};

class VTree
{
private:
    VNode *root;
    int size;
    std::stack<VNode*> stk;
    int balance;
    void inorder(VNode*);
    int getheight(VNode*);
    VNode*createVNode(int data);
    VNode*insert_h(VNode*,int);
    VNode*rightRotate(VNode*);
    VNode*leftRotate(VNode*);
    VNode*predessor(VNode*);
    VNode*delete_h(VNode*,int);

public:
    VTree();
    void createVTree(int*arr,int k);
    void insertV(int);

    void deleteV(int);
    void search(int);
    void display();
    bool isEmpty();
};
#endif