#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> &adj, 
         unordered_map<int, bool> &visited, 
         vector<int> &ans){  
    
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(int i = 0; i < adj[front].size(); i++){
            if(!visited[adj[front][i]]){
                q.push(adj[front][i]);
                visited[adj[front][i]] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    vector<int> ans;
    unordered_map<int, bool> visited;

    // Handles disconnected graph
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bfs(i, adj, visited, ans);
        }
    }

    return ans;
}


int main(){

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < E; i++){

        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result = bfsTraversal(V, adj);

    cout << "\nBFS Traversal: ";

    for(auto node : result){
        cout << node << " ";
    }

    cout << endl;

    return 0;
}