#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &cyclic_ndes, int node)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(graph, visited, dfsVisited, cyclic_ndes, neighbour))
            {
                return cyclic_ndes[node] = true;
            }
        }
        else if (dfsVisited[neighbour])
        {
            return cyclic_ndes[node] = true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<bool> visited(v, false), dfsVisited(v, false), cyclic_nodes(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, dfsVisited, cyclic_nodes, i);
        }
    }

    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (!cyclic_nodes[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}