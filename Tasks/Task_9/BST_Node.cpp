
#include "BST_Node.h"
#include <iostream>
#include <queue>

using namespace std;



TreeNode::TreeNode(int d):left(nullptr),right(nullptr),data(d){}

TreeNode::TreeNode():left(nullptr),right(nullptr),data(0){}




BSTree::BSTree():root(nullptr){}

BSTree::~BSTree() 
{
    clear(root);
}

void BSTree::clear(TreeNode*node) 
{
    if(node==nullptr)
    {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}




void BSTree::insertNode(int data) 
{
    TreeNode*newNode=new TreeNode(data);

    if(root==nullptr) 
    {
        root=newNode;
        return;
    }

    TreeNode*current=root;
    TreeNode*parent=nullptr;

    while(current!=nullptr) 
    {
        parent=current;

        if(data<current->data)
        {
            current=current->left;
        }
        else if(data>current->data)
        {
            current=current->right;
        }  
        else 
        {
            delete newNode;
            return;
        }
    }

    if(data<parent->data)
    {
        parent->left=newNode;
    }    
    else
    {
        parent->right=newNode;
    }
        
}


TreeNode*BSTree::remove(TreeNode*node,int key) 
{
    if(node==nullptr)
    {
        return nullptr;
    }
        

    if(key<node->data) 
    {
        node->left=remove(node->left,key);
    }
    else if(key>node->data) 
    {
        node->right=remove(node->right,key);
    }
    else 
    {
        
        if(node->left==nullptr) 
        {
            TreeNode*temp=node->right;
            delete node;
            return temp;
        }

        if(node->right==nullptr) 
        {
            TreeNode*temp=node->left;
            delete node;
            return temp;
        }

        TreeNode*temp=node->right;

        while(temp->left!=nullptr)
        {
            temp = temp->left;
        }
            

        node->data=temp->data;
        node->right=remove(node->right,temp->data);
    }

    return node;
}

void BSTree::deleteNode(int key) 
{
    root=remove(root, key);
}


int BSTree::count(TreeNode*node) 
{
    if(node==nullptr)
    {
        return 0;
    }
       

    return 1+count(node->left)+count(node->right);
}

int BSTree::countNodes() 
{
    return count(root);
}




int BSTree::countLeaves(TreeNode*node) 
{
    if(node==nullptr)
    {
        return 0;
    }
        

    if(node->left==nullptr && node->right==nullptr)
    {
        return 1;
    }
        

    return countLeaves(node->left)+countLeaves(node->right);
}

int BSTree::countLeafNodes() 
{
    return countLeaves(root);
}


void BSTree::printBFS() {
    if (root==nullptr)
    {
        return;
    }
        

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) 
    {
        TreeNode*current=q.front();
        q.pop();

        cout<<current->data<<" ";

        if(current->left!=nullptr)
        {
            q.push(current->left);
        }
            

        if(current->right!=nullptr)
        {
            q.push(current->right);
        }    
    }
    cout<<endl;
}


void BSTree::preorder(TreeNode*node) 
{
    if (node==nullptr)
    {
        return;
    }
    
    cout<<node->data<< " ";
    preorder(node->left);
    preorder(node->right);
}

void BSTree::printDFSPreorder() 
{
    preorder(root);
    cout<<endl;
}


void BSTree::inorder(TreeNode* node) 
{
    if(node==nullptr)
    {
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void BSTree::printDFSInorder() 
{
    inorder(root);
    cout<<endl;
}




void BSTree::postorder(TreeNode* node) 
{
    if(node==nullptr)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

void BSTree::printDFSPostorder() 
{
    postorder(root);
    cout<<endl;
}
