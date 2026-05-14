#include<bits/stdc++.h>
using namespace std;


// We want to find the topmost parent of a node
int findParent(vector<int> &parent, int node){
    
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]); 
}


void unionByRank(int u, int v, 
                 vector<int> &parent, 
                 vector<int> &rank){

    if(rank[u] < rank[v]){
        parent[u] = v;
    }

    else if(rank[u] > rank[v]){
        parent[v] = u;
    }

    else{
        parent[u] = v;
        rank[v]++;
    }
}


// Custom comparator
bool comparator(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}


int minimumSpanningTree(vector<vector<int>>& edges, int n){
    
    sort(edges.begin(), edges.end(), comparator);
    
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    int mstWeight = 0;

    for(int i = 0; i < edges.size(); i++){

        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int weight = edges[i][2];

        if(u != v){

            mstWeight += weight;

            unionByRank(u, v, parent, rank);
        }
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

    int mstWeight = minimumSpanningTree(edges, V);

    cout << "\nWeight of Minimum Spanning Tree: "
         << mstWeight << endl;

    return 0;
}