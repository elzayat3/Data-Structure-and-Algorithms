
#include "bin_tree.h"
#include <iostream>


BinTree::BinTree()
{
    root=nullptr;
}



BinTree::~BinTree()
{
    Delete_Tree(root);
    root=nullptr;
}

int BinTree::Count_Nodes(TreeNode* node)
{
    if(node==nullptr)
    {
        return 0;
    }

    return 1+Count_Nodes(node->left)+Count_Nodes(node->right);
}


int BinTree::Count_Leaves(TreeNode*node)
{
    if(node==nullptr)
    {
        return 0;
    }

    if(node->left==nullptr&&node->right==nullptr)
    {
        return 1;
    }

    return Count_Leaves(node->left)+Count_Leaves(node->right);
}


void BinTree::Delete_Tree(TreeNode*node)
{
    if(node==nullptr)
    {
        return;
    }

    Delete_Tree(node->left);
    Delete_Tree(node->right);

    delete node;
}


void BinTree::Preorder(TreeNode*node)
{
    if(node==nullptr)
    {
        return;
    }

    std::cout<<node->data<<" ";

    Preorder(node->left);
    Preorder(node->right);
}


void BinTree::Inorder(TreeNode* node)
{
    if (node==nullptr)
    {
        return;
    }

    Inorder(node->left);

    std::cout<<node->data<<" ";

    Inorder(node->right);
}


void BinTree::Postorder(TreeNode* node)
{
    if (node==nullptr)
    {
        return;
    }

    Postorder(node->left);
    Postorder(node->right);

    std::cout<<node->data<<" ";
}


int BinTree::countNodes()
{
    return Count_Nodes(root);
}


int BinTree::countLeafNodes()
{
    return Count_Leaves(root);
}


void BinTree::printBFS()
{
    if(root==nullptr)
    {
        std::cout<<"Tree is Empty"<<std::endl;
        return;
    }

    int n=countNodes();

    TreeNode**queue=new TreeNode*[n];

    int front=0;
    int rear=0;

    queue[rear++]=root;

    while(front<rear)
    {
        TreeNode*temp=queue[front++];

        std::cout<<temp->data<<" ";

        if(temp->left!=nullptr)
        {
            queue[rear++]=temp->left;
        }

        if(temp->right!=nullptr)
        {
            queue[rear++]=temp->right;
        }
    }

    delete[] queue;

    std::cout<<std::endl;
}


void BinTree::printDFSPreorder()
{
    if (root==nullptr)
    {
        std::cout<<"Tree is Empty"<<std::endl;
        return;
    }

    Preorder(root);
    std::cout<<std::endl;
}


void BinTree::printDFSInorder()
{
    if (root==nullptr)
    {
        std::cout<<"Tree is Empty"<<std::endl;
        return;
    }

    Inorder(root);
    std::cout<<std::endl;
}


void BinTree::printDFSPostorder()
{
    if (root==nullptr)
    {
        std::cout<<"Tree is Empty"<<std::endl;
        return;
    }

    Postorder(root);
    std::cout<<std::endl;
}
