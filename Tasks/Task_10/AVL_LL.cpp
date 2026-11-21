
#include "AVL_LL.h"
#include <iostream>
#include <algorithm>

using namespace std;

VTree::VTree()
{
    root=nullptr;
    size=0;
    balance=0;
}

VNode*VTree::createVNode(int data)
{
    VNode*node=new VNode;

    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    node->height=1;

    return node;
}

int VTree::getheight(VNode*node)
{
    if (node==nullptr)
    {
        return 0;
    }
    return node->height;
}

VNode*VTree::rightRotate(VNode*y)
{
    VNode*x=y->left;
    VNode*T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=1+max(getheight(y->left),getheight(y->right));
    x->height=1+max(getheight(x->left),getheight(x->right));

    return x;
}

VNode*VTree::leftRotate(VNode*x)
{
    VNode*y=x->right;
    VNode*T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=1+max(getheight(x->left),getheight(x->right));
    y->height=1+max(getheight(y->left),getheight(y->right));

    return y;
}

VNode*VTree::insert_h(VNode*node,int data)
{
    if (node==nullptr)
    {
        size++;
        return createVNode(data);
    }

    if (data<node->data)
    {
        node->left=insert_h(node->left,data);
    }
    else if (data>node->data)
    {
        node->right=insert_h(node->right,data);
    }
    else
    {
        return node;
    }

    node->height=1+max(getheight(node->left),getheight(node->right));

    balance=getheight(node->left)-getheight(node->right);

    if (balance>1 && data<node->left->data)
    {
        return rightRotate(node);
    }

    if (balance<-1 && data>node->right->data)
    {
        return leftRotate(node);
    }

    if (balance>1 && data>node->left->data)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance<-1 && data<node->right->data)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void VTree::insertV(int data)
{
    root=insert_h(root,data);
}

void VTree::createVTree(int*arr,int k)
{
    if (root!=nullptr)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        VNode*current=stk.top();
        stk.pop();

        if (current->left!=nullptr)
        {
            stk.push(current->left);
        }

        if (current->right!=nullptr)
        {
            stk.push(current->right);
        }

        delete current;
    }

    root=nullptr;
    size=0;
    balance=0;

    if (arr==nullptr || k<=0)
    {
        return;
    }

    for (int i=0;i<k;i++)
    {
        insertV(arr[i]);
    }
}

VNode*VTree::predessor(VNode*node)
{
    if (node==nullptr)
    {
        return nullptr;
    }

    while (node->right!=nullptr)
    {
        node=node->right;
    }

    return node;
}

VNode*VTree::delete_h(VNode*node,int key)
{
    if (node==nullptr)
    {
        return nullptr;
    }

    if (key<node->data)
    {
        node->left=delete_h(node->left,key);
    }
    else if (key>node->data)
    {
        node->right=delete_h(node->right,key);
    }
    else
    {
        if (node->left==nullptr || node->right==nullptr)
        {
            VNode*temp=(node->left!=nullptr)?node->left:node->right;

            delete node;
            size--;

            return temp;
        }

        VNode*temp=predessor(node->left);

        node->data=temp->data;
        node->left=delete_h(node->left,temp->data);
    }

    node->height=1+max(getheight(node->left),getheight(node->right));

    balance=getheight(node->left)-getheight(node->right);

    if (balance>1 && getheight(node->left->left)>=getheight(node->left->right))
    {
        return rightRotate(node);
    }

    if (balance>1 && getheight(node->left->left)<getheight(node->left->right))
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance<-1 && getheight(node->right->right)>=getheight(node->right->left))
    {
        return leftRotate(node);
    }

    if (balance<-1 && getheight(node->right->right)<getheight(node->right->left))
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void VTree::deleteV(int key)
{
    root=delete_h(root,key);
}

void VTree::search(int key)
{
    VNode*current=root;

    while (current!=nullptr)
    {
        if (key==current->data)
        {
            cout<<key<<" Found"<<endl;
            return;
        }

        if (key<current->data)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }

    cout<<key<<" Not Found"<<endl;
}

void VTree::inorder(VNode*node)
{
    if (node==nullptr)
    {
        return;
    }

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void VTree::display()
{
    if (isEmpty())
    {
        cout<<"Tree is Empty"<<endl;
        return;
    }

    inorder(root);
    cout<<endl;
}

bool VTree::isEmpty()
{
    return root==nullptr;
}
