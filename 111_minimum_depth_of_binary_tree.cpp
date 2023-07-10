#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int minDepth(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int depth = 1;
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            struct node *n = q.front();
            q.pop();
            if (n->left == NULL && n->right == NULL)
            {
                return depth;
            }
            if (n->left != NULL)
            {
                q.push(n->left);
            }
            if (n->right != NULL)
            {
                q.push(n->right);
            }
        }
        depth++;
    }
    return depth;
}

int main()
{
    struct node *root = createNode(1);
    struct node *a = createNode(2);
    struct node *b = createNode(3);
    struct node *c = createNode(4);
    struct node *d = createNode(5);
    struct node *e = createNode(6);
    struct node *f = createNode(7);
    struct node *g = createNode(8);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;
    b->right = f;

    e->left = g;

    cout << "Min depth of the binary tree is : " << minDepth(root) << endl;
}