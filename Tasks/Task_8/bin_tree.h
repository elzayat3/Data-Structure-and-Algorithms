
#ifndef BIN_TREE
#define BIN_TREE

class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    char data;
};

class BinTree
{
public:
    BinTree();
    ~BinTree();

    int countNodes();
    int countLeafNodes();

    void printBFS();
    void printDFSPreorder();
    void printDFSInorder();
    void printDFSPostorder();

private:
    TreeNode* root;

    int Count_Nodes(TreeNode* node);
    int Count_Leaves(TreeNode* node);

    void Delete_Tree(TreeNode* node);

    void Preorder(TreeNode* node);
    void Inorder(TreeNode* node);
    void Postorder(TreeNode* node);

    BinTree(const BinTree&) = delete;
    BinTree& operator=(const BinTree&) = delete;
};

#endif /* BIN_TREE */
