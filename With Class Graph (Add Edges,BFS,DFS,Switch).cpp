#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <list>
using namespace std;



class graph
{
public:
    // Cant use a vector<vector<int>> here because cant inatilize a 2D vector without specifying and its not possibe to
    // send n in graph

    // if i want a in assending order then need to use set
    // unordered map is better for fast access

    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void bfs(int node, unordered_map<int, bool> &visited, vector<int> &ans)
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
    void dfs(int node, unordered_map<int, bool> &visited2, vector<int> &ans2)
    {
        visited2[node] = true;
        ans2.push_back(node);
        for (auto j : adj[node])
        {
            if (!visited2[j])
            {
                dfs(j, visited2, ans2);
            }
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  
    int n, m;
    cout << "Enter No. of edges and vertices" << endl;
    cin >> n >> m;

    cout<<"If the graph is undirected enter 0 else enter 1 "<<endl;
    int direction;
    cin>>direction;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v, direction);
    }

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
                g.bfs(i, visited, ans);
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
                g.dfs(i, visited, ans);
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
