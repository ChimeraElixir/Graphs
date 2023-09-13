#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <list>
using namespace std;

void addEdges(int u, int v, bool direction,vector<vector<int>> &adj)
{
    adj[u].push_back(v);

    if (direction == 0)
    {
        adj[v].push_back(u);
    }
}
void bfs(int node, unordered_map<int, bool> &visited, vector<int> &ans,vector<vector<int>> &adj)
{
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto j : adj[front])
        {
            if (!visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }
    }
}
void dfs(int node, unordered_map<int, bool> &visited, vector<int> &ans,vector<vector<int>> &adj)
{
    visited[node] = true;
    ans.push_back(node);
    for (auto j : adj[node])
    {
        if (!visited[j])
        {
            dfs(j, visited, ans,adj);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cout << "Enter No. of edges and vertices" << endl;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);

    cout << "If the graph is undirected enter 0 else enter 1 " << endl;
    int direction;
    cin >> direction;

    int choice;
    cout << "1.BFS /n  2.DFS " << endl;

    cin >> choice;
    vector<int> ans;
    unordered_map<int, bool> visited;

    switch (choice)
    {
    case 1:
        // Cant initialize a data structre here its give
        // DfS_transversal.cpp:88:21: note: jump bypasses variable initialization
        //    vector<int> ans;
        //                     ^
        // DfS_transversal.cpp:103:5: error: cannot jump from switch statement to this case label
        //     case 2:
        //     ^
        // DfS_transversal.cpp:89:34: note: jump bypasses variable initialization
        //         unordered_map<int, bool> visited;
        //                                  ^
        // DfS_transversal.cpp:88:21: note: jump bypasses variable initialization

        //     thsi error
        // vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited, ans,adj);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        break;
    case 2:

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, ans,adj);
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        break;

    default:
        cout << "Select a valid choice" << endl;
        return 0;
    }
}
