#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, 
         unordered_map<int, bool> &visited, 
         vector<int> &component){
    
    component.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for(int i = 0; i < E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
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

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    cout << "\nDFS Traversal:\n";

    for(int i = 0; i < result.size(); i++){

        cout << "Component " << i + 1 << ": ";

        for(auto node : result[i]){
            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}