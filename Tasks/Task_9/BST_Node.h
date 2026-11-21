
#ifndef BSTREE_H
#define BSTREE_H

class TreeNode {
public:
    TreeNode(int d);
    TreeNode();

    TreeNode*left;
    TreeNode*right;
    int data;
};

class BSTree {
public:
    BSTree();
    ~BSTree();

    void insertNode(int data);
    void deleteNode(int key);

    int countNodes();
    int countLeafNodes();

    void printBFS();
    void printDFSPreorder();
    void printDFSInorder();
    void printDFSPostorder();

private:
    TreeNode*root;

    void clear(TreeNode*node);

    int count(TreeNode*node);
    int countLeaves(TreeNode*node);

    void preorder(TreeNode*node);
    void inorder(TreeNode*node);
    void postorder(TreeNode*node);

    TreeNode*remove(TreeNode*node,int key);
};

#endif
