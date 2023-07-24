#include <iostream>
#include <queue>
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

int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty())
    {
        int n = q.size();
        int mmin = q.front().second;
        int first, last;

        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front().first;
            int idx = q.front().second - mmin;
            q.pop();

            if (i == 0)
            {
                first = idx;
            }
            if (i == n - 1)
            {
                last = idx;
            }

            if (curr->left)
            {
                q.push({curr->left, (long long)2 * idx + 1});
            }
            if (curr->right)
            {
                q.push({curr->right, (long long)2 * idx + 2});
            }
        }
        maxWidth = max(maxWidth, last - first + 1);
    }
    return maxWidth;
}