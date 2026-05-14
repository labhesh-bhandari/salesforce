#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges) {

    map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> mst(V, false);
    
    key[0] = 0;
    
    for(int i = 0; i < V; i++){

        int mini = INT_MAX;
        int u;

        // Finding minimum key vertex
        for(int j = 0; j < V; j++){

            if(mst[j] == false && key[j] < mini){

                mini = key[j];
                u = j;
            }
        }
        
        mst[u] = true;
        
        for(auto neighbour : adj[u]){

            int v = neighbour.first;
            int weight = neighbour.second;

            if(mst[v] == false && weight < key[v]){

                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    int mstWeight = 0;

    for(int i = 0; i < V; i++){
        mstWeight += key[i];
    }
    
    return mstWeight;
}



int main(){

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++){

        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }

    int mstWeight = spanningTree(V, edges);

    cout << "\nWeight of Minimum Spanning Tree: "
         << mstWeight << endl;

    return 0;
}