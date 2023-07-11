#include <iostream>
#include <queue>
#include <unordered_map>
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

void markParents(struct node *root, unordered_map<struct node *, struct node *> &parent)
{
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(struct node *root, struct node *target, int k)
{
    unordered_map<struct node *, struct node *> parent;
    markParents(root, parent);

    unordered_map<struct node *, bool> visited;
    queue<struct node *> q;
    q.push(target);
    visited[target] = true;
    int current_level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (current_level++ == k)
        {
            break;
        }
        for (int i = 0; i < size; i++)
        {
            struct node *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }

            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (parent[curr] && !visited[parent[curr]])
            {
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
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

    struct node *target = c;
    int k = 2;
    vector<int> res = distanceK(root, target, k);
    for (int i : res)
    {
        cout << i << ", ";
    }
    cout << endl;
}