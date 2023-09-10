// https://www.codingninjas.com/studio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //for(int i=0;i<adj.size();i++){
      // cout<<i<<' ';
        //for(int j=0;j<adj[i].size();j++){
          //  cout<<adj[i][j]<<' ';

        //}
        //cout<<endl;
    //}
    return adj;
    
}
