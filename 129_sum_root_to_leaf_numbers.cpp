#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity : O(N)
// Space Complexity : O(N)
int recursiveTraversal(TreeNode *root, int path)
{
    if (root == NULL)
    {
        return 0;
    }

    path = path * 10 + root->val;

    if (!(root->left) && !(root->right))
    {
        return path;
    }

    return recursiveTraversal(root->left, path) + recursiveTraversal(root->right, path);
}

int sumNumbers(TreeNode *root)
{
    return recursiveTraversal(root, 0);
}